vertices = ["a", "b", "c"]
edges = [("a", "b"), ("b", "c")]
matrix = [[0 for _ in vertices] for _ in vertices]
for v,u in edges:
    i = vertices.index(v)
    j = vertices.index(u)
    matrix[i][j] = 1
    matrix[j][i] = 1
for row in matrix:
    print(row)
