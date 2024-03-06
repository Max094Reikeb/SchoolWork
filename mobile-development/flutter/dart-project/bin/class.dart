import 'dart:io';

import 'package:dart_project/dart_project.dart' as dart_project;

void main(List<String> arguments) {
  // Vehicle v1 = Vehicle(100, 5);
  // print(v1.toString()); // Instance of 'Vehicle'
  // Vehicle v2 = Vehicle(100, 5);
  // print(v2 == v1); // false car les emplacements mémoire sont différents
  // v2.speedUp(50);
  // print(v2.getSpeed());
}

abstract class Vehicle {
  int _currentSpeed = 0;
  int capacity;

  Vehicle._(this._currentSpeed, this.capacity);

  factory(String type) {
    switch (type) {
      case "bike":
        return Bike(_currentSpeed);
      case "car":
        return Car(_currentSpeed);
      default:
        throw Exception("Erreur avec le type de véhicule !");
    }
  }

  int getSpeed() {
    return _currentSpeed;
  }

  void speedUp(int speedUp) {
    _currentSpeed += speedUp;
  }
}

class Bike extends Vehicle {
  Bike(int _currentSpeed) : super._(_currentSpeed, 1);
}

class Car extends Vehicle {
  Car(int _currentSpeed) : super._(_currentSpeed, 4);
}
