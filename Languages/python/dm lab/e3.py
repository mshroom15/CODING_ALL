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

vertices.append("d")
for row in matrix:
    row.append(0)
matrix.append([0 for _ in vertices])
graph["d"] = []
for v , adj in graph.items():
    print(f"{v} -> [{', '.join(adj)}]")
for row in matrix:
    print(row)
        