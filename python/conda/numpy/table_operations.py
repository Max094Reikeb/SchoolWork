import numpy as np


def somme(array):
    arraySomme = 0
    for i in array:
        arraySomme += i
    return arraySomme


def mean(array):
    return somme(array) / len(array)


def maximum(array):
    maxSomme = array[0]
    for i in array:
        if maxSomme < i:
            maxSomme = i
    return maxSomme


def minimum(array):
    minSomme = array[0]
    for i in array:
        if minSomme > i:
            minSomme = i
    return minSomme


def sorting(array):
    return np.sort(array)


arr = np.array([1, 2, 3, 4, 5])

print("Somme ", somme(arr))
print("Moyenne ", mean(arr))
print("Max ", maximum(arr))
print("Min ", minimum(arr))
print("Rangé ", sorting(arr))
