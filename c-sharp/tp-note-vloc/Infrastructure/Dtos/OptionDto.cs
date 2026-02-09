using VLoc.Domain.Enums;

namespace VLoc.Infrastructure.Dtos;

public class OptionDto
{
    public Guid Id { get; set; }
    public string Name { get; set; } = "";
    public OptionPricingType PricingType { get; set; }
    public decimal Price { get; set; }
}
