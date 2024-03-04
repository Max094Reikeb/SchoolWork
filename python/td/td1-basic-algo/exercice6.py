print("Entrez la valeur de a")
a = float(input())
print("Entrez la valeur de b")
b = float(input())
print("Entrez la valeur de c")
c = float(input())
print(f"a = {a}, b = {b}, c = {c}")
d = a
a = b
b = c
c = d
print(f"Après permutation, a = {a}, b = {b}, c = {c}")
