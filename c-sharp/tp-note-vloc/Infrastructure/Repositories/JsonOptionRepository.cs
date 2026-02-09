using VLoc.Domain.ValueObjects;
using VLoc.Infrastructure.Dtos;
using VLoc.Infrastructure.Persistence;

namespace VLoc.Infrastructure.Repositories;

public class JsonOptionRepository : JsonRepository<OptionDto>, IOptionRepository
{
    public JsonOptionRepository(JsonFileStore store, string pathFile) : base(store, pathFile) { }

    public IReadOnlyList<(Guid Id, RentalOption Option)> GetAll()
        => Items.Select(x => (x.Id, new RentalOption(x.Name, x.PricingType, x.Price))).ToList();

    public (Guid Id, RentalOption Option)? Get(Guid id)
    {
        var dto = Items.FirstOrDefault(x => x.Id == id);
        if (dto is null) return null;
        return (dto.Id, new RentalOption(dto.Name, dto.PricingType, dto.Price));
    }

    public void Add(Guid id, RentalOption option)
    {
        Items.Add(new OptionDto
        {
            Id = id,
            Name = option.Name,
            PricingType = option.PricingType,
            Price = option.Price
        });
        Persist();
    }

    public void Save() => Persist();
}
