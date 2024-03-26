// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'product_response.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

ProductResponse _$ProductResponseFromJson(Map<String, dynamic> json) =>
    ProductResponse(
      Products.fromJson(json['response'] as Map<String, dynamic>),
    );

Map<String, dynamic> _$ProductResponseToJson(ProductResponse instance) =>
    <String, dynamic>{
      'response': instance.response.toJson(),
    };

Products _$ProductsFromJson(Map<String, dynamic> json) => Products(
      json['barcode'] as String,
      json['name'] as String,
      json['altName'] as String,
      Pictures.fromJson(json['pictures'] as Map<String, dynamic>),
      json['quantity'] as String,
      (json['brands'] as List<dynamic>).map((e) => e as String).toList(),
      (json['stores'] as List<dynamic>).map((e) => e as String).toList(),
      (json['manufacturingCountries'] as List<dynamic>)
          .map((e) => e as String)
          .toList(),
      Ingredients.fromJson(json['ingredients'] as Map<String, dynamic>),
      Map<String, String>.from(json['additives'] as Map),
    );

Map<String, dynamic> _$ProductsToJson(Products instance) => <String, dynamic>{
      'barcode': instance.barcode,
      'name': instance.name,
      'altName': instance.altName,
      'pictures': instance.pictures.toJson(),
      'quantity': instance.quantity,
      'brands': instance.brands,
      'stores': instance.stores,
      'manufacturingCountries': instance.manufacturingCountries,
      'ingredients': instance.ingredients.toJson(),
      'additives': instance.additives,
    };

Pictures _$PicturesFromJson(Map<String, dynamic> json) => Pictures(
      json['product'] as String,
      json['front'] as String,
      json['ingredients'] as String,
      json['nutrition'] as String,
    );

Map<String, dynamic> _$PicturesToJson(Pictures instance) => <String, dynamic>{
      'product': instance.product,
      'front': instance.front,
      'ingredients': instance.ingredients,
      'nutrition': instance.nutrition,
    };

Ingredients _$IngredientsFromJson(Map<String, dynamic> json) => Ingredients(
      (json['list'] as List<dynamic>).map((e) => e as String).toList(),
    );

Map<String, dynamic> _$IngredientsToJson(Ingredients instance) =>
    <String, dynamic>{
      'list': instance.list,
    };
