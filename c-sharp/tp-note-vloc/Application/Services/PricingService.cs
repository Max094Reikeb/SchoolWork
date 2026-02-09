using VLoc.Domain.Entities;
using VLoc.Domain.Enums;
using VLoc.Domain.ValueObjects;

namespace VLoc.Application.Services;

public class PricingService
{
    public Invoice BuildInvoice(Rental rental)
    {
        var invoice = new Invoice
        {
            RentalId = rental.Id,
            CustomerId = rental.Customer.Id
        };

        int days = rental.DurationDays;

        decimal vehicleCost = rental.Vehicle.BaseDailyPrice * days;
        invoice.Lines.Add(new InvoiceLine($"Véhicule ({days} jours)", vehicleCost));

        foreach (var opt in rental.Options)
        {
            decimal amount = opt.PricingType == OptionPricingType.PerDay
                ? opt.Price * days
                : opt.Price;

            invoice.Lines.Add(new InvoiceLine($"Option: {opt.Name}", amount));
        }

        decimal subtotal = invoice.Total;

        // Remise longue durée: 15% pour 7 jours ou plus
        if (days >= 7)
        {
            decimal discount = subtotal * 0.15m;
            invoice.Lines.Add(new InvoiceLine("Remise longue durée (15%)", -discount));
            subtotal -= discount;
        }

        // Promotion (appliquée après la remise)
        if (rental.Promotion is not null)
        {
            decimal afterPromo = rental.Promotion.Apply(
                subtotal, rental.StartDate, rental.EndDate, rental.Customer, rental.Vehicle);

            decimal promoDelta = afterPromo - subtotal; // négatif si réduction
            if (promoDelta != 0)
                invoice.Lines.Add(new InvoiceLine($"Promotion {rental.Promotion.Code}", promoDelta));
        }

        return invoice;
    }
}
