using VLoc.Domain.ValueObjects;

namespace VLoc.Infrastructure.Repositories;

public interface IInvoiceRepository
{
    IReadOnlyList<Invoice> GetAll();
    void Add(Invoice invoice);
    void Save();
}
