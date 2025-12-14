def cartesian(A,B):
    return {(a,b) for a in A for b in B}
A={1,2}
B={'x','y'}
print(cartesian(A,B))
