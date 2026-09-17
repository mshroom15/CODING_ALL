vertices = ["a", "b", "c"]
edges = [("a", "b"), ("b", "c")]
graph = {v: [] for v in vertices}
for v,u in edges:
    graph[v].append(u)
    graph[u].append(v)

def count_edges(graph):
    count = 0
    for adj in graph.values():
        count += len(adj)
    return count // 2
print(count_edges(graph))