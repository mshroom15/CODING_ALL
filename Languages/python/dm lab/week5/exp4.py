
def recurrence(a0, n):
    seq = [a0]
    for i in range(1, n): seq.append(2 * seq[-1])
    return seq
print("Recurrence Sequence:", recurrence(1,6))