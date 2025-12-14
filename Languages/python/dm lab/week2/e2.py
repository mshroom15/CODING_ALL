
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
