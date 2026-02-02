import matplotlib.pyplot as plt

def fib_iterative(n):
    seq = [0,1]
    for i in range(2, n): seq.append(seq[-1] + seq[-2])
    return seq[:n]

n = range(10)
fib = fib_iterative(10)
plt.plot(n, fib, marker='o')
plt.title("Fibonacci Sequence Visualization")
plt.xlabel("n")
plt.ylabel("Fibonacci(n)")
plt.grid(True)
plt.show()