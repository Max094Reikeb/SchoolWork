using VLoc.Domain.Enums;

namespace VLoc.Domain.ValueObjects;

public record RentalOption(string Name, OptionPricingType PricingType, decimal Price);
