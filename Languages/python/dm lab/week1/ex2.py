import itertools

def equivalnt(expr1, expr2, vars):
    for values in itertools.product([False, True], repeat = len(vars)):
        env = dict(zip(vars, values))   
        if eval(expr1,{},env) != eval(expr2,{},env):
            return False
    return True
print(equivalnt("(p or q) and ((not p) or q)","q",["p","q"]))