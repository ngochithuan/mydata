import matplotlib.pyplot as plt
import networkx as nx
import numpy as np


A1 = np.array([
    [0, 0, 3, 0, 1],  # a
    [0, 0, 0, 0, 0],  # b
    [0, 5, 0, 1, 0],  # c
    [0, 3, 0, 0, 2],  # d
    [0, 0, 0, 0, 0]   # e
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
    [1, 0, 0, 0, 0, 0],  # a
    [0, 0, 5, 3, 0, 0],  # b
    [0, 0, 0, 1, 5, 0],  # c
    [0, 0, 0, 0, 2, 3],  # d
    [1, 0, 0, 0, 0, 6],  # e
    [1, 0, 0, 0, 0, 0]   # f
])

G1 = nx.from_numpy_array(A)

pos = nx.spring_layout(G1)

labels = {i: ch for i, ch in enumerate('abcdef')}

nx.draw_networkx(G1, pos=pos, with_labels=True, labels=labels, node_color='lightblue', arrows=True)
edge_labels = nx.get_edge_attributes(G1, 'weight')
nx.draw_networkx_edge_labels(G1, pos=pos, edge_labels=edge_labels, font_size=8)

plt.axis('equal')
plt.show()


