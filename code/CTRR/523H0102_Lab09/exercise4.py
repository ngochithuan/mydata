import matplotlib.pyplot as plt
import networkx as nx
import numpy as np

def toLoE(A):
    edges = []
    n = len(A)
    for i in range(n):
        for j in range(i + 1, n): 
            if A[i][j] != 0:
                edges.append((i, j, A[i][j]))  
    return edges

A = [
    [0, 2, 0],
    [2, 0, 3],
    [0, 3, 0]
]

print(toLoE(A)) 