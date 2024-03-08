import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:my_flutter_project/app_colors.dart';
import 'package:my_flutter_project/app_icons.dart';
import 'package:my_flutter_project/complete_app.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primaryColor: AppColors.blue,
        primaryColorLight: AppColors.blueLight,
        primaryColorDark: AppColors.blueDark,
        fontFamily: 'Avenir',
        appBarTheme: const AppBarTheme(
          centerTitle: false,
          backgroundColor: AppColors.white,
          elevation: 0.0,
          iconTheme: IconThemeData(
            color: AppColors.blue,
          ),
          titleTextStyle: TextStyle(
            color: AppColors.blue,
            fontSize: 18.0,
            fontWeight: FontWeight.bold,
          ),
        ),
        textTheme: const TextTheme(
          displayLarge: TextStyle(
            color: AppColors.blue,
            fontSize: 22.0,
            fontWeight: FontWeight.bold,
          ),
          displayMedium: TextStyle(
            color: AppColors.gray2,
            fontSize: 18.0,
          ),
          headlineMedium: TextStyle(
            color: AppColors.gray3,
            fontSize: 17.0,
          ),
          headlineSmall: TextStyle(
            color: AppColors.blue,
            fontSize: 17.0,
            fontWeight: FontWeight.bold,
          ),
        ),
        dividerColor: AppColors.gray2,
        bottomNavigationBarTheme: const BottomNavigationBarThemeData(
          showSelectedLabels: true,
          showUnselectedLabels: true,
          selectedItemColor: AppColors.blue,
          unselectedItemColor: AppColors.gray2,
          type: BottomNavigationBarType.fixed,
        ),
      ),
      home: const ProductInfo(),
    );
  }
}

class AddCardScreen extends StatelessWidget {
  const AddCardScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final double height = MediaQuery.sizeOf(context).height;

    return Scaffold(
      appBar: AppBar(
        title: const Text('Mes scans'),
        centerTitle: false,
        actions: [
          IconButton(icon: const Icon(AppIcons.barcode), onPressed: () {})
        ],
      ),
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            SvgPicture.asset("res/svg/ill_empty.svg"),
            SizedBox(height: height * 0.1),
            const Text(
              'Vous n\'avez pas encore scanné de produit.',
              textAlign: TextAlign.center,
            ),
            SizedBox(height: height * 0.1),
            TextButton(
              onPressed: () {},
              style: OutlinedButton.styleFrom(
                foregroundColor: AppColors.blue,
                shape: const RoundedRectangleBorder(
                    borderRadius: BorderRadius.all(Radius.circular(22.0))),
                backgroundColor: AppColors.yellow,
              ),
              child: Row(
                mainAxisSize: MainAxisSize.min,
                children: [
                  Text('Commencer'.toUpperCase()),
                  const SizedBox(width: 15.0),
                  const Icon(
                    Icons.arrow_right_alt,
                  ),
                ],
              ),
            )
          ],
        ),
      ),
    );
  }
}

class HeaderScreen extends StatelessWidget {
  const HeaderScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Stack(
        children: [
          Positioned(
            top: 0.0,
            left: 0.0,
            right: 0.0,
            height: 300,
            child: Image.network(
              'https://plus.unsplash.com/premium_photo-1663858367001-89e5c92d1e0e',
              fit: BoxFit.cover,
            ),
          ),
          Positioned(
            top: 280.0,
            left: 0.0,
            right: 0.0,
            child: Container(
                height: 500,
                decoration: const BoxDecoration(
                  borderRadius: BorderRadius.vertical(
                    top: Radius.circular(16.0),
                  ),
                  color: Colors.white,
                ),
                padding: const EdgeInsets.symmetric(
                    horizontal: 20.0, vertical: 30.0),
                child: const Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [_HeaderName(), _Bandeau(), ButtonEnum()],
                )),
          ),
        ],
      ),
    );
  }
}

class _HeaderName extends StatelessWidget {
  const _HeaderName({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return const Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(
          'Petits pois et carottes',
          style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
        ),
        Text(
          'Cassegrain',
          style: TextStyle(color: AppColors.gray3),
        ),
      ],
    );
  }
}

class _Bandeau extends StatelessWidget {
  const _Bandeau({super.key});

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisSize: MainAxisSize.min,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Expanded(
              flex: 44,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Image.asset("res/drawables/nutriscore_a.png"),
                ],
              ),
            ),
            const Divider(height: 100),
            const Expanded(
              flex: 66,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(
                    'Groupe NOVA',
                    style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                  ),
                  Text(
                    'Produits alimentaires et boissons ultra-transformées',
                    style: TextStyle(color: AppColors.gray3),
                  ),
                ],
              ),
            ),
          ],
        ),
        const Divider(),
        const Row(
          children: [
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(
                  'EcoScore',
                  style: TextStyle(
                      fontSize: 18,
                      fontWeight: FontWeight.bold,
                      color: AppColors.gray3),
                ),
                Row(
                  children: [
                    Icon(AppIcons.ecoscore_d),
                    Text(
                      'Impact environnemental élevé',
                      style: TextStyle(color: AppColors.gray3),
                    ),
                  ],
                ),
              ],
            ),
          ],
        ),
      ],
    );
  }
}

class ButtonEnum extends StatelessWidget {
  const ButtonEnum({super.key});

  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Container(
          decoration: const BoxDecoration(
            borderRadius: BorderRadius.all(Radius.circular(15.0)),
            color: AppColors.blueLight,
          ),
          padding: const EdgeInsets.symmetric(horizontal: 10.0, vertical: 8.0),
          child: const Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              Icon(
                Icons.check,
                color: AppColors.white,
              ),
              SizedBox(
                width: 10.0,
              ),
              Text(
                "Végétalien",
                style: TextStyle(color: AppColors.white),
              )
            ],
          ),
        )
      ],
    );
  }
}
