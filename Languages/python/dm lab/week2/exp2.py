
def forall(domains, predicate):

    return all(predicate(x) for x in domains)
def exists(domains, predicate):

    return any(predicate(x) for x in domains)
def negate_forall(domains, predicate):
    
    return not forall(domains, predicate)
def negate_exists(domains, predicate):
    
    return not exists(domains, predicate)
domain = [0, 1, 2, 3, 4, 5]
predicate1 = lambda x: x**2<=16 
predicate2 = lambda x: x**2==25
print("For all x (x^2 <= 16):", negate_forall(domain, predicate1))
print("There exists x (x^2 == 25):", negate_exists(domain, predicate2))

