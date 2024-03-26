import 'package:flutter/material.dart';
import 'package:my_flutter_project/app_colors.dart';
import 'package:my_flutter_project/app_icons.dart';

class Exercice extends StatelessWidget {
  const Exercice({super.key});

  @override
  Widget build(BuildContext context) {
    final double height = MediaQuery.sizeOf(context).height;

    return Scaffold(
      backgroundColor: AppColors.blueLight,
      appBar: AppBar(
        leading: IconButton(
            icon: const Icon(Icons.chevron_left, color: AppColors.white),
            onPressed: () {}),
      ),
      body: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          const Placeholder(),
          SizedBox(height: height * 0.1),
          const Text(
            'Scan a QR to Pay',
            textAlign: TextAlign.center,
            style: TextStyle(
                fontSize: 25,
                fontWeight: FontWeight.bold,
                color: AppColors.white),
          ),
          const Text(
            'Hold the code inside the frame, it will be scanned automatically',
            textAlign: TextAlign.center,
            style: TextStyle(color: AppColors.white),
          ),
          SizedBox(height: height * 0.1),
          Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              IconButton(
                  icon: const Icon(Icons.flash_on, color: AppColors.white),
                  onPressed: () {}),
              const SizedBox(width: 20),
              SizedBox(
                width: 40,
                height: 40,
                child: AspectRatio(
                  aspectRatio: 1.0,
                  child: Container(
                    decoration: const BoxDecoration(
                        shape: BoxShape.circle, color: Colors.white),
                  ),
                ),
              ),
              const SizedBox(width: 20),
              IconButton(
                  icon: const Icon(Icons.settings_backup_restore,
                      color: AppColors.white),
                  onPressed: () {})
            ],
          )
        ],
      ),
    );
  }
}
