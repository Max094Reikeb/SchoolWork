using System;
using System.Collections.Generic;
using System.Linq;

public static class Ex1
{
    public sealed class Livre
    {
        public string Titre { get; }
        public string Auteur { get; }
        public int Identifiant { get; }

        public Livre(string titre, string auteur, int identifiant)
        {
            if (string.IsNullOrWhiteSpace(titre)) throw new ArgumentException("Le titre est requis.", nameof(titre));
            if (string.IsNullOrWhiteSpace(auteur)) throw new ArgumentException("L'auteur est requis.", nameof(auteur));
            if (identifiant <= 0) throw new ArgumentOutOfRangeException(nameof(identifiant), "L'identifiant doit être strictement positif.");

            Titre = titre.Trim();
            Auteur = auteur.Trim();
            Identifiant = identifiant;
        }

        public override string ToString() => $"[{Identifiant}] \"{Titre}\" — {Auteur}";
    }

    public sealed class Bibliotheque
    {
        private readonly List<Livre> _livres = new();

        public bool AjouterLivre(Livre livre)
        {
            if (livre is null) throw new ArgumentNullException(nameof(livre));
            if (_livres.Any(l => l.Identifiant == livre.Identifiant)) return false;
            _livres.Add(livre);
            return true;
        }

        public bool SupprimerLivre(int identifiant)
        {
            var index = _livres.FindIndex(l => l.Identifiant == identifiant);
            if (index >= 0)
            {
                _livres.RemoveAt(index);
                return true;
            }
            return false;
        }

        public IEnumerable<Livre> RechercherLivreParTitre(string titre)
        {
            if (string.IsNullOrWhiteSpace(titre)) return Enumerable.Empty<Livre>();
            return _livres.Where(l => l.Titre.Contains(titre, StringComparison.OrdinalIgnoreCase));
        }

        public IEnumerable<Livre> RechercherLivreParAuteur(string auteur)
        {
            if (string.IsNullOrWhiteSpace(auteur)) return Enumerable.Empty<Livre>();
            return _livres.Where(l => l.Auteur.Contains(auteur, StringComparison.OrdinalIgnoreCase));
        }

        public IEnumerable<Livre> TousLesLivres() => _livres.OrderBy(l => l.Identifiant);

        public void AfficherTousLesLivres()
        {
            if (_livres.Count == 0)
            {
                Console.WriteLine("(aucun livre)");
                return;
            }
            foreach (var l in TousLesLivres())
                Console.WriteLine(l);
        }
    }

    public static void Run()
    {
        var bib = new Bibliotheque();

        bib.AjouterLivre(new Livre("Le Petit Prince", "Antoine de Saint-Exupéry", 1));
        bib.AjouterLivre(new Livre("L'Étranger", "Albert Camus", 2));
        bib.AjouterLivre(new Livre("Candide", "Voltaire", 3));

        while (true)
        {
            Console.WriteLine();
            Console.WriteLine("=== Bibliothèque ===");
            Console.WriteLine("1) Ajouter un livre");
            Console.WriteLine("2) Supprimer un livre");
            Console.WriteLine("3) Rechercher par titre");
            Console.WriteLine("4) Rechercher par auteur");
            Console.WriteLine("5) Afficher tous les livres");
            Console.WriteLine("0) Quitter");
            Console.Write("Votre choix: ");
            var input = Console.ReadLine();

            switch (input)
            {
                case "1":
                    Ajouter(bib);
                    break;
                case "2":
                    Supprimer(bib);
                    break;
                case "3":
                    RechercherTitre(bib);
                    break;
                case "4":
                    RechercherAuteur(bib);
                    break;
                case "5":
                    bib.AfficherTousLesLivres();
                    break;
                case "0":
                    return;
                default:
                    Console.WriteLine("Choix invalide.");
                    break;
            }
        }
    }

    private static void Ajouter(Bibliotheque bib)
    {
        Console.Write("Titre: ");
        var titre = Console.ReadLine() ?? "";
        Console.Write("Auteur: ");
        var auteur = Console.ReadLine() ?? "";
        Console.Write("Identifiant (entier > 0): ");
        if (!int.TryParse(Console.ReadLine(), out var id) || id <= 0)
        {
            Console.WriteLine("Identifiant invalide.");
            return;
        }

        try
        {
            var ok = bib.AjouterLivre(new Livre(titre, auteur, id));
            Console.WriteLine(ok ? "Livre ajouté." : "Échec: un livre avec cet identifiant existe déjà.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Erreur: {ex.Message}");
        }
    }

    private static void Supprimer(Bibliotheque bib)
    {
        Console.Write("Identifiant à supprimer: ");
        if (!int.TryParse(Console.ReadLine(), out var id) || id <= 0)
        {
            Console.WriteLine("Identifiant invalide.");
            return;
        }

        Console.WriteLine(bib.SupprimerLivre(id) ? "Livre supprimé." : "Aucun livre avec cet identifiant.");
    }
    
    private static void RechercherTitre(Bibliotheque bib)
    {
        Console.Write("Titre (ou fragment): ");
        var q = Console.ReadLine() ?? "";
        var res = bib.RechercherLivreParTitre(q).ToList();
        AfficherResultats(res);
    }

    private static void RechercherAuteur(Bibliotheque bib)
    {
        Console.Write("Auteur (ou fragment): ");
        var q = Console.ReadLine() ?? "";
        var res = bib.RechercherLivreParAuteur(q).ToList();
        AfficherResultats(res);
    }

    private static void AfficherResultats(List<Livre> res)
    {
        if (res.Count == 0)
        {
            Console.WriteLine("(aucun résultat)");
            return;
        }
        foreach (var l in res.OrderBy(l => l.Identifiant))
            Console.WriteLine(l);
    }
}
