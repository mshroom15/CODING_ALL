vertices = ["a", "b", "c"]
edges = [("a", "b"), ("b", "c")]
graph = {v: [] for v in vertices}
for v,u in edges:
    graph[v].append(u)
    graph[u].append(v)
for v in vertices:
    print(f"{v} -> [{', '.join(graph[v])}]")