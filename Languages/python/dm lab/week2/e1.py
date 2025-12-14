

def forall(domains, predicate):

    return all(predicate(x) for x in domains)
def exists(domains, predicate):

    return any(predicate(x) for x in domains)
def negate_forall(domains, predicate):
    
    return not forall(domains, predicate)
def negate_exists(domains, predicate):
    
    return not exists(domains, predicate)
domaina = range(0, 101, 2) 
print(f"(a) All even numbers are divisible by 2: {forall(domaina, lambda x: x % 2 == 0)}")
domainb = range(1, 101)
print(f"(b) There exists a number divisible by 3 and 5: {exists(domainb, lambda x: x % 3 == 0 and x % 5 == 0)}")