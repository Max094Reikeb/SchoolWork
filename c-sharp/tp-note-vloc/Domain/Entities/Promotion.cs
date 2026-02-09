using VLoc.Domain.Entities;

namespace VLoc.Domain.Entities;

public abstract class Promotion
{
    public string Code { get; init; } = "";
    public bool IsActive { get; init; } = true;

    // Promotion applies to a customer's vehicle in a limited timeframe
    public abstract decimal Apply(
        decimal subtotal,
        DateOnly start,
        DateOnly end,
        Customer customer,
        Vehicle vehicle);
}
