# Example: Verify the identity (A ∪ B)' = A' ∩ B'.

U = {1, 2, 3, 4, 5, 6}
A = {1, 2, 3}
B = {3, 4, 5}
lhs = U.difference(A.union(B))
rhs = U.difference(A).intersection(U.difference(B))
print("LHS =", lhs)
print("RHS =", rhs)
print("Identity Verified:", lhs == rhs)