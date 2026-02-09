using VLoc.Domain.Entities;

namespace VLoc.Infrastructure.Repositories;

public interface IVehicleRepository
{
    IReadOnlyList<Vehicle> GetAll();
    Vehicle? Get(Guid id);
    void Add(Vehicle vehicle);
    void Save();
    void Update(Vehicle vehicle);
}
