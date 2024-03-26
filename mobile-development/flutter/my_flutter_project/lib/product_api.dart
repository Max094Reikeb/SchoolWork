import 'package:dio/dio.dart';
import 'package:my_flutter_project/product_response.dart';
import 'package:retrofit/http.dart';
import 'package:retrofit/retrofit.dart';

part 'product_api.g.dart';

@RestApi()
abstract class ProductAPI {
  factory ProductAPI(Dio dio, {required String baseUrl}) = _ProductAPI;

  @GET('/getProduct')
  Future<ProductResponse> loadProduct(@Query('barcode') String query);
}

class ProductApiManager {
  final ProductAPI _api =
      ProductAPI(Dio(), baseUrl: 'https://api.formation-android.fr/v2/');

  Future<ProductResponse> getProduct(String barcode) async {
    return _api.loadProduct(barcode);
  }
}
