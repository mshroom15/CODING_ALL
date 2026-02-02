def lucas(n):
    seq=[2,1]
    for i in range(2,n):
        seq.append(seq[-1]+seq[-2])
    return seq[:n]

print("Lucas numbers:",lucas(10))
