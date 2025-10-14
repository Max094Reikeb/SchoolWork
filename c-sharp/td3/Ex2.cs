using System;

public static class Ex2
{
    public class Personnage
    {
        public string Nom { get; }
        public int PointsDeVie { get; private set; }
        public int PointsDeVieMax { get; }
        public int Attaque { get; }
        public int Defense { get; }

        public bool EstKO => PointsDeVie <= 0;

        public Personnage(string nom, int pointsDeVie, int attaque, int defense)
        {
            if (string.IsNullOrWhiteSpace(nom)) throw new ArgumentException("Nom requis.", nameof(nom));
            if (pointsDeVie <= 0) throw new ArgumentOutOfRangeException(nameof(pointsDeVie));
            if (attaque < 0) throw new ArgumentOutOfRangeException(nameof(attaque));
            if (defense < 0) throw new ArgumentOutOfRangeException(nameof(defense));

            Nom = nom.Trim();
            PointsDeVie = pointsDeVie;
            PointsDeVieMax = pointsDeVie;
            Attaque = attaque;
            Defense = defense;
        }

        public virtual void Attaquer(Personnage cible)
        {
            if (cible is null) throw new ArgumentNullException(nameof(cible));
            var puissance = Attaque;
            InfligerDegats(cible, puissance);
        }

        protected static void InfligerDegats(Personnage cible, int puissanceAttaquant)
        {
            var degats = Math.Max(0, puissanceAttaquant - cible.Defense);
            cible.PointsDeVie = Math.Max(0, cible.PointsDeVie - degats);
            Console.WriteLine(degats > 0
                ? $"{cible.Nom} subit {degats} dégâts. PV restants: {cible.PointsDeVie}"
                : $"{cible.Nom} bloque l'attaque. PV: {cible.PointsDeVie}");
        }

        public void Soigner(int montant)
        {
            if (montant <= 0) return;
            PointsDeVie = Math.Min(PointsDeVie + montant, PointsDeVieMax);
        }

        public void SoignerComplet()
        {
            PointsDeVie = PointsDeVieMax;
        }

        public override string ToString() => $"{Nom} (PV:{PointsDeVie} ATQ:{Attaque} DEF:{Defense})";
    }

    public class Guerrier : Personnage
    {
        public int Force { get; }

        public Guerrier(string nom, int pointsDeVie, int attaque, int defense, int force)
            : base(nom, pointsDeVie, attaque, defense)
        {
            if (force < 0) throw new ArgumentOutOfRangeException(nameof(force));
            Force = force;
        }

        public override void Attaquer(Personnage cible)
        {
            Console.WriteLine($"{Nom} (Guerrier) frappe avec sa force ({Force}).");
            var puissance = Attaque + Force;
            InfligerDegats(cible, puissance);
        }

        public override string ToString() => base.ToString() + $" FORCE:{Force}";
    }

    public class Mage : Personnage
    {
        public int Magie { get; }

        public Mage(string nom, int pointsDeVie, int attaque, int defense, int magie)
            : base(nom, pointsDeVie, attaque, defense)
        {
            if (magie < 0) throw new ArgumentOutOfRangeException(nameof(magie));
            Magie = magie;
        }

        public override void Attaquer(Personnage cible)
        {
            Console.WriteLine($"{Nom} (Mage) lance un sort (Magie {Magie}).");
            var puissance = Attaque + Magie;
            InfligerDegats(cible, puissance);
        }

        public override string ToString() => base.ToString() + $" MAG:{Magie}";
    }

    public static void Run()
    {
        Console.WriteLine("=== Exercice 2 : Jeu de combat ===");

        var p1 = new Personnage("Aventurier", 30, 6, 3);
        var g1 = new Guerrier("Bjorn", 40, 7, 4, force: 3);
        var m1 = new Mage("Lyra", 28, 5, 2, magie: 6);

        Duel(g1, m1);
        g1.SoignerComplet();
        m1.SoignerComplet();
        Console.WriteLine();
        Duel(m1, p1);
        m1.SoignerComplet();
        p1.SoignerComplet();
        Console.WriteLine();
        Duel(p1, g1);
    }

    private static void Duel(Personnage a, Personnage b)
    {
        Console.WriteLine($"--- Duel : {a.Nom} vs {b.Nom} ---");

        Console.WriteLine(a);
        Console.WriteLine(b);

        var tour = 1;
        while (!a.EstKO && !b.EstKO)
        {
            Console.WriteLine($"> Tour {tour}");
            a.Attaquer(b);
            if (b.EstKO) break;
            b.Attaquer(a);
            tour++;
        }

        Console.WriteLine(a.EstKO
            ? $"Victoire de {b.Nom} !"
            : $"Victoire de {a.Nom} !");
    }
}
