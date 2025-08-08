import networkx as nx
import matplotlib.pyplot as plt

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
