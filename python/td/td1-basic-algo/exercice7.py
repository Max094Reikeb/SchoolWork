print("Entrez la raison")
raison = int(input())
print("Entrez le premier terme")
u0 = int(input())
print("Entrez le nombre d'éléments")
n = int(input())
s = n * (((2 * u0) + ((n - 1) * raison)) // 2)
print(f"La somme des {n} premiers termes est {s}")