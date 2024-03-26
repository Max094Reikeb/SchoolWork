import 'package:json_annotation/json_annotation.dart';

part 'product_response.g.dart';

@JsonSerializable(explicitToJson: true)
class ProductResponse {
  @JsonKey(name: 'response')
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
  @JsonKey(name: 'name')
  final String name;
  @JsonKey(name: 'altName')
  final String altName;

  Products(this.name, this.altName);

  factory Products.fromJson(Map<String, dynamic> json) =>
      _$ProductsFromJson(json);

  Map<String, dynamic> toJson() => _$ProductsToJson(this);

  @override
  String toString() {
    return 'Products{name: $name, altName: $altName}';
  }
}
