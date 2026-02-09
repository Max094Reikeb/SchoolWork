using VLoc.Domain.Entities;
using VLoc.Domain.Enums;

namespace VLoc.Application.Services;

public class RentalService
{
    private readonly PricingService _pricing;

    public RentalService(PricingService pricing) => _pricing = pricing;

    public Rental CreateRental(Customer customer, Vehicle vehicle, DateOnly start, DateOnly end, DateOnly today)
    {
        if (end < start) throw new ArgumentException("Dates invalides.");

        int days = (end.DayNumber - start.DayNumber) + 1;
        if (days > 30) throw new InvalidOperationException("Durée max: 30 jours.");

        if (vehicle.Status != VehicleStatus.Available)
            throw new InvalidOperationException("Véhicule non disponible.");

        if (vehicle.NeedsMaintenance(today))
            throw new InvalidOperationException("Véhicule doit passer en maintenance (10 000 km ou 6 mois).");

        if (customer.ActiveRentalsCount(today) >= 3)
            throw new InvalidOperationException("Max 3 locations simultanées par client.");

        var rental = new Rental(customer, vehicle, start, end);
        customer.Rentals.Add(rental);
        return rental;
    }

    public void PayDepositAndStart(Rental rental)
    {
        // Dépôt obligatoire avant démarrage
        rental.PayDeposit();

        rental.Vehicle.SetStatus(VehicleStatus.Rented);
        rental.Activate();
    }

    public Domain.ValueObjects.Invoice CloseRental(Rental rental, int returnMileageKm, DateOnly returnDate)
    {
        // Retour véhicule + inspection obligatoire
        rental.Vehicle.RegisterReturn(returnMileageKm);
        rental.CloseAfterInspection();

        // Maintenance si nécessaire après retour
        if (rental.Vehicle.NeedsMaintenance(returnDate))
            rental.Vehicle.MarkMaintenance(returnDate);

        return _pricing.BuildInvoice(rental);
    }
}
