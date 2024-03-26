import 'package:json_annotation/json_annotation.dart';

part 'product_response.g.dart';

@JsonSerializable(explicitToJson: true)
class ProductResponse {
  final Products response;

  ProductResponse(this.response);

  factory ProductResponse.fromJson(Map<String, dynamic> json) =>
      _$ProductResponseFromJson(json);

  Map<String, dynamic> toJson() => _$ProductResponseToJson(this);

  @override
  String toString() {
    return 'ProductResponse{response: $response}';
  }
}

@JsonSerializable(explicitToJson: true)
class Products {
  final String barcode;
  final String name;
  final String altName;
  final Pictures pictures;
  final String quantity;
  final List<String> brands;
  final List<String> stores;
  final List<String> manufacturingCountries;

  // Nutriscore
  // Novascore
  // Ecoscore
  final Ingredients ingredients;

  // traces
  // allergens
  final Map<String, String> additives;

  // nutrientLevels
  // nutritionFacts
  // ingredientsFromPalmOil

  Products(
      this.barcode,
      this.name,
      this.altName,
      this.pictures,
      this.quantity,
      this.brands,
      this.stores,
      this.manufacturingCountries,
      this.ingredients,
      this.additives);

  factory Products.fromJson(Map<String, dynamic> json) =>
      _$ProductsFromJson(json);

  Map<String, dynamic> toJson() => _$ProductsToJson(this);

  @override
  String toString() {
    return 'Products{name: $name, altName: $altName}';
  }
}

@JsonSerializable(explicitToJson: true)
class Pictures {
  final String product;
  final String front;
  final String ingredients;
  final String nutrition;

  Pictures(this.product, this.front, this.ingredients, this.nutrition);

  factory Pictures.fromJson(Map<String, dynamic> json) =>
      _$PicturesFromJson(json);

  Map<String, dynamic> toJson() => _$PicturesToJson(this);
}

@JsonSerializable(explicitToJson: true)
class Ingredients {
  final List<String> list;

  Ingredients(this.list);

  factory Ingredients.fromJson(Map<String, dynamic> json) =>
      _$IngredientsFromJson(json);

  Map<String, dynamic> toJson() => _$IngredientsToJson(this);
}
