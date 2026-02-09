namespace VLoc.Domain.ValueObjects;

public record InvoiceLine(string Label, decimal Amount);

public class Invoice
{
    public Guid Id { get; } = Guid.NewGuid();
    public Guid RentalId { get; init; }
    public Guid CustomerId { get; init; }
    public DateTime CreatedAtUtc { get; init; } = DateTime.UtcNow;

    public List<InvoiceLine> Lines { get; } = new();
    public decimal Total => Lines.Sum(l => l.Amount);
}
