def is_injective(pairs):
    images = [y for _, y in pairs]
    return len(images) == len(set(images))
def is_surjective(pairs, codomain):
    images = {y for _, y in pairs}
    return images == set(codomain)
A = [1,2,3]
B = [2,3,4]
relation = [(1,2), (2,3), (3,4)]
print("Bijective:", is_injective(relation) and is_surjective(relation, B))
