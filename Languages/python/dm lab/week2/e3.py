
def forall(domains, predicate):

    return all(predicate(x) for x in domains)
def exists(domains, predicate):

    return any(predicate(x) for x in domains)
def negate_forall(domains, predicate):
    
    return not forall(domains, predicate)
def negate_exists(domains, predicate):
    
    return not exists(domains, predicate)
def forall_and_exists(domains, predicate_p, predicate_q):
    return forall(domains, predicate_p) and exists(domains, predicate_q)



domain1 = [1, 2, 3, 4, 5]
predicate1 = lambda x: x > 3 

print("Example 1: P(x) = 'x > 3'")
print(f"Domain: {domain1}")
print(f"¬(∀xP(x)) = {negate_forall(domain1, predicate1)}")
print(f"∃x(¬P(x)) = {exists(domain1, lambda x: not predicate1(x))}")
    

domain2 = [2, 4, 6, 8]
predicate2 = lambda x: x % 2 == 0 

print("Example 2: P(x) = 'x is even'")
print(f"Domain: {domain2}")
print(f"¬(∀xP(x)) = {negate_forall(domain2, predicate2)}")
print(f"∃x(¬P(x)) = {exists(domain2, lambda x: not predicate2(x))}")
