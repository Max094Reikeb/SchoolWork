import numpy as np

# Créer un tableau multidimensionnnel
matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

# Accéder aux éléments
element = matrix[0, 1]

# Calculer la somme par colonnes
column_sum = np.sum(matrix, axis=0)

# Calculer la somme par lignes
row_sum = np.sum(matrix, axis=1)

print("Element ", element)
print("Column sum", column_sum)
print("Row sum", row_sum)
