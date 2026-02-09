using VLoc.Domain.Enums;

namespace VLoc.Infrastructure.Dtos;

public class CustomerDto
{
    public Guid Id { get; set; }
    public string FullName { get; set; } = "";
    public CustomerType Type { get; set; }
}
