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
      json['name'] as String?,
      json['altName'] as String?,
      json['pictures'] == null
          ? null
          : DataPictures.fromJson(json['pictures'] as Map<String, dynamic>),
      json['quantity'] as String?,
      (json['brands'] as List<dynamic>?)?.map((e) => e as String).toList(),
      (json['stores'] as List<dynamic>?)?.map((e) => e as String).toList(),
      (json['countries'] as List<dynamic>?)?.map((e) => e as String).toList(),
      (json['manufacturingCountries'] as List<dynamic>?)
          ?.map((e) => e as String)
          .toList(),
      $enumDecodeNullable(_$DataNutriScoreEnumMap, json['nutriScore']),
      $enumDecodeNullable(_$DataNovaScoreEnumMap, json['novaScore']),
      $enumDecodeNullable(_$DataEcoScoreEnumMap, json['ecoScoreGrade']),
      json['ingredients'] == null
          ? null
          : DataIngredients.fromJson(
              json['ingredients'] as Map<String, dynamic>),
      json['traces'] == null
          ? null
          : DataTraces.fromJson(json['traces'] as Map<String, dynamic>),
      json['allergens'] == null
          ? null
          : DataAllergens.fromJson(json['allergens'] as Map<String, dynamic>),
      (json['additives'] as Map<String, dynamic>?)?.map(
        (k, e) => MapEntry(k, e as String),
      ),
      json['analysis'] == null
          ? null
          : DataAnalysis.fromJson(json['analysis'] as Map<String, dynamic>),
    );

Map<String, dynamic> _$ProductResponseDataToJson(
        ProductResponseData instance) =>
    <String, dynamic>{
      'barcode': instance.barcode,
      'name': instance.name,
      'altName': instance.altName,
      'pictures': instance.pictures?.toJson(),
      'quantity': instance.quantity,
      'brands': instance.brands,
      'stores': instance.stores,
      'countries': instance.sellingCountries,
      'manufacturingCountries': instance.manufacturingCountries,
      'nutriScore': _$DataNutriScoreEnumMap[instance.nutriScore],
      'novaScore': _$DataNovaScoreEnumMap[instance.novaScore],
      'ecoScoreGrade': _$DataEcoScoreEnumMap[instance.ecoScore],
      'ingredients': instance.ingredients?.toJson(),
      'traces': instance.traces?.toJson(),
      'allergens': instance.allergens?.toJson(),
      'additives': instance.additives,
      'analysis': instance.analysis?.toJson(),
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
      json['product'] as String?,
      json['front'] as String?,
      json['ingredients'] as String?,
      json['nutrition'] as String?,
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
      (json['list'] as List<dynamic>?)?.map((e) => e as String).toList(),
      (json['details'] as List<dynamic>?)
          ?.map(
              (e) => DataIngredientDetails.fromJson(e as Map<String, dynamic>))
          .toList(),
    );

Map<String, dynamic> _$DataIngredientsToJson(DataIngredients instance) =>
    <String, dynamic>{
      'list': instance.list,
      'details': instance.details?.map((e) => e.toJson()).toList(),
    };

DataIngredientDetails _$DataIngredientDetailsFromJson(
        Map<String, dynamic> json) =>
    DataIngredientDetails(
      json['vegan'] as bool?,
      json['vegetarian'] as bool?,
      json['containsPalmOil'] as bool?,
      json['percent'] as String?,
      json['value'] as String?,
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
      (json['list'] as List<dynamic>?)?.map((e) => e as String).toList(),
    );

Map<String, dynamic> _$DataTracesToJson(DataTraces instance) =>
    <String, dynamic>{
      'list': instance.list,
    };

DataAllergens _$DataAllergensFromJson(Map<String, dynamic> json) =>
    DataAllergens(
      (json['list'] as List<dynamic>?)?.map((e) => e as String).toList(),
    );

Map<String, dynamic> _$DataAllergensToJson(DataAllergens instance) =>
    <String, dynamic>{
      'list': instance.list,
    };

DataAdditives _$DataAdditivesFromJson(Map<String, dynamic> json) =>
    DataAdditives(
      json['name'] as String?,
      json['description'] as String?,
    );

Map<String, dynamic> _$DataAdditivesToJson(DataAdditives instance) =>
    <String, dynamic>{
      'name': instance.name,
      'description': instance.description,
    };

DataAnalysis _$DataAnalysisFromJson(Map<String, dynamic> json) => DataAnalysis(
      $enumDecodeNullable(_$DataAnalysisStatusEnumMap, json['palmOil']),
      $enumDecodeNullable(_$DataAnalysisStatusEnumMap, json['vegan']),
      $enumDecodeNullable(_$DataAnalysisStatusEnumMap, json['vegetarian']),
    );

Map<String, dynamic> _$DataAnalysisToJson(DataAnalysis instance) =>
    <String, dynamic>{
      'palmOil': _$DataAnalysisStatusEnumMap[instance.palmOil],
      'vegan': _$DataAnalysisStatusEnumMap[instance.vegan],
      'vegetarian': _$DataAnalysisStatusEnumMap[instance.vegetarian],
    };

const _$DataAnalysisStatusEnumMap = {
  DataAnalysisStatus.Yes: 'yes',
  DataAnalysisStatus.No: 'no',
  DataAnalysisStatus.Maybe: 'maybe',
  DataAnalysisStatus.Unknown: 'unknown',
};
