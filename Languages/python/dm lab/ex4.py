
import networkx as nx
import matplotlib.pyplot as plt
weighted_edges = [("a", "b", 4), ("b", "c", 2), ("a", "c", 5)]


G = nx.Graph()
G.add_weighted_edges_from(weighted_edges)
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=700, font_size=12, font_weight='bold')
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.show()