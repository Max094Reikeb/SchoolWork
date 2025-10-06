using System;

public static class Ex1
{
    public static void Run()
    {
        Console.WriteLine("### Exercice 1 ###");
        Console.Write("Entrez votre entier naturel: ");
        int n = int.Parse(Console.ReadLine());

        Console.WriteLine($"Les nombres parfaits jusqu'à {n} sont:");
        for (int x = 2; x <= n; x++)
        {
            if (IsPerfect(x))
                Console.WriteLine(x);
        }
    }

    private static bool IsPerfect(int x)
    {
        int sum = 1;
        if (x == 1) return false;

        int limit = (int)Math.Sqrt(x);
        for (int d = 2; d <= limit; d++)
        {
            if (x % d == 0)
            {
                sum += d;
                int other = x / d;
                if (other != d) sum += other;
            }
        }
        return sum == x;
    }
}
