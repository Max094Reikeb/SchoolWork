// TD 1
// Exercice 1.1
string name = "Maxence";
int age = 24;
double height = 172;

Console.WriteLine($"Nom: {name}, age: {age}, taille: {height}cm");

// Exercice 1.2
int x = 4;
int y = 7;
Console.WriteLine($"x + y = {x+y}");
Console.WriteLine($"x - y = {x-y}");
Console.WriteLine($"x * y = {x*y}");
Console.WriteLine($"x / y = {x/y}");

// Exercice 1.3
string chaine = "123";
int entier = 42;
double pi = 3.14;

int chaineToInt = int.Parse(chaine);
string intToChaine = Convert.ToString(entier);
int doubleToInt = Convert.ToInt32(pi);

Console.WriteLine($"{chaineToInt} est maintenant un {chaineToInt.GetType()}");
Console.WriteLine($"{intToChaine} est maintenant un {intToChaine.GetType()}");
Console.WriteLine($"{doubleToInt} est maintenant un {doubleToInt.GetType()}");

// Exercice 1.4
Console.Write("Entrez votre prix unitaire HT (€): ");
decimal unitaireHT = decimal.Parse(Console.ReadLine());

Console.Write("Entrez le taux de TVA (%): ");
decimal tauxTVA = decimal.Parse(Console.ReadLine());

Console.Write("Entrez le nombre d'articles: ");
int quantite = int.Parse(Console.ReadLine());

decimal totalHT = unitaireHT * quantite;
decimal totalTTC = totalHT * (1 + tauxTVA / 100);

Console.WriteLine($"\n--- Résultat ---");
Console.WriteLine($"Prix unitaire HT : {unitaireHT} €");
Console.WriteLine($"Quantité : {quantite}");
Console.WriteLine($"Taux TVA : {tauxTVA} %");
Console.WriteLine($"Total HT : {totalHT} €");
Console.WriteLine($"Total TTC : {totalTTC} €");

// Exercice 2.1
int evenOrOdd = 23;
if (evenOrOdd % 2 == 0) {
    Console.WriteLine($"{evenOrOdd} est un nombre pair !");
} else {
    Console.WriteLine($"{evenOrOdd} est un nombre impair !");
}

// Exercice 2.2
int note = 13;
if (note >= 16) {
    Console.WriteLine("Mention: Très bien");
} else if (note >= 14) {
    Console.WriteLine("Mention: Bien");
} else if (note >= 12) {
    Console.WriteLine("Mention: Assez bien");
} else if (note >= 10) {
    Console.WriteLine("Mention: Passable");
} else {
    Console.WriteLine("Mention: Inssufisant");
}

// Exercice 2.3
Console.Write("Entrez le montant de votre panier (€): ");
decimal montantPanier = decimal.Parse(Console.ReadLine());

if (montantPanier > 100) {
    Console.WriteLine("Réduction de 10% !");
} else if (montantPanier > 50) {
    Console.WriteLine("Réduction de 5% !");
} else {
    Console.WriteLine("Pas de réduction !");
}
