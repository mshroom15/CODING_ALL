A={1,2,3}
B={3,4}
C={2,5}
left=A.intersection(B.union(C))
right=A.intersection(B).union(A.intersection(C))
print("Identity (a) holds:", left==right)
