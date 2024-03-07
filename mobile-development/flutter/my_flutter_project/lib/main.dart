import 'package:flutter/material.dart';
import 'package:flutter_svg/flutter_svg.dart';
import 'package:my_flutter_project/app_colors.dart';
import 'package:my_flutter_project/app_icons.dart';

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
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const AddCardScreen(),
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
