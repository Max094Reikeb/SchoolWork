using VLoc.Application.Services;
using VLoc.Domain.Entities;
using VLoc.Domain.Enums;
using VLoc.Domain.ValueObjects;
using VLoc.Infrastructure.Repositories;

namespace VLoc.Presentation.ConsoleUI;

public class Menu
{
    private readonly ICustomerRepository _customers;
    private readonly IVehicleRepository _vehicles;
    private readonly IOptionRepository _options;
    private readonly IInvoiceRepository _invoices;
    private readonly RentalService _rentalService;
    private readonly PricingService _pricingService;
    private readonly MaintenanceService _maintenanceService;

    public Menu(
        ICustomerRepository customers,
        IVehicleRepository vehicles,
        IOptionRepository options,
        IInvoiceRepository invoices,
        RentalService rentalService,
        PricingService pricingService,
        MaintenanceService maintenanceService)
    {
        _customers = customers;
        _vehicles = vehicles;
        _options = options;
        _invoices = invoices;
        _rentalService = rentalService;
        _pricingService = pricingService;
        _maintenanceService = maintenanceService;
    }

    public void Run()
    {
        while (true)
        {
            Console.WriteLine("\n=== V-Loc (console) ===");
            Console.WriteLine("1) Lister clients");
            Console.WriteLine("2) Ajouter un client");
            Console.WriteLine("3) Lister véhicules");
            Console.WriteLine("4) Ajouter un véhicule");
            Console.WriteLine("5) Lister options");
            Console.WriteLine("6) Ajouter une option");
            Console.WriteLine("7) Créer location (draft)");
            Console.WriteLine("8) Payer caution + démarrer location");
            Console.WriteLine("9) Clôturer location (retour + inspection / maintenance + facture)");
            Console.WriteLine("10) Historique + factures d'un client");
            Console.WriteLine("11) Faire une maintenance (hors location)");
            Console.WriteLine("0) Quitter");
            Console.Write("Choix: ");

            var choice = Console.ReadLine();
            try
            {
                switch (choice)
                {
                    case "1": ListCustomers(); break;
                    case "2": AddCustomer(); break;
                    case "3": ListVehicles(); break;
                    case "4": AddVehicle(); break;
                    case "5": ListOptions(); break;
                    case "6": AddOption(); break;
                    case "7": CreateRentalDraft(); break;
                    case "8": StartRental(); break;
                    case "9": CloseRental(); break;
                    case "10": ShowCustomerHistory(); break;
                    case "11": DoMaintenance(); break;
                    case "0": return;
                    default: Console.WriteLine("Choix invalide."); break;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Erreur: {ex.Message}");
            }
        }
    }

    private void ListCustomers()
    {
        Console.WriteLine("\n--- Clients ---");
        foreach (var c in _customers.GetAll())
            Console.WriteLine($"{c.Id} | {c.FullName} | {c.Type}");
    }

    private void AddCustomer()
    {
        Console.Write("Nom complet: ");
        var name = Console.ReadLine() ?? "";

        Console.Write("Type (standard/premium): ");
        var type = (Console.ReadLine() ?? "").Trim().ToLowerInvariant();

        Customer c = type == "premium" ? new PremiumCustomer() : new StandardCustomer();
        c.FullName = name;

        _customers.Add(c);
        Console.WriteLine("Client ajouté.");
    }

    private void ListVehicles()
    {
        var today = DateOnly.FromDateTime(DateTime.Today);

        Console.WriteLine("\n--- Véhicules ---");
        foreach (var v in _vehicles.GetAll())
        {
            var maint = v.NeedsMaintenance(today) ? "MAINTENANCE DUE" : "OK";
            Console.WriteLine($"{v.Id} | {v.Model} | {v.BaseDailyPrice}€/j | {v.Status} | km={v.MileageKm} | {maint}");
        }
    }

    private void AddVehicle()
    {
        Console.Write("Modèle: ");
        var model = Console.ReadLine() ?? "";

        Console.Write("Prix journalier (€): ");
        var price = decimal.Parse(Console.ReadLine() ?? "0");

        Console.Write("Kilométrage: ");
        var km = int.Parse(Console.ReadLine() ?? "0");

        var today = DateOnly.FromDateTime(DateTime.Today);

        // on initialise la dernière maintenance à aujourd'hui (ou tu peux demander à l’utilisateur)
        var v = new Vehicle(model, price, km, lastMaintenanceDate: today, mileageAtLastMaintenance: km);

        _vehicles.Add(v);
        Console.WriteLine("Véhicule ajouté.");
    }

    private void ListOptions()
    {
        Console.WriteLine("\n--- Options ---");
        foreach (var (id, opt) in _options.GetAll())
            Console.WriteLine($"{id} | {opt.Name} | {opt.PricingType} | {opt.Price}€");
    }

    private void AddOption()
    {
        Console.Write("Nom option: ");
        var name = Console.ReadLine() ?? "";

        Console.Write("Type (perday/fixed): ");
        var t = (Console.ReadLine() ?? "").Trim().ToLowerInvariant();

        Console.Write("Prix (€): ");
        var price = decimal.Parse(Console.ReadLine() ?? "0");

        var pricingType = t == "fixed" ? OptionPricingType.Fixed : OptionPricingType.PerDay;

        var id = Guid.NewGuid();
        _options.Add(id, new RentalOption(name, pricingType, price));
        Console.WriteLine($"Option ajoutée (Id: {id}).");
    }

    private void CreateRentalDraft()
    {
        var today = DateOnly.FromDateTime(DateTime.Today);

        var customer = PickCustomer();
        var vehicle = PickVehicle();

        Console.Write("Date début (YYYY-MM-DD): ");
        var start = DateOnly.Parse(Console.ReadLine() ?? "");

        Console.Write("Date fin (YYYY-MM-DD): ");
        var end = DateOnly.Parse(Console.ReadLine() ?? "");

        var rental = _rentalService.CreateRental(customer, vehicle, start, end, today);

        Console.WriteLine("\n--- Options disponibles ---");
        var allOptions = _options.GetAll();
        if (allOptions.Count == 0)
        {
            Console.WriteLine("Aucune option disponible. (Ajoute-en via le menu.)");
        }
        else
        {
            foreach (var (id, opt) in allOptions)
                Console.WriteLine($"{id} | {opt.Name} | {opt.PricingType} | {opt.Price}€");

            while (true)
            {
                Console.Write("\nAjouter une option (colle l'Id / Entrée pour terminer): ");
                var raw = (Console.ReadLine() ?? "").Trim();

                if (string.IsNullOrEmpty(raw))
                    break;

                if (!Guid.TryParse(raw, out var optionId))
                {
                    Console.WriteLine("Id invalide (format GUID attendu).");
                    continue;
                }

                var found = _options.Get(optionId);
                if (found is null)
                {
                    Console.WriteLine("Option introuvable.");
                    continue;
                }

                rental.Options.Add(found.Value.Option);
                Console.WriteLine($"Option ajoutée: {found.Value.Option.Name}");
            }
        }

        Console.Write("Promo -10% ? (y/n): ");
        if ((Console.ReadLine() ?? "").Trim().ToLowerInvariant() == "y")
            rental.AttachPromotion(new PercentagePromotion { Code = "PROMO10", Percent = 0.10m });

        var preview = _pricingService.BuildInvoice(rental);
        Console.WriteLine($"Location créée (Draft). Total estimé: {preview.Total}€");
    }

    private void StartRental()
    {
        var rental = PickRental();
        _rentalService.PayDepositAndStart(rental);
        _vehicles.Update(rental.Vehicle);
        _customers.Update(rental.Customer);
        Console.WriteLine("Location démarrée (caution payée).");
    }

    private void CloseRental()
    {
        var rental = PickRental();

        Console.Write("Km au retour: ");
        int km = int.Parse(Console.ReadLine() ?? "0");

        var returnDate = DateOnly.FromDateTime(DateTime.Today);
        var invoice = _rentalService.CloseRental(rental, km, returnDate);
        _invoices.Add(invoice);

        _vehicles.Update(rental.Vehicle);
        _customers.Update(rental.Customer);

        Console.WriteLine("\n--- Facture ---");
        foreach (var line in invoice.Lines)
            Console.WriteLine($"{line.Label}: {line.Amount}€");
        Console.WriteLine($"TOTAL: {invoice.Total}€");
    }

    private void ShowCustomerHistory()
    {
        var customer = PickCustomer();

        Console.WriteLine($"\n--- Historique locations: {customer.FullName} ---");
        foreach (var r in customer.Rentals)
        {
            Console.WriteLine($"{r.Id} | {r.Vehicle.Model} | {r.StartDate} -> {r.EndDate} | {r.Status} | Caution={(r.DepositPaid ? "OK" : "NON")}");
        }

        Console.WriteLine("\n--- Factures ---");
        var customerInvoices = _invoices.GetAll().Where(i => i.CustomerId == customer.Id).ToList();
        if (customerInvoices.Count == 0) Console.WriteLine("Aucune facture.");
        foreach (var i in customerInvoices)
            Console.WriteLine($"{i.Id} | {i.CreatedAtUtc:u} | Total {i.Total}€");
    }

    private void DoMaintenance()
    {
        var vehicle = PickVehicle();

        if (vehicle.Status == VehicleStatus.Rented)
            throw new InvalidOperationException("Impossible: véhicule actuellement en location.");

        Console.WriteLine($"Maintenance due ? {(vehicle.NeedsMaintenance(DateOnly.FromDateTime(DateTime.Today)) ? "OUI" : "NON")}");

        Console.Write("Date maintenance (YYYY-MM-DD) [Entrée = aujourd'hui]: ");
        var dateStr = (Console.ReadLine() ?? "").Trim();
        var date = string.IsNullOrEmpty(dateStr)
            ? DateOnly.FromDateTime(DateTime.Today)
            : DateOnly.Parse(dateStr);

        Console.Write("Kilométrage au moment de la maintenance: ");
        int km = int.Parse(Console.ReadLine() ?? "0");

        _maintenanceService.PerformMaintenance(vehicle, date, km);
        _vehicles.Update(vehicle); // Indispensable pour mettre à jour la base de données

        Console.WriteLine($"Maintenance enregistrée. Statut véhicule: {vehicle.Status}. Dernière maintenance: {vehicle.LastMaintenanceDate}");
    }

    private Customer PickCustomer()
    {
        ListCustomers();
        Console.Write("\nId client: ");
        var id = Guid.Parse(Console.ReadLine() ?? "");
        return _customers.Get(id) ?? throw new InvalidOperationException("Client introuvable.");
    }

    private Vehicle PickVehicle()
    {
        ListVehicles();
        Console.Write("\nId véhicule: ");
        var id = Guid.Parse(Console.ReadLine() ?? "");
        return _vehicles.Get(id) ?? throw new InvalidOperationException("Véhicule introuvable.");
    }

    private Rental PickRental()
    {
        var customer = PickCustomer();

        Console.WriteLine("\nLocations du client:");
        foreach (var r in customer.Rentals)
            Console.WriteLine($"{r.Id} | {r.Vehicle.Model} | {r.StartDate}->{r.EndDate} | {r.Status}");

        Console.Write("\nId location: ");
        var id = Guid.Parse(Console.ReadLine() ?? "");
        return customer.Rentals.FirstOrDefault(r => r.Id == id)
               ?? throw new InvalidOperationException("Location introuvable.");
    }
}
