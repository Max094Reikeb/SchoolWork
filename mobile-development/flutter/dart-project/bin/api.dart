import 'dart:convert';
import 'dart:io';

import 'package:http/http.dart' as http;

void main(List<String> arguments) {
  print("Quel est votre prénom ? ");
  String name = stdin.readLineSync()!;
  agify(name);
  genderize(name);
  nationalize(name);
}

Future<void> agify(String name) async {
  var url = Uri.https('api.agify.io', '/', {'name': name, 'country_id': 'FR'});
  var response = await http.get(url);

  Map<dynamic, dynamic> json = jsonDecode(response.body);
  int? age = json['age'];
  if (age != null) {
    print("L'âge moyen de votre prénom est de : $age ans");
  } else {
    print("L'âge moyen de votre prénom n'est pas disponible.");
  }
}

Future<void> genderize(String name) async {
  var url =
      Uri.https('api.genderize.io', '/', {'name': name, 'country_id': 'FR'});
  var response = await http.get(url);

  Map<dynamic, dynamic> json = jsonDecode(response.body);
  print("Votre prénom est plus porté par des : ${json['gender']}");
}

Future<void> nationalize(String name) async {
  var url = Uri.https('api.nationalize.io', '/', {'name': name});
  var response = await http.get(url);

  Map<String, dynamic> json = jsonDecode(response.body);
  List<String> countryIds = json['country']
      .map<String>((country) => country['country_id'] as String)
      .toList();
  print(
      "Votre prénom est plus porté dans les pays suivants : ${countryIds.join(", ")}");
}
