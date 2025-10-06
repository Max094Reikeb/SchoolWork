using System;

public static class Ex3
{

    private static readonly Random Rng = new();

    public static void Run()
    {
        Console.Write("Entrez un nombre d'allumettes impair et supérieur à 3: ");
        if (!int.TryParse(Console.ReadLine(), out int n) || n <= 3 || n % 2 == 0)
        {
            Console.WriteLine("Invalide (doit être un entier impair et supérieur à 3).");
            return;
        }

        int remaining = n;
        bool humanTurn = true;
        while (remaining > 0)
        {
            Console.WriteLine($"\nAllumettes restantes: {remaining}");
            int taken = humanTurn ? HumanMove(remaining) : ComputerMove(remaining);
            remaining -= taken;

            if (remaining == 0)
            {
                Console.WriteLine(humanTurn
                    ? "Vous avez pris la dernière allumette - PERDU !"
                    : "L'Ordinateur a pris la dernière allumette, et a perdu - GAGNÉ !");
                break;
            }

            humanTurn = !humanTurn;
        }
    }

    private static int HumanMove(int remaining)
    {
        while (true)
        {
            Console.Write("Votre tour (prenez en 1 à 3): ");
            if (int.TryParse(Console.ReadLine(), out int t) && t >= 1 && t <= 3 && t <= remaining)
                return t;
            Console.WriteLine("Invalide.");
        }
    }

    private static int ComputerMove(int remaining)
    {
        int max = Math.Min(3, remaining);
        int t = Rng.Next(1, max + 1);
        Console.WriteLine($"L'Ordinateur en a pris {t}.");
        return t;
    }
}
