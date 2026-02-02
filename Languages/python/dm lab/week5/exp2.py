def fib_recursive(n):
    if n <= 1: return n
    return fib_recursive(n-1) + fib_recursive(n-2)
print("Fibonacci (recursive):", [fib_recursive(i) for i in range(10)])

def fib_iterative(n):
    seq = [0,1]
    for i in range(2, n): seq.append(seq[-1] + seq[-2])
    return seq[:n]
print("Fibonacci (iterative):", fib_iterative(10))