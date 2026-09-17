import networkx as nx
import matplotlib.pyplot as plt

vertices =["A","B","C","D"]
edges = [("A","B"),("A","C"),("B","D"),("C","D")]
weight = {("A","B", 2), ("A","C", 3), ("B","D", 1), ("C","D", 4)}
n = len(vertices)   
matrix = [[0]*n for _ in range(n)]
for v,u in edges:
    i,j=vertices.index(v),vertices.index(u)
    matrix[i][j],matrix[j][i]=1,1
for row in matrix:
    print(row)

graph={v:[] for v in vertices}
for v,u in edges:
    graph[v].append(u)
    graph[u].append(v)
for row in graph:
    print(f"{row} -> {graph[row]}")

weight_graph={v:[] for v in vertices}
for v,u,w in weight:
    weight_graph[v].append((u,w))
    weight_graph[u].append((v,w))
for row in weight_graph:
    print(f"{row} -> {weight_graph[row]}")
g=nx.Graph()
g.add_weighted_edges_from(weight)
pos=nx.spring_layout(g)

nx.draw(g,pos,with_labels=True)
plt.show()

def add_vertex(v):
    global vertices, matrix, graph, weight_graph
    if v not in vertices:
        vertices.append(v)
        n = len(vertices)
        for row in matrix:
            row.append(0)
        matrix.append([0] * n)
        graph[v] = []
        weight_graph[v] = []

def add_edge(v, u, w=None):
    global vertices, matrix, edges, graph, weight_graph, weight
    if v not in vertices:
        add_vertex(v)
    if u not in vertices:
        add_vertex(u)
    
    if (v, u) not in edges and (u, v) not in edges:
        edges.append((v, u))
        i, j = vertices.index(v), vertices.index(u)
        matrix[i][j], matrix[j][i] = 1, 1
        graph[v].append(u)
        graph[u].append(v)
        
        if w is not None:
            weight.add((v, u, w))
            weight_graph[v].append((u, w))
            weight_graph[u].append((v, w))

