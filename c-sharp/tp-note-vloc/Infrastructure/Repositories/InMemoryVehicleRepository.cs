using VLoc.Domain.Entities;

namespace VLoc.Infrastructure.Repositories;

public class InMemoryVehicleRepository : IRepository<Vehicle>
{
    private readonly List<Vehicle> _items = new();

    public Vehicle? Get(Guid id) => _items.FirstOrDefault(x => x.Id == id);
    public IReadOnlyList<Vehicle> GetAll() => _items;

    public void Add(Vehicle item) => _items.Add(item);
}
