import 'package:json_annotation/json_annotation.dart';
import 'package:my_flutter_project/Product.dart';

part 'product_response.g.dart';

@JsonSerializable(explicitToJson: true)
class ProductResponse {
  @JsonKey(name: 'response')
  final ProductResponseData response;

  ProductResponse(this.response);

  factory ProductResponse.fromJson(Map<String, dynamic> json) =>
      _$ProductResponseFromJson(json);

  Map<String, dynamic> toJson() => _$ProductResponseToJson(this);

  Product getProduct() {
    return Product(
        barcode: response.barcode,
        name: response.name,
        altName: response.altName,
        picture: response.pictures?.product,
        quantity: response.quantity,
        brands: response.brands,
        sellingCountries: response.sellingCountries,
        manufacturingCountries: response.manufacturingCountries,
        nutriScore: switch (response.nutriScore) {
          DataNutriScore.A => ProductNutriscore.A,
          DataNutriScore.B => ProductNutriscore.B,
          DataNutriScore.C => ProductNutriscore.C,
          DataNutriScore.D => ProductNutriscore.D,
          DataNutriScore.E => ProductNutriscore.E,
          null => throw UnimplementedError()
        },
        novaScore: switch (response.novaScore) {
          DataNovaScore.Group1 => ProductNovaScore.Group1,
          DataNovaScore.Group2 => ProductNovaScore.Group2,
          DataNovaScore.Group3 => ProductNovaScore.Group3,
          DataNovaScore.Group4 => ProductNovaScore.Group4,
          null => throw Exception('Unknown nova group!')
        },
        ecoScore: switch (response.ecoScore) {
          DataEcoScore.A => ProductEcoScore.A,
          DataEcoScore.B => ProductEcoScore.B,
          DataEcoScore.C => ProductEcoScore.C,
          DataEcoScore.D => ProductEcoScore.D,
          DataEcoScore.E => ProductEcoScore.E,
          null => throw Exception('Unknown nova group!')
        },
        ingredients: response.ingredients?.list,
        traces: response.traces?.list,
        allergens: response.allergens?.list,
        additives: response.additives,
        analysis: ProductAnalysis(
            palmOil: switch (response.analysis?.palmOil) {
              DataAnalysisStatus.Yes => AnalysisStatus.Yes,
              DataAnalysisStatus.No => AnalysisStatus.No,
              DataAnalysisStatus.Maybe => AnalysisStatus.Maybe,
              DataAnalysisStatus.Unknown => AnalysisStatus.Unknown,
              null => throw UnimplementedError()
            },
            vegan: switch (response.analysis?.vegan) {
              DataAnalysisStatus.Yes => AnalysisStatus.Yes,
              DataAnalysisStatus.No => AnalysisStatus.No,
              DataAnalysisStatus.Maybe => AnalysisStatus.Maybe,
              DataAnalysisStatus.Unknown => AnalysisStatus.Unknown,
              null => throw UnimplementedError()
            },
            vegetarian: switch (response.analysis?.vegetarian) {
              DataAnalysisStatus.Yes => AnalysisStatus.Yes,
              DataAnalysisStatus.No => AnalysisStatus.No,
              DataAnalysisStatus.Maybe => AnalysisStatus.Maybe,
              DataAnalysisStatus.Unknown => AnalysisStatus.Unknown,
              null => throw UnimplementedError()
            }));
  }

  @override
  String toString() {
    return '';
  }
}

@JsonSerializable(explicitToJson: true)
class ProductResponseData {
  final String barcode;
  final String? name;
  final String? altName;
  final DataPictures? pictures;
  final String? quantity;
  final List<String>? brands;
  final List<String>? stores;
  @JsonKey(name: 'countries')
  final List<String>? sellingCountries;
  final List<String>? manufacturingCountries;
  @JsonKey(name: 'nutriScore')
  final DataNutriScore? nutriScore;
  @JsonKey(name: 'novaScore')
  final DataNovaScore? novaScore;
  @JsonKey(name: 'ecoScoreGrade')
  final DataEcoScore? ecoScore;
  final DataIngredients? ingredients;
  final DataTraces? traces;
  final DataAllergens? allergens;

  // @JsonKey(fromJson: additiveFromJSON, toJson: additiveToJSON)
  // final List<Additive> additives;
  final Map<String, String>? additives;
  final DataAnalysis? analysis;

  ProductResponseData(
      this.barcode,
      this.name,
      this.altName,
      this.pictures,
      this.quantity,
      this.brands,
      this.stores,
      this.sellingCountries,
      this.manufacturingCountries,
      this.nutriScore,
      this.novaScore,
      this.ecoScore,
      this.ingredients,
      this.traces,
      this.allergens,
      this.additives,
      this.analysis);

