using VLoc.Domain.Entities;

namespace VLoc.Application.Services;

public class MaintenanceService
{
    public void PerformMaintenance(Vehicle vehicle, DateOnly date, int mileageKm)
    {
        vehicle.PerformMaintenance(date, mileageKm);
    }
}
