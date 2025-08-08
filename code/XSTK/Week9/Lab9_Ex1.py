import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv("iris.csv", delimiter=',')
print(df)

x = df["sepal_length"]
y = df["sepal_width"]

x = np.array(x)
y = np.array(y)

# print(x)
# print(y)

plt.xlabel("sepal_length")
plt.ylabel("sepal_width")

setosa = df[df["species"] == "setosa"]
versicolor = df[df["species"] == "versicolor"]
virginica = df[df["species"] == "virginica"]

plt.scatter(setosa["sepal_length"], setosa["sepal_width"], label = "setosa", color = "r")
plt.scatter(versicolor["sepal_length"], setosa["sepal_width"], label = "versicolor", color = "g")
plt.scatter(virginica["sepal_length"], setosa["sepal_width"], label = "virginica", color = "b")

plt.legend()
plt.show()


