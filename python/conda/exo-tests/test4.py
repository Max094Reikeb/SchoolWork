def isOdd(number):
    if number % 2 > 0:
        print(str(number) + ' is odd!')
    else:
        print(str(number) + ' is even!')
    return [number % 2]


yolo = isOdd(1)
print(yolo)
