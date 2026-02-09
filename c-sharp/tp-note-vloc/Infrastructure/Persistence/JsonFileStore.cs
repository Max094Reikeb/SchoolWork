using System.Text.Json;
using System.Text.Json.Serialization;

namespace VLoc.Infrastructure.Persistence;

public class JsonFileStore
{
    private readonly JsonSerializerOptions _options = new()
    {
        WriteIndented = true,
        Converters = { new JsonStringEnumConverter() }
    };

    public T LoadOrCreate<T>(string path, Func<T> factory)
    {
        EnsureDirectory(path);

        if (!File.Exists(path))
        {
            var created = factory();
            Save(path, created);
            return created;
        }

        var json = File.ReadAllText(path);

        // On check le cas où le JSON est vide / blanc
        if (string.IsNullOrWhiteSpace(json))
        {
            var created = factory();
            Save(path, created);
            return created;
        }

        try
        {
            var data = JsonSerializer.Deserialize<T>(json, _options);
            return data ?? factory();
        }
        catch(JsonException)
        {
            // Si le JSON est corrompu -> On renomme et on remet au propre
            var backup = path + $".bad.{DateTime.UtcNow:yyyyMMddHHmmss}";
            File.Copy(path, backup, overwrite: true);

            var created = factory();
            Save(path, created);
            return created;
        }
    }

    public void Save<T>(string path, T data)
    {
        EnsureDirectory(path);
        var json = JsonSerializer.Serialize(data, _options);
        File.WriteAllText(path, json);
    }

    private static void EnsureDirectory(string path)
    {
        var dir = Path.GetDirectoryName(path);
        if (!string.IsNullOrWhiteSpace(dir))
            Directory.CreateDirectory(dir);
    }
}
