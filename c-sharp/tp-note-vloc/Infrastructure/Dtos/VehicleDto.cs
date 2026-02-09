using VLoc.Domain.Enums;

namespace VLoc.Infrastructure.Dtos;

public class VehicleDto
{
    public Guid Id { get; set; }
    public string Model { get; set; } = "";
    public decimal BaseDailyPrice { get; set; }

    public VehicleStatus Status { get; set; } = VehicleStatus.Available;

    public int MileageKm { get; set; }
    public DateOnly LastMaintenanceDate { get; set; }
    public int MileageAtLastMaintenance { get; set; }
}
