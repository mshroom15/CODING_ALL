def arithmetic_sequence(a1, d, n):
    return [a1 + i*d for i in range(n)]
def summation(seq): return sum(seq)
A = arithmetic_sequence(2,3,5)
print("Sum of Arithmetic Sequence:", summation(A))