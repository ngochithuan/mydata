import matplotlib.pyplot as plt
import networkx as nx
import numpy as np



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