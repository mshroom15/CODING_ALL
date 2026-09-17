vertices = ["a", "b", "c"]
edges = [("a", "b"), ("b", "c")]
matrix = [[0 for _ in vertices] for _ in vertices]
for v,u in edges:
    i = vertices.index(v)
    j = vertices.index(u)
    matrix[i][j] = 1
    matrix[j][i] = 1
graph = {v: [] for v in vertices}
for v,u in edges:
    graph[v].append(u)
    graph[u].append(v)
n=len(vertices)
def matrix_space():
    return n*n
def graph_space():
    return sum(len(adj) for adj in graph.values())
print(f"Adjacency Matrix Space: {matrix_space()}")
print(f"Adjacency List Space: {graph_space()}")