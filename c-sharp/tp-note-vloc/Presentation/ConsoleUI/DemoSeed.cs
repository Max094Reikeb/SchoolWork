using VLoc.Domain.Entities;

namespace VLoc.Presentation.ConsoleUI;

public static class DemoSeed
{
    public static void Seed(
        Infrastructure.Repositories.InMemoryCustomerRepository customers,
        Infrastructure.Repositories.InMemoryVehicleRepository vehicles)
    {
        customers.Add(new StandardCustomer { FullName = "Alice Martin" });
        customers.Add(new PremiumCustomer { FullName = "Bob Durand" });

        var today = DateOnly.FromDateTime(DateTime.Today);

        vehicles.Add(new Vehicle("Peugeot 208", 45m, mileageKm: 52_000, lastMaintenanceDate: today.AddMonths(-2), mileageAtLastMaintenance: 45_000));
        vehicles.Add(new Vehicle("Renault Clio", 40m, mileageKm: 10_000, lastMaintenanceDate: today.AddMonths(-7), mileageAtLastMaintenance: 10_000)); // force maintenance (6 mois)
        vehicles.Add(new Vehicle("Tesla Model 3", 120m, mileageKm: 25_000, lastMaintenanceDate: today.AddMonths(-1), mileageAtLastMaintenance: 20_000));
    }
}
