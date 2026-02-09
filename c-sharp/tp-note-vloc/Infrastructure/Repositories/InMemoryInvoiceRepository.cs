using VLoc.Domain.ValueObjects;

namespace VLoc.Infrastructure.Repositories;

public class InMemoryInvoiceRepository : IRepository<Invoice>
{
    private readonly List<Invoice> _items = new();

    public Invoice? Get(Guid id) => _items.FirstOrDefault(x => x.Id == id);
    public IReadOnlyList<Invoice> GetAll() => _items;

    public void Add(Invoice item) => _items.Add(item);
}
