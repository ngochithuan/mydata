import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("company-sales_data.csv", delimiter=',')
#print(df)

total_profit = df["total_profit"]
months = df["month_number"]

plt.plot(months, total_profit)
plt.xlabel("Months")
plt.ylabel("USD")
plt.title("Total profit of all months")
plt.show()

plt.xlabel("Months")
plt.ylabel("USD")
toothPaste = df["toothpaste"]

plt.scatter(months, toothPaste, label = "H", color = "r")
plt.show()
