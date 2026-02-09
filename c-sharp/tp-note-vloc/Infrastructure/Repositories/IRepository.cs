namespace VLoc.Infrastructure.Repositories;

public interface IRepository<T>
{
    T? Get(Guid id);
    IReadOnlyList<T> GetAll();
    void Add(T item);
}
