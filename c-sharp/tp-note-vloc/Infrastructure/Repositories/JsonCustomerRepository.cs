using VLoc.Domain.Entities;
using VLoc.Domain.Enums;
using VLoc.Infrastructure.Dtos;
using VLoc.Infrastructure.Persistence;

namespace VLoc.Infrastructure.Repositories;

public class JsonCustomerRepository : JsonRepository<CustomerDto>, ICustomerRepository
{
    public JsonCustomerRepository(JsonFileStore store, string pathFile) : base(store, pathFile) { }

    public IReadOnlyList<Customer> GetAll() => Items.Select(ToDomain).ToList();
    public Customer? Get(Guid id) => Items.Where(x => x.Id == id).Select(ToDomain).FirstOrDefault();

    public void Add(Customer customer)
    {
        Items.Add(ToDto(customer));
        Persist();
    }

    public void Update(Customer customer)
    {
        var idx = Items.FindIndex(c => c.Id == customer.Id);
        if (idx < 0)
            throw new InvalidOperationException("Client introuvable (update).");

        Items[idx] = ToDto(customer);
        Persist();
    }

    public void Save() => Persist();

    private static Customer ToDomain(CustomerDto dto)
    {
        Customer c = dto.Type switch
        {
            CustomerType.Premium => new PremiumCustomer(),
            _ => new StandardCustomer()
        };

        // ⚠️ Id a un getter only dans ton Domain; pour un projet simple, on accepte que l'Id
        // en mémoire change si tu recharges. Si tu veux un Id persistant, dis-moi et je te montre
        // un pattern avec Id settable ou factory.
        c.FullName = dto.FullName;
        return c;
    }

    private static CustomerDto ToDto(Customer c) => new()
    {
        Id = c.Id,
        FullName = c.FullName,
        Type = c.Type
    };
}
