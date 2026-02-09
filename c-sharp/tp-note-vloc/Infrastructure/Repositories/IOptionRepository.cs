using VLoc.Domain.ValueObjects;

namespace VLoc.Infrastructure.Repositories;

public interface IOptionRepository
{
    IReadOnlyList<(Guid Id, RentalOption Option)> GetAll();
    (Guid Id, RentalOption Option)? Get(Guid id);
    void Add(Guid id, RentalOption option);
    void Save();
}