  factory ProductResponseData.fromJson(Map<String, dynamic> json) =>
      _$ProductResponseDataFromJson(json);

  Map<String, dynamic> toJson() => _$ProductResponseDataToJson(this);

  static List<DataAdditives> additiveFromJSON(Object json) {
    List<DataAdditives> additives = [];
    for (var element in (json as Map<String, dynamic>).entries) {
      additives.add(DataAdditives(element.key, element.value));
    }
    return additives;
  }

  static Map<String, String> additiveToJSON(List<DataAdditives> additives) {
    return <String, String>{};
  }

  @override
  String toString() {
    return 'barcode: $barcode, name: $name, altName: $altName, quantity: $quantity, additifs: $additives}';
  }
}

@JsonSerializable(explicitToJson: true)
class DataPictures {
  final String? product;
  final String? front;
  final String? ingredients;
  final String? nutrition;

  DataPictures(this.product, this.front, this.ingredients, this.nutrition);

  factory DataPictures.fromJson(Map<String, dynamic> json) =>
      _$DataPicturesFromJson(json);

  Map<String, dynamic> toJson() => _$DataPicturesToJson(this);
}

@JsonSerializable(explicitToJson: true)
class DataIngredients {
  final List<String>? list;
  final List<DataIngredientDetails>? details;

  DataIngredients(this.list, this.details);

  factory DataIngredients.fromJson(Map<String, dynamic> json) =>
      _$DataIngredientsFromJson(json);

  Map<String, dynamic> toJson() => _$DataIngredientsToJson(this);
}

enum DataNutriScore {
  @JsonValue('A')
  A,
  @JsonValue('B')
  B,
  @JsonValue('C')
  C,
  @JsonValue('D')
  D,
  @JsonValue('E')
  E,
}

enum DataNovaScore {
  @JsonValue(1)
  Group1,
  @JsonValue(2)
  Group2,
  @JsonValue(3)
  Group3,
  @JsonValue(4)
  Group4,
}

enum DataEcoScore {
  @JsonValue('A')
  A,
  @JsonValue('B')
  B,
  @JsonValue('C')
  C,
  @JsonValue('D')
  D,
  @JsonValue('E')
  E,
}

@JsonSerializable(explicitToJson: true)
class DataIngredientDetails {
  final bool? vegan;
  final bool? vegetarian;
  final bool? containsPalmOil;
  final String? percent;
  final String? value;

  DataIngredientDetails(this.vegan, this.vegetarian, this.containsPalmOil,
      this.percent, this.value);

  factory DataIngredientDetails.fromJson(Map<String, dynamic> json) =>
      _$DataIngredientDetailsFromJson(json);

  Map<String, dynamic> toJson() => _$DataIngredientDetailsToJson(this);
}

@JsonSerializable(explicitToJson: true)
class DataTraces {
  final List<String>? list;

  DataTraces(this.list);

  factory DataTraces.fromJson(Map<String, dynamic> json) =>
      _$DataTracesFromJson(json);

  Map<String, dynamic> toJson() => _$DataTracesToJson(this);
}

@JsonSerializable(explicitToJson: true)
class DataAllergens {
  final List<String>? list;

  DataAllergens(this.list);

  factory DataAllergens.fromJson(Map<String, dynamic> json) =>
      _$DataAllergensFromJson(json);

  Map<String, dynamic> toJson() => _$DataAllergensToJson(this);
}

@JsonSerializable(explicitToJson: true)
class DataAdditives {
  final String? name;
  final String? description;

  DataAdditives(this.name, this.description);

  factory DataAdditives.fromJson(Map<String, dynamic> json) =>
      _$DataAdditivesFromJson(json);

  Map<String, dynamic> toJson() => _$DataAdditivesToJson(this);

  @override
  String toString() {
    return '$name : $description';
  }
}

enum DataAnalysisStatus {
  @JsonValue('yes')
  Yes,
  @JsonValue('no')
  No,
  @JsonValue('maybe')
  Maybe,
  @JsonValue('unknown')
  Unknown
}

@JsonSerializable(explicitToJson: true)
class DataAnalysis {
  final DataAnalysisStatus? palmOil;
  final DataAnalysisStatus? vegan;
  final DataAnalysisStatus? vegetarian;

  DataAnalysis(this.palmOil, this.vegan, this.vegetarian);

  factory DataAnalysis.fromJson(Map<String, dynamic> json) =>
      _$DataAnalysisFromJson(json);

  Map<String, dynamic> toJson() => _$DataAnalysisToJson(this);
}
