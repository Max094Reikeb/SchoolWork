// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'product_response.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

ProductResponse _$ProductResponseFromJson(Map<String, dynamic> json) =>
    ProductResponse(
      ProductResponseData.fromJson(json['response'] as Map<String, dynamic>),
    );

Map<String, dynamic> _$ProductResponseToJson(ProductResponse instance) =>
    <String, dynamic>{
      'response': instance.response.toJson(),
    };

ProductResponseData _$ProductResponseDataFromJson(Map<String, dynamic> json) =>
    ProductResponseData(
      json['barcode'] as String,
      json['name'] as String,
      json['altName'] as String,
      DataPictures.fromJson(json['pictures'] as Map<String, dynamic>),
      json['quantity'] as String,
      (json['brands'] as List<dynamic>).map((e) => e as String).toList(),
      (json['stores'] as List<dynamic>).map((e) => e as String).toList(),
      (json['manufacturingCountries'] as List<dynamic>)
          .map((e) => e as String)
          .toList(),
      $enumDecode(_$DataNutriScoreEnumMap, json['nutriScore']),
      $enumDecode(_$DataNovaScoreEnumMap, json['novaScore']),
      $enumDecode(_$DataEcoScoreEnumMap, json['ecoScoreGrade']),
      DataIngredients.fromJson(json['ingredients'] as Map<String, dynamic>),
      DataTraces.fromJson(json['traces'] as Map<String, dynamic>),
      DataAllergens.fromJson(json['allergens'] as Map<String, dynamic>),
      Map<String, String>.from(json['additives'] as Map),
    );

Map<String, dynamic> _$ProductResponseDataToJson(
        ProductResponseData instance) =>
    <String, dynamic>{
      'barcode': instance.barcode,
      'name': instance.name,
      'altName': instance.altName,
      'pictures': instance.pictures.toJson(),
      'quantity': instance.quantity,
      'brands': instance.brands,
      'stores': instance.stores,
      'manufacturingCountries': instance.manufacturingCountries,
      'nutriScore': _$DataNutriScoreEnumMap[instance.nutriScore]!,
      'novaScore': _$DataNovaScoreEnumMap[instance.novaScore]!,
      'ecoScoreGrade': _$DataEcoScoreEnumMap[instance.ecoScore]!,
      'ingredients': instance.ingredients.toJson(),
      'traces': instance.traces.toJson(),
      'allergens': instance.allergens.toJson(),
      'additives': instance.additives,
    };

const _$DataNutriScoreEnumMap = {
  DataNutriScore.A: 'A',
  DataNutriScore.B: 'B',
  DataNutriScore.C: 'C',
  DataNutriScore.D: 'D',
  DataNutriScore.E: 'E',
};

const _$DataNovaScoreEnumMap = {
  DataNovaScore.Group1: 1,
  DataNovaScore.Group2: 2,
  DataNovaScore.Group3: 3,
  DataNovaScore.Group4: 4,
};

const _$DataEcoScoreEnumMap = {
  DataEcoScore.A: 'A',
  DataEcoScore.B: 'B',
  DataEcoScore.C: 'C',
  DataEcoScore.D: 'D',
  DataEcoScore.E: 'E',
};

DataPictures _$DataPicturesFromJson(Map<String, dynamic> json) => DataPictures(
      json['product'] as String,
      json['front'] as String,
      json['ingredients'] as String,
      json['nutrition'] as String,
    );

Map<String, dynamic> _$DataPicturesToJson(DataPictures instance) =>
    <String, dynamic>{
      'product': instance.product,
      'front': instance.front,
      'ingredients': instance.ingredients,
      'nutrition': instance.nutrition,
    };

DataIngredients _$DataIngredientsFromJson(Map<String, dynamic> json) =>
    DataIngredients(
      (json['list'] as List<dynamic>).map((e) => e as String).toList(),
      (json['details'] as List<dynamic>)
          .map((e) => DataIngredientDetails.fromJson(e as Map<String, dynamic>))
          .toList(),
    );

Map<String, dynamic> _$DataIngredientsToJson(DataIngredients instance) =>
    <String, dynamic>{
      'list': instance.list,
      'details': instance.details.map((e) => e.toJson()).toList(),
    };

DataIngredientDetails _$DataIngredientDetailsFromJson(
        Map<String, dynamic> json) =>
    DataIngredientDetails(
      json['vegan'] as bool,
      json['vegetarian'] as bool,
      json['containsPalmOil'] as bool,
      json['percent'] as String,
      json['value'] as String,
    );

Map<String, dynamic> _$DataIngredientDetailsToJson(
        DataIngredientDetails instance) =>
    <String, dynamic>{
      'vegan': instance.vegan,
      'vegetarian': instance.vegetarian,
      'containsPalmOil': instance.containsPalmOil,
      'percent': instance.percent,
      'value': instance.value,
    };

DataTraces _$DataTracesFromJson(Map<String, dynamic> json) => DataTraces(
      (json['list'] as List<dynamic>).map((e) => e as String).toList(),
    );

Map<String, dynamic> _$DataTracesToJson(DataTraces instance) =>
    <String, dynamic>{
      'list': instance.list,
    };

DataAllergens _$DataAllergensFromJson(Map<String, dynamic> json) =>
    DataAllergens(
      (json['list'] as List<dynamic>).map((e) => e as String).toList(),
    );

Map<String, dynamic> _$DataAllergensToJson(DataAllergens instance) =>
    <String, dynamic>{
      'list': instance.list,
    };

DataAdditives _$DataAdditivesFromJson(Map<String, dynamic> json) =>
    DataAdditives(
      json['name'] as String,
      json['description'] as String,
    );

Map<String, dynamic> _$DataAdditivesToJson(DataAdditives instance) =>
    <String, dynamic>{
      'name': instance.name,
      'description': instance.description,
    };
