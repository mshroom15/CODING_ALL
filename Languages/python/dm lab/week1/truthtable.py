import itertools
def truth_table(expr, vars):
    print("|".join(vars)+"| Result |")      
    for values in itertools.product([False, True], repeat=len(vars)):
        env = dict(zip(vars, values))
        print("|".join(str(env[var]) for var in vars)+"| "+str(eval(expr, {}, env))+" |")
truth_table("(p and q) or (not p)",["p","q"])
def equivalnt(expr1, expr2, vars):
    for values in itertools.product([False, True], repeat = len(vars)):
        env = dict(zip(vars, values))   
        if eval(expr1,{},env) != eval(expr2,{},env):
            return False
    return True
print(equivalnt("p and (q or r)","(p and q) or (p and r)",["p","q","r"]))