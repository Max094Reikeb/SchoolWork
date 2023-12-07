import pandas as pd
import matplotlib.pyplot as plt

# Créer une DataFrame
data = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})
x = [1, 2, 3]
y = [4, 5, 6]

# data.plot(kind='scatter', x='A', y='B')
plt.plot(x, y)
plt.xlabel('Axe des x')
plt.ylabel('Axe des y')
plt.title('Graphique linéaire')
plt.show()
