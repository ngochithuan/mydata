import matplotlib.pyplot as plt
import networkx as nx
import numpy as np

A1 = np.array([
    [0, 3, 5, 2],
    [0, 0, 2, 0],
    [0, 0, 0, 3],
    [0, 0, 0, 0]
])

G1 = nx.from_numpy_array(A1)

pos = nx.spring_layout(G1)

labels = {i: ch for i, ch in enumerate('abcd')}

nx.draw_networkx(G1, pos=pos, with_labels=True, labels=labels, node_color='lightblue', arrows=True)
edge_labels = nx.get_edge_attributes(G1, 'weight')
nx.draw_networkx_edge_labels(G1, pos=pos, edge_labels=edge_labels, font_size=8)

plt.axis('equal')
plt.show()

def mPlus(A, B):
    rows = len(A)
    cols = len(A[0])
    C = [[A[i][j] + B[i][j] for j in range(cols)] for i in range(rows)]
    return C

def mMinus(A, B):
    rows = len(A)
    cols = len(A[0])
    C = [[A[i][j] - B[i][j] for j in range(cols)] for i in range(rows)]
    return C

def mMultiply(A, B):
    rows_A = len(A)
    cols_A = len(A[0])
    cols_B = len(B[0])

    C = [[0 for _ in range(cols_B)] for _ in range(rows_A)]

    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                C[i][j] += A[i][k] * B[k][j]
    return C

def mTranspose(A):
    rows = len(A)
    cols = len(A[0])
    T = [[A[j][i] for j in range(rows)] for i in range(cols)]
    return T

A = [[1, 2], [3, 4]]
B = [[5, 6], [7, 8]]

print("A + B =", mPlus(A, B))
print("A - B =", mMinus(A, B))
print("A * B =", mMultiply(A, B))
print("Transpose A =", mTranspose(A))

A = [[1, 4, 6, 10], [2, 7, 5, 3]]
B = [[1, 4, 6], [2, 7 , 5], [9, 0, 11], [3, 1, 0]]
print("A * B =", mMultiply(A, B))




