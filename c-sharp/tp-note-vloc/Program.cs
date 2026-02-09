using VLoc.Application.Services;
using VLoc.Infrastructure.Persistence;
using VLoc.Infrastructure.Repositories;
using VLoc.Presentation.ConsoleUI;

var pricing = new PricingService();
var rentalService = new RentalService(pricing);
var maintenanceService = new MaintenanceService();

var store = new JsonFileStore();

var customers = new JsonCustomerRepository(store, "data/customers.json");
var vehicles = new JsonVehicleRepository(store, "data/vehicles.json");
var options = new JsonOptionRepository(store, "data/options.json");
var invoices = new JsonInvoiceRepository(store, "logs/invoices.json");

var menu = new Menu(customers, vehicles, options, invoices, rentalService, pricing, maintenanceService);
menu.Run();
