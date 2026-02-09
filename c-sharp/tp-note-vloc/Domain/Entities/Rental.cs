using VLoc.Domain.Enums;
using VLoc.Domain.ValueObjects;

namespace VLoc.Domain.Entities;

public class Rental
{
    public Guid Id { get; } = Guid.NewGuid();

    public Customer Customer { get; }
    public Vehicle Vehicle { get; }

    public DateOnly StartDate { get; }
    public DateOnly EndDate { get; }

    public List<RentalOption> Options { get; } = new();
    public Promotion? Promotion { get; private set; }

    public RentalStatus Status { get; private set; } = RentalStatus.Draft;

    public bool DepositPaid { get; private set; }
    public bool ReturnInspected { get; private set; }

    public Rental(Customer customer, Vehicle vehicle, DateOnly start, DateOnly end)
    {
        Customer = customer;
        Vehicle = vehicle;
        StartDate = start;
        EndDate = end;
    }

    public int DurationDays => (EndDate.DayNumber - StartDate.DayNumber) + 1;

    public void AttachPromotion(Promotion promo) => Promotion = promo;

    public void PayDeposit() => DepositPaid = true;

    public void Activate()
    {
        if (!DepositPaid) throw new InvalidOperationException("Dépôt de garantie non payé.");
        Status = RentalStatus.Active;
    }

    public void CloseAfterInspection()
    {
        ReturnInspected = true;
        Status = RentalStatus.Closed;
    }
}
