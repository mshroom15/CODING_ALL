
def forall(domains, predicate):

    return all(predicate(x) for x in domains)
def exists(domains, predicate):

    return any(predicate(x) for x in domains)
def negate_forall(domains, predicate):
    
    return not forall(domains, predicate)
def negate_exists(domains, predicate):
    
    return not exists(domains, predicate)