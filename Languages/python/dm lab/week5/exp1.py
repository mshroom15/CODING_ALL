def arithmetic_sequence(a1, d, n):
    return [a1 + i*d for i in range(n)]
def geometric_sequence(a1, r, n):
    return [a1 * (r**i) for i in range(n)]
print("Arithmetic Sequence:", arithmetic_sequence(2,3,5))
print("Geometric Sequence:", geometric_sequence(2,2,5))