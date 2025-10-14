using System;
using System.Collections.Generic;

public static class Ex3
{
    public sealed class Arbre
    {
        public int Etat { get; private set; }

        public Arbre(int etat = 0)
        {
            if (etat < 0 || etat > 3) throw new ArgumentOutOfRangeException(nameof(etat));
            Etat = etat;
        }

        public char Symbole() => Etat switch
        {
            0 => '.',
            1 => 'A',
            2 => 'F',
            3 => 'C',
            _ => '?'
        };

        public int ProchainEtat(bool voisinFeu)
        {
            return Etat switch
            {
                0 => 0,
                1 => voisinFeu ? 2 : 1,
                2 => 3,
                3 => 3,
                _ => Etat
            };
        }

        public void FixerEtat(int nouvelEtat)
        {
            if (nouvelEtat < 0 || nouvelEtat > 3) throw new ArgumentOutOfRangeException(nameof(nouvelEtat));
            Etat = nouvelEtat;
        }
    }

    public sealed class Foret
    {
        public int Lignes { get; }
        public int Colonnes { get; }
        public Arbre[,] Grille { get; }

        private readonly Random _rng = new();

        public Foret(int lignes, int colonnes, double p)
        {
            if (lignes <= 0 || colonnes <= 0) throw new ArgumentOutOfRangeException("Dimensions invalides.");
            if (p < 0 || p > 1) throw new ArgumentOutOfRangeException(nameof(p));

            Lignes = lignes;
            Colonnes = colonnes;
            Grille = new Arbre[Lignes, Colonnes];

            var arbresSains = new List<(int r, int c)>();
            for (int r = 0; r < Lignes; r++)
            {
                for (int c = 0; c < Colonnes; c++)
                {
                    bool hasTree = _rng.NextDouble() < p;
                    int etat = hasTree ? 1 : 0;
                    Grille[r, c] = new Arbre(etat);
                    if (etat == 1) arbresSains.Add((r, c));
                }
            }

            if (arbresSains.Count > 0)
            {
                var (r0, c0) = arbresSains[_rng.Next(arbresSains.Count)];
                Grille[r0, c0].FixerEtat(2);
            }
        }

        public void Afficher()
        {
            for (int r = 0; r < Lignes; r++)
            {
                for (int c = 0; c < Colonnes; c++)
                {
                    Console.Write(Grille[r, c].Symbole());
                }
                Console.WriteLine();
            }
            Console.WriteLine($"Proportion d'arbres sains : {ProportionArbresSains()}");
        }

        public bool AVoisinEnFeu(int r, int c)
        {
            var voisins = new (int rr, int cc)[]
            {
                (r-1, c), (r+1, c), (r, c-1), (r, c+1)
            };
            foreach (var (rr, cc) in voisins)
            {
                if (rr >= 0 && rr < Lignes && cc >= 0 && cc < Colonnes)
                {
                    if (Grille[rr, cc].Etat == 2) return true;
                }
            }
            return false;
        }

        public (bool anyFire, bool anyHealthy) ProchaineGeneration()
        {
            int[,] nouveauxEtats = new int[Lignes, Colonnes];

            for (int r = 0; r < Lignes; r++)
            {
                for (int c = 0; c < Colonnes; c++)
                {
                    bool voisinFeu = AVoisinEnFeu(r, c);
                    nouveauxEtats[r, c] = Grille[r, c].ProchainEtat(voisinFeu);
                }
            }

            bool anyFire = false;
            bool anyHealthy = false;

            for (int r = 0; r < Lignes; r++)
            {
                for (int c = 0; c < Colonnes; c++)
                {
                    Grille[r, c].FixerEtat(nouveauxEtats[r, c]);
                    if (nouveauxEtats[r, c] == 2) anyFire = true;
                    if (nouveauxEtats[r, c] == 1) anyHealthy = true;
                }
            }

            return (anyFire, anyHealthy);
        }

        public double ProportionArbresSains()
        {
            int total = Lignes * Colonnes;
            if (total == 0) return 0;
            int sains = 0;
            for (int r = 0; r < Lignes; r++)
                for (int c = 0; c < Colonnes; c++)
                    if (Grille[r, c].Etat == 1) sains++;
            return (double)sains / total;
        }

        public void Generer(int n, bool pauseParTouche = true)
        {
            for (int gen = 1; gen <= n; gen++)
            {
                Console.WriteLine($"\n--- Génération {gen} ---");
                Afficher();

                if (pauseParTouche)
                {
                    Console.WriteLine("Appuyez sur n'importe quelle touche pour passer à la génération suivante...");
                    Console.ReadKey(intercept: true);
                }

                var (anyFire, _) = ProchaineGeneration();
                if (!anyFire)
                {
                    Console.WriteLine("\nPlus aucun arbre en feu. Simulation terminée.");
                    Afficher();
                    return;
                }
            }

            Console.WriteLine("\nNombre maximal de générations atteint.");
            Afficher();
        }
    }

    public static void Run()
    {
        Console.WriteLine("=== Exercice 3 : Feux de forêts ===");
        int n = LireEntier("Nombre de lignes", defaut: 20, min: 1);
        int m = LireEntier("Nombre de colonnes", defaut: 40, min: 1);
        double p = LireDouble("Probabilité d'avoir un arbre (0..1)", defaut: 0.6, min: 0, max: 1);
        int tours = LireEntier("Nombre max de générations", defaut: 200, min: 1);

        var foret = new Foret(n, m, p);
        Console.WriteLine("\n--- État initial ---");
        foret.Afficher();

        Console.WriteLine("Appuyez sur n'importe quelle touche pour commencer...");
        Console.ReadKey(intercept: true);

        foret.Generer(tours, pauseParTouche: true);
    }

    private static int LireEntier(string label, int defaut, int min)
    {
        while (true)
        {
            Console.Write($"{label} [{defaut}] : ");
            var s = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(s)) return defaut;
            if (int.TryParse(s, out var v) && v >= min) return v;
            Console.WriteLine($"Veuillez entrer un entier ≥ {min}.");
        }
    }
    
    private static double LireDouble(string label, double defaut, double min, double max)
    {
        while (true)
        {
            Console.Write($"{label} [{defaut}] : ");
            var s = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(s)) return defaut;
            if (double.TryParse(s, out var v) && v >= min && v <= max) return v;
            Console.WriteLine($"Veuillez entrer un réel entre {min} et {max}.");
        }
    }
}
