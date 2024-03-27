import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:my_flutter_project/product_api.dart';
import 'package:my_flutter_project/product_response.dart';

import 'Product.dart';

abstract class ProductEvent {}

class ChargeEvent extends ProductEvent {
  String barcode = "";
}

class ProductBlock extends Bloc<ProductEvent, ProductState> {
  ProductBlock() : super(ProductState.initial()) {
    on<ChargeEvent>(_onCharge);
  }

  Future<void> _onCharge(
    ChargeEvent event,
    Emitter<ProductState> emit,
  ) async {
    ProductResponse product =
        await ProductApiManager().getProduct(event.barcode);
    emit(ProductState(product.getProduct()));
  }
}

class ProductState {
  final Product? product;

  ProductState(this.product);

  ProductState.initial() : product = null;
}
