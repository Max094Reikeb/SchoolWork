namespace VLoc.Infrastructure.Dtos;

public class InvoiceLineDto
{
    public string Label { get; set; } = "";
    public decimal Amount { get; set; }
}

public class InvoiceDto
{
    public Guid Id { get; set; }
    public Guid RentalId { get; set; }
    public Guid CustomerId { get; set; }
    public DateTime CreatedAtUtc { get; set; }
    public List<InvoiceLineDto> Lines { get; set; } = new();
    public decimal Total { get; set; }
}
