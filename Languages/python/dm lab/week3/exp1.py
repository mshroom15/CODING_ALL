A = {1, 2, 3}
B = {3, 4, 5}
U = {1, 2, 3, 4, 5, 6}
print("A union B =", A.union(B))
print("A intersection B =", A.intersection(B))
print("A - B =", A.difference(B))
print("A symmetric_difference B =", A.symmetric_difference(B))
print("Complement of A =", U.difference(A))