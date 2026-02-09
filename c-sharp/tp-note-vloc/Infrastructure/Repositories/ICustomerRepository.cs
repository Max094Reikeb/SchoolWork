using VLoc.Domain.Entities;

namespace VLoc.Infrastructure.Repositories;

public interface ICustomerRepository
{
    IReadOnlyList<Customer> GetAll();
    Customer? Get(Guid id);
    void Add(Customer customer);
    void Save();
    void Update(Customer customer);
}
