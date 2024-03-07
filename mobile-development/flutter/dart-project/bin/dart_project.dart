import 'dart:io';

void main(List<String> arguments) {
  // MARK: Null
  int? num = 12;
  print(num.roundToDouble()); // affiche 12.0
  num = null;
  print(num); // affiche null
  print(num ?? "Vide");

  // MARK - Paramètres
  method(0);
  method(0, 1);
  method(0, null);
  method(0, 1, 4);

  // TVA
  print("Entrez un nombre dont vous voulez la TVA: ");
  tva(double.parse(stdin.readLineSync()!));
}

void method(int a, [int? b = 0, int? c = 0]) {}

void useFoo() {
  foo(name: 'a');
  foo(name: 'b', number: 1);
  foo(name: 'c', toUpperCase: true);
  foo(name: 'd', number: 2, toUpperCase: true);
}

String foo({required String name, int? number, bool? toUpperCase}) =>
    '${((toUpperCase ?? false) ? name.toUpperCase() : name)} $number';

int factoriel(int n) {
  if (n > 0) {
    return n * factoriel(n - 1);
  } else {
    return 1;
  }
}

void tva(double number) {
  double twoOne = number + ((2.1 * number) / 100);
  double fiveFive = number + ((5.5 * number) / 100);
  double ten = number + ((10.0 * number) / 100);
  double twenty = number + ((20.0 * number) / 100);
  print("\nTVA 2,1% : $twoOne€");
  print("TVA 5,5% : $fiveFive€");
  print("TVA 10,0% : $ten€");
  print("TVA 20,0% : $twenty€");
}
