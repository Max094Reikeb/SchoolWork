using System;

public static class Ex2
{
    public static void Run()
    {
        Console.WriteLine("### Exercice 2 ###");
        var logs  = new List<(string user, string ip)>
        {
            ("user1","192.168.1.1"),
            ("user2","192.168.1.10"),
            ("user3","10.0.0.2"),
            ("user1","192.168.1.10"),
            ("user4","203.0.113.15"),
            ("user5","198.51.100.23"),
            ("user1","203.0.113.15"),
        };
        var ip_user1 = new List<string>();
        foreach (var entry in logs)
        {
            if (entry.user == "user1")
                ip_user1.Add(entry.ip);
        }

        Console.WriteLine("Adresses IP de user1:");
        foreach (var ip in ip_user1)
            Console.WriteLine(ip);
    }
}
