using VLoc.Domain.Enums;

namespace VLoc.Domain.Entities;

public abstract class Customer
{
    public Guid Id { get; } = Guid.NewGuid();
    public string FullName { get; set; } = "";
    public CustomerType Type { get; protected set; }
    public List<Rental> Rentals { get; } = new();

    // Checks for active rentals
    public int ActiveRentalsCount(DateOnly today)
        => Rentals.Count(r => r.Status == RentalStatus.Active && r.StartDate <= today && r.EndDate >= today);
}

public sealed class StandardCustomer : Customer
{
    public StandardCustomer() => Type = CustomerType.Standard;
}

public sealed class PremiumCustomer : Customer
{
    public PremiumCustomer() => Type = CustomerType.Premium;
}
