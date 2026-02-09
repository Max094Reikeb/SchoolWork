using VLoc.Domain.Entities;

namespace VLoc.Domain.Entities;

public sealed class PercentagePromotion : Promotion
{
    public decimal Percent { get; init; }

    public override decimal Apply(decimal subtotal, DateOnly start, DateOnly end, Customer customer, Vehicle vehicle)
        => IsActive ? subtotal * (1 - Percent) : subtotal;
}
