using VLoc.Domain.Enums;

namespace VLoc.Domain.Entities;

public class Vehicle
{
    public Guid Id { get; } = Guid.NewGuid();
    public string Model { get; set; } = "";
    public decimal BaseDailyPrice { get; set; }

    public VehicleStatus Status { get; private set; } = VehicleStatus.Available;

    public int MileageKm { get; private set; }
    public DateOnly LastMaintenanceDate { get; private set; }
    public int MileageAtLastMaintenance { get; private set; }

    public Vehicle(string model, decimal baseDailyPrice, int mileageKm, DateOnly lastMaintenanceDate, int mileageAtLastMaintenance)
    {
        Model = model;
        BaseDailyPrice = baseDailyPrice;
        MileageKm = mileageKm;
        LastMaintenanceDate = lastMaintenanceDate;
        MileageAtLastMaintenance = mileageAtLastMaintenance;
    }

    public void SetStatus(VehicleStatus status) => Status = status;

    public bool NeedsMaintenance(DateOnly today)
    {
        bool dueMileage = (MileageKm - MileageAtLastMaintenance) >= 10_000;
        bool dueTime = LastMaintenanceDate.AddMonths(6) <= today;
        return dueMileage || dueTime;
    }

    public void RegisterReturn(int newMileageKm)
    {
        if (newMileageKm < MileageKm) throw new InvalidOperationException("Kilométrage invalide.");
        MileageKm = newMileageKm;
        Status = VehicleStatus.Available;
    }

    public void MarkMaintenance(DateOnly date)
    {
        Status = VehicleStatus.InMaintenance;
        LastMaintenanceDate = date;
        MileageAtLastMaintenance = MileageKm;
    }

    public void PerformMaintenance(DateOnly date, int mileageKmAtMaintenance)
    {
        if (mileageKmAtMaintenance < MileageKm)
            throw new InvalidOperationException("Kilométrage maintenance invalide.");

        MileageKm = mileageKmAtMaintenance;

        // On considère que la maintenance est faite -> remise à zéro des seuils
        LastMaintenanceDate = date;
        MileageAtLastMaintenance = mileageKmAtMaintenance;

        // On s'assure que le véhicule soit disponible (pas loué)
        if (Status != VehicleStatus.Rented)
            Status = VehicleStatus.Available;
    }
}
