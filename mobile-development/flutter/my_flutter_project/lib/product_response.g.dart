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
      json['name'] as String,
      json['altName'] as String,
    );

Map<String, dynamic> _$ProductsToJson(Products instance) => <String, dynamic>{
      'name': instance.name,
      'altName': instance.altName,
    };
