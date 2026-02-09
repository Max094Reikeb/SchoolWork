using VLoc.Domain.Entities;

namespace VLoc.Infrastructure.Repositories;

public class InMemoryCustomerRepository : IRepository<Customer>
{
    private readonly List<Customer> _items = new();

    public Customer? Get(Guid id) => _items.FirstOrDefault(x => x.Id == id);
    public IReadOnlyList<Customer> GetAll() => _items;

    public void Add(Customer item) => _items.Add(item);
}
