import pandas as pd
import numpy as np

df = pd.read_csv("population.csv", delimiter=',')
print(df)

country = set(df["Country Name"])
print(len(country))