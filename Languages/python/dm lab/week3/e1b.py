U={1,2,3,4,5,6}
A={1,2}
B={2,3}
left=U - (A.union(B))
right=(U-A).intersection(U-B)
print("Identity (b) holds:", left==right)
