import 'package:flutter/material.dart';
import 'package:my_flutter_project/product_api.dart';

class MyScreenWithRequest extends StatelessWidget {
  const MyScreenWithRequest({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: FutureBuilder(
          future: ProductApiManager().getProduct("5000159484695"),
          builder: (BuildContext context, AsyncSnapshot<dynamic> snapshot) {
            if (!snapshot.hasData) {
              return const CircularProgressIndicator();
            } else if (snapshot.hasError) {
              return const Text('Une erreur est survenue !');
            } else {
              return Text('C\'est ok ! ${snapshot.data!.toString()}');
            }
          },
        ),
      ),
    );
  }
}
