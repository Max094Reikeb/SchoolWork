class Product {
  final String barcode;
  final String? name;
  final String? altName;
  final String? picture;
  final String? quantity;
  final List<String>? brands;
  final List<String>? sellingCountries;
  final List<String>? manufacturingCountries;
  final ProductNutriscore? nutriScore;
  final ProductNovaScore? novaScore;
  final ProductEcoScore? ecoScore;
  final List<String>? ingredients;
  final List<String>? traces;
  final List<String>? allergens;
  final Map<String, String>? additives;
  final NutrientLevels? nutrientLevels;
  final NutritionFacts? nutritionFacts;
  final bool? ingredientsFromPalmOil;
  final ProductAnalysis? analysis;

  Product(
      {required this.barcode,
      this.name,
      this.altName,
      this.picture,
      this.quantity,
      this.brands,
      this.sellingCountries,
      this.manufacturingCountries,
      this.nutriScore,
      this.novaScore,
      this.ecoScore,
      this.ingredients,
      this.traces,
      this.allergens,
      this.additives,
      this.nutrientLevels,
      this.nutritionFacts,
      this.ingredientsFromPalmOil,
      this.analysis});
}

class NutritionFacts {
  final String servingSize;
  final Nutriment? calories;
  final Nutriment? fat;
  final Nutriment? saturatedFat;
  final Nutriment? carbohydrate;
  final Nutriment? sugar;
  final Nutriment? fiber;
  final Nutriment? proteins;
  final Nutriment? sodium;
  final Nutriment? salt;
  final Nutriment? energy;

  NutritionFacts(
      {required this.servingSize,
      this.calories,
      this.fat,
      this.saturatedFat,
      this.carbohydrate,
      this.sugar,
      this.fiber,
      this.proteins,
      this.sodium,
      this.salt,
      this.energy});
}

class Nutriment {
  final String unit;
  final dynamic perServing;
  final dynamic per100g;

  Nutriment({required this.unit, this.perServing, this.per100g});
}

class NutrientLevels {
  final String? salt;
  final String? saturatedFat;
  final String? sugars;
  final String? fat;

  NutrientLevels({this.salt, this.saturatedFat, this.sugars, this.fat});
}

enum ProductNutriscore {
  A("a"),
  B("b"),
  C("c"),
  D("d"),
  E("e");

  final String letter;

  const ProductNutriscore(this.letter);
}

enum ProductNovaScore { Group1, Group2, Group3, Group4 }

enum ProductEcoScore { A, B, C, D, E }

class ProductAnalysis {
  final AnalysisStatus? palmOil;
  final AnalysisStatus? vegan;
  final AnalysisStatus? vegetarian;

  ProductAnalysis({this.palmOil, this.vegan, this.vegetarian});
}

enum AnalysisStatus { Yes, No, Maybe, Unknown }
