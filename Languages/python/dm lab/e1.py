vertices = ["a", "b", "c"]
edges = [("a", "b"), ("b", "c")]
matrix = [[0 for _ in vertices] for _ in vertices]
for v,u in edges:
    i = vertices.index(v)
    j = vertices.index(u)
    matrix[i][j] = 1
    matrix[j][i] = 1
n=len(vertices)

def matrix_to_list(matrix):
    graph = {v: [] for v in vertices}
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 1:
                graph[vertices[i]].append(vertices[j])
    return graph
graph = matrix_to_list(matrix)
for node , adj in graph.items():
    print(f"{node} -> {adj}")