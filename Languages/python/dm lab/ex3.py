
weighted_edges = [("a", "b", 4), ("b", "c", 2), ("a", "c", 5)]
weighted_graph = {}
for v, u, w in weighted_edges:
    weighted_graph.setdefault(v, []).append((u, w))
    weighted_graph.setdefault(u, []).append((v, w))
for node , adj in weighted_graph.items():
    print(f"{node} -> {adj}")    