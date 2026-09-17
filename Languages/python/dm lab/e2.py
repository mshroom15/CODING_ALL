directed_vetices = ["a", "b", "c"]
directed_edges = [("a", "b"), ("b", "c")]
directed_graph = {v: [] for v in directed_vetices}
for v, u in directed_edges:
    directed_graph[v].append(u)
for node, adj in directed_graph.items():
    print(f"{node} -> {adj}")