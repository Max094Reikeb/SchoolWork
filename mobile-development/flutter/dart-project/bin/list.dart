import 'dart:io';

import 'package:dart_project/dart_project.dart' as dart_project;

void main(List<String> arguments) {
  List<int> l1 = [25, 42, 79, 12];
  l1.sort((b, a) => a.compareTo(b));
  print(l1);
  Iterable<int> l2 = l1.map((e) {
    return e *= 2;
  });
  print(l2);
  Iterable<int> l3 = l1.where((element) => element.isEven);
  print(l3);
}
