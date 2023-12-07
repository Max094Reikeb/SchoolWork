import numpy as np

arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])

# Addition des tableaux
addition = arr1 + arr2

# Multiplication des tableaux
multiplication = arr1 * arr2

# Produit scalaire
dot_product = np.dot(arr1, arr2)

# Transpositions
transpose = arr1.T

print("Addition ", addition)
print("Multiplication ", multiplication)
print("Produit scalaire ", dot_product)
print("Transposition ", transpose)
