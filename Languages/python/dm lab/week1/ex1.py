import itertools
def truth_table(expr, vars):
    print("|".join(vars)+"| Result |")      
    for values in itertools.product([False, True], repeat=len(vars)):
        env = dict(zip(vars, values))
        print("|".join(str(env[var]) for var in vars)+"| "+str(eval(expr, {}, env))+" |")
truth_table("(not (p and q))or (p or q)",["p","q"])