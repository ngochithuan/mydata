import matplotlib.pyplot as plt
import networkx as nx
import numpy as np

# Example

A1=np.array([
[0,3,5,2],
[0,0,2,0],
[0,0,0,3],
[0,0,0,0]])

G1 = nx.from_numpy_array(A1)
pos=nx.spring_layout(G1)
nx.draw_networkx(G1,pos=pos,with_labels=True,labels={a:b for
a,b in enumerate('abcd')})
edge_labels = nx.draw_networkx_edge_labels(G1,font_size=6,
pos=pos,label_pos=0.5)
plt.axis('equal')
plt.show()

# Exercise 1

def mPlus(A, B):
    if (len(A) != len(B)):
        print("Can't calculate")
        return -1
    
    resultArray = np.empty((len(A), len(A[0])))
    for i in range(0, len(A)):
        for j in range(0, len(A[0])):
            resultArray[i][j] = A[i][j] + B[i][j]
            
    return resultArray

A = [[10, -2],
      [3, 5]]

B = [[-1, 4],
      [7, 0]]

print("Exercise 1a:")
print(mPlus(A, B))


def mMinus(A, B):
    if (len(A) != len(B)):
        print("Can't calculate")
        return -1
    
    resultArray = np.empty((len(A), len(A[0])))
    for i in range(0, len(A)):
        for j in range(0, len(A[0])):
            resultArray[i][j] = A[i][j] - B[i][j]
    return resultArray

print("Exercise 1b:")
print(mMinus(A, B))

def mMultiply(A,B):
    n = len(A[0])
    resultArray = np.empty((len(A), len(B[0])))
    for i in range(0, len(A)):
        for j in range(0, len(B[0])):
            temp = 0
            for k in range(0, n):
                temp = A[i][k] * B[k][j]
            resultArray[i][j] = temp
    return resultArray

A = [[1, 2, 3],
     [4, 5, 6]]

B = [[7, 8],
     [9, 10],
     [11, 12]]

print("Exercise 1c:")
print(mMultiply(A, B))

def mTranspose(A):
    return np.transpose(A)

print("Exercise 1d:")
print(mTranspose(A))

# Exercise 2:
A1 = np.array([
    [0, 0, 3, 0, 1],
    [0, 0, 0, 0, 0],
    [0, 5, 0, 1, 0],
    [0, 3, 0, 0, 2],
    [0, 0, 0, 0, 0]
])

G1 = nx.from_numpy_array(A1)

pos = nx.spring_layout(G1)

labels = {i: ch for i, ch in enumerate('abcde')}

nx.draw_networkx(G1, pos=pos, with_labels=True, labels=labels, node_color='lightblue', arrows=True)
edge_labels = nx.get_edge_attributes(G1, 'weight')
nx.draw_networkx_edge_labels(G1, pos=pos, edge_labels=edge_labels, font_size=8)

plt.axis('equal')
plt.show()


A = np.array([
    [1, 0, 0, 0, 0, 0],
    [0, 0, 5, 3, 0, 0],
    [0, 0, 0, 1, 5, 0],
    [0, 0, 0, 0, 2, 3],
    [1, 0, 0, 0, 0, 6],
    [1, 0, 0, 0, 0, 0]
])

G1 = nx.from_numpy_array(A)

pos = nx.spring_layout(G1)

labels = {i: ch for i, ch in enumerate('abcdef')}

nx.draw_networkx(G1, pos=pos, with_labels=True, labels=labels, node_color='lightblue', arrows=True)
edge_labels = nx.get_edge_attributes(G1, 'weight')
nx.draw_networkx_edge_labels(G1, pos=pos, edge_labels=edge_labels, font_size=8)

plt.axis('equal')
plt.show()

# Exercise 3:

edges = [
    ('A', 'C', 5),
    ('A', 'D', 3),
    ('B', 'C', 3),
    ('B', 'D', 2),
    ('C', 'D', 1),
    ('C', 'E', 3),
    ('D', 'E', 1),
    ('D', 'F', 3),
    ('E', 'F', 4)
]

G = nx.Graph()  
G.add_weighted_edges_from(edges)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=1000, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.title("Weighted Graph")
plt.show()


edges = [
    ('A', 'C', 2),
    ('A', 'D', 3),
    ('A', 'E', 3),
    ('B', 'C', 3),
    ('B', 'D', 2),
    ('C', 'D', 2),
    ('C', 'E', 8),
    ('C', 'F', 6),
    ('D', 'F', 5),
    ('E', 'F', 3)
]

G = nx.Graph()  
G.add_weighted_edges_from(edges)

pos = nx.spring_layout(G, seed=42)
nx.draw(G, pos, with_labels=True, node_color='lightgreen', node_size=1000, font_weight='bold')
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.title("Weighted Graph b)")
plt.show()

# Exercise 4:

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

# Exercise 5:

G = nx.DiGraph()

edges = [
    ("Monkeys", "Primates"),
    ("Apes", "Primates"),
    ("Gorillas", "Primates"),
    ("Mice", "Rodents"),
    ("Squirrels", "Rodents"),
    ("Beavers", "Rodents"),
    ("Crocodiles", "Reptiles"),
    ("Komodo dragons", "Reptiles"),
    ("Lizards", "Reptiles"),
    ("Coconut trees", "Plants"),
    ("Grasses", "Plants"),
    ("Oaks", "Plants"),
    ("Mushrooms", "Fungi"),
    ("Molds", "Fungi"),
    ("Yeasts", "Fungi"),
    ("Yeasts", "Unicellular organisms"),
    ("Primates", "Mammals"),
    ("Rodents", "Mammals"),
    ("Mammals", "Animals"),
    ("Rodents", "Animals"),
    ("Reptiles", "Animals"),
    ("Animals", "Multicellular organisms"),
    ("Plants", "Multicellular organisms"),
    ("Mushrooms", "Multicellular organisms"),
    ("Molds", "Multicellular organisms"),
]

G.add_edges_from(edges)

plt.figure(figsize=(14, 10))
pos = nx.spring_layout(G, k=0.6, seed=42)
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=2000, font_size=10, arrowsize=20)
plt.title("Biological Classification Graph")
plt.show()
