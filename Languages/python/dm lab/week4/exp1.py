def is_function(pairs):
    domain = [x for x, _ in pairs]
    return len(domain) == len(set(domain))
relation1 = [(1, 2), (2, 3), (3, 4)]
relation2 = [(1, 2), (1, 3), (2, 4)]
print(f"R1 is function: {is_function(relation1)}")
print(f"R2 is function: {is_function(relation2)}")