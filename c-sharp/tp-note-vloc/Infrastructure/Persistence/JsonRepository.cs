namespace VLoc.Infrastructure.Persistence;

public abstract class JsonRepository<TDto>
{
    protected readonly JsonFileStore Store;
    protected readonly string PathFile;
    protected List<TDto> Items;

    protected JsonRepository(JsonFileStore store, string pathFile)
    {
        Store = store;
        PathFile = pathFile;
        Items = Store.LoadOrCreate(pathFile, () => new List<TDto>());
    }

    protected void Persist() => Store.Save(PathFile, Items);
}
