using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Choisissez exercice (1-3): ");
        string? choice = Console.ReadLine();

        switch (choice)
        {
            case "1":
                // Exercice 1
                Ex1.Run();
                break;
            case "2":
                // Exercice 2
                Ex2.Run();
                break;
            case "3":
                // Exercice 3
                Ex3.Run();
                break;
            default:
                Console.WriteLine("Erreur.");
                break;
        }
    }
}
