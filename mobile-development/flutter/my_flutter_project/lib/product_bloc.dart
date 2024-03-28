import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:my_flutter_project/product_api.dart';
import 'package:my_flutter_project/product_response.dart';

import 'Product.dart';

abstract class ProductEvent {}

class ChargeEvent extends ProductEvent {
  final String barcode;

  ChargeEvent(this.barcode);
}

class ProductBlock extends Bloc<ProductEvent, ProductState> {
  final String barcode;

  ProductBlock(this.barcode) : super(ProductState.initial()) {
    on<ChargeEvent>(_onCharge);
    add(ChargeEvent(barcode));
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
