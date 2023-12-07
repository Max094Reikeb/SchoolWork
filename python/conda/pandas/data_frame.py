import pandas as pd
import matplotlib.pyplot as plt

# Créer une DataFrame
df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})
df2 = pd.DataFrame({'A': [4, 5, 7], 'C': [9, 7, 8]})

# Créer une Series
s = pd.Series([10, 20, 30, 40])

print("Datas", df)
print("Series", s)

data = pd.read_csv('data.csv')
data_xlsx = pd.read_excel('data.xlsx')

data.to_csv('nouveau_data.csv', index=False)

data['C'] = data['A'] + data['B']
grouped = data.groupby('A').mean()

pivot = data.pivot_table(index='Ligne', columns='Colonne', values="valeur")
merged = pd.merge(df, df2, on='Clé')

data.plot(kind='scatter', x='A', y='B')
plt.show()
