using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Choisissez exercice (1-5): ");
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
            case "4":
                // Exercice 4
                Ex4.Run();
                break;
            case "5":
                // Exercice 5
                Ex5.Run();
                break;
            default:
                Console.WriteLine("Erreur.");
                break;
        }
    }
}
