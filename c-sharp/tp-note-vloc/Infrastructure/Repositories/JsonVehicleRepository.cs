using VLoc.Domain.Entities;
using VLoc.Infrastructure.Dtos;
using VLoc.Infrastructure.Persistence;

namespace VLoc.Infrastructure.Repositories;

public class JsonVehicleRepository : JsonRepository<VehicleDto>, IVehicleRepository
{
    public JsonVehicleRepository(JsonFileStore store, string pathFile) : base(store, pathFile) { }

    public IReadOnlyList<Vehicle> GetAll() => Items.Select(ToDomain).ToList();
    public Vehicle? Get(Guid id) => Items.Where(x => x.Id == id).Select(ToDomain).FirstOrDefault();

    public void Add(Vehicle vehicle)
    {
        Items.Add(ToDto(vehicle));
        Persist();
    }

    public void Update(Vehicle vehicle)
    {
        var idx = Items.FindIndex(v => v.Id == vehicle.Id);
        if (idx < 0)
            throw new InvalidOperationException("Véhicule introuvable (update).");

        Items[idx] = ToDto(vehicle);
        Persist();
    }

    public void Save() => Persist();

    private static Vehicle ToDomain(VehicleDto dto)
    {
        var v = new Vehicle(
            dto.Model,
            dto.BaseDailyPrice,
            dto.MileageKm,
            dto.LastMaintenanceDate,
            dto.MileageAtLastMaintenance
        );

        v.SetStatus(dto.Status);
        return v;
    }

    private static VehicleDto ToDto(Vehicle v) => new()
    {
        Id = v.Id,
        Model = v.Model,
        BaseDailyPrice = v.BaseDailyPrice,
        Status = v.Status,
        MileageKm = v.MileageKm,
        LastMaintenanceDate = v.LastMaintenanceDate,
        MileageAtLastMaintenance = v.MileageAtLastMaintenance
    };
}
