import pandas as pd
import numpy as np

df = pd.read_csv("iris.csv", delimiter=',')
print(df)
print(df.describe())

data_sepal_length = df["sepal_length"]
data_sepal_width = df["sepal_width"]
data_petal_length = df["petal_length"]
data_petal_width = df["petal_width"]


def count(data):
    return len(data)

def mean(data):
    return sum(data)/len(data)

def standard_deviation(data):
    meanD = mean(data)
    s = 0
    for item in data:
        s = s + (item - meanD)**2
    s = s / (len(data)-1)
    return s**(1/2)

def mint(data):
    min = data[0]
    for item in data:
        if item < min:
            min = item
    return min

def maxt(data):
    max = data[0]
    for item in data:
        if item > max:
            max = item
    return max


# print()    
# print(count(data_petal_length))
# print("-----------------------")
# print(mean(data_sepal_length))
# print(mean(data_sepal_width))
# print(mean(data_petal_length))
# print(mean(data_petal_width))
# print("-----------------------")
# print(standard_deviation(data_sepal_length))
# print(standard_deviation(data_sepal_width))
# print(standard_deviation(data_petal_length))
# print(standard_deviation(data_petal_width))
# print("-----------------------")
# print(max(data_sepal_length))
# print(max(data_sepal_width))
# print(max(data_petal_length))
# print(max(data_petal_width))
# print("-----------------------")
# print(min(data_sepal_length))
# print(min(data_sepal_width))
# print(min(data_petal_length))
# print(min(data_petal_width))

data = [data_sepal_length, data_sepal_width, data_petal_length, data_petal_width]

# count_data = np.empty(4)
# mean_data = np.empty(4)
# std_data = np.empty(4)
# min_data = np.empty(4)
# max_data = np.empty(4)

count_data = []
mean_data = []
std_data = []
min_data = []
max_data = []

# count_data[i] = count(data[i])
# mean_data[i] = mean(data[i])
# std_data[i] = standard_deviation(data[i])
# min_data[i] = mint(data[i])
# max_data[i] = maxt(data[i])

for i in range(0, len(df.columns)-1):
    count_data.append(count(data[i]))
    mean_data.append(mean(data[i]))    
    std_data.append(standard_deviation(data[i]))
    min_data.append(mint(data[i]))
    max_data.append(maxt(data[i]))
    
result_data = pd.DataFrame([count_data, mean_data, std_data, min_data, max_data])
result_data.columns = ["sepal_length", "sepal_width", "petal_length", "petal_width"]
result_data.index = ["count", "mean", "std", "min", "max"]
print(result_data)

# result_data = np.array(5, 4)
# print(result_data)
