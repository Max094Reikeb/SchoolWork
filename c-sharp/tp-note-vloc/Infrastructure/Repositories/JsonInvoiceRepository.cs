using VLoc.Domain.ValueObjects;
using VLoc.Infrastructure.Dtos;
using VLoc.Infrastructure.Persistence;

namespace VLoc.Infrastructure.Repositories;

public class JsonInvoiceRepository : JsonRepository<InvoiceDto>, IInvoiceRepository
{
    public JsonInvoiceRepository(JsonFileStore store, string pathFile) : base(store, pathFile) { }

    public IReadOnlyList<Invoice> GetAll() => Items.Select(ToDomain).ToList();

    public void Add(Invoice invoice)
    {
        Items.Add(ToDto(invoice));
        Persist();
    }

    public void Save() => Persist();

    private static Invoice ToDomain(InvoiceDto dto)
    {
        var inv = new Invoice { RentalId = dto.RentalId, CustomerId = dto.CustomerId };
        inv.Lines.AddRange(dto.Lines.Select(l => new InvoiceLine(l.Label, l.Amount)));
        return inv;
    }

    private static InvoiceDto ToDto(Invoice inv) => new()
    {
        Id = inv.Id,
        RentalId = inv.RentalId,
        CustomerId = inv.CustomerId,
        CreatedAtUtc = inv.CreatedAtUtc,
        Lines = inv.Lines.Select(l => new InvoiceLineDto { Label = l.Label, Amount = l.Amount }).ToList(),
        Total = inv.Total
    };
}
