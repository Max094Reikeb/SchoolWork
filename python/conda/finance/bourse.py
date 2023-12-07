import yfinance as yf
import matplotlib.pyplot as plt

ticker_symbol = "NVDA"
df = yf.download(ticker_symbol, '2016-01-01', '2019-08-01')
df['Close'].plot()
plt.show()
