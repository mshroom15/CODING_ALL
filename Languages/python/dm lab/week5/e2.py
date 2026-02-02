def recurrence_an(n):
    seq=[1]
    for i in range(1,n):
        seq.append(3*seq[-1]-2)
    return seq

print("Recurrence Sequence:", recurrence_an(6))
