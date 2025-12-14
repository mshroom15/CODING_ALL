def f(x): return 2*x + 1
def g(x): return x**2
def composition(f, g, domain):
    return [(x, g(f(x))) for x in domain]
domain = [1,2,3,4]
print("Composition g(f(x)):", composition(f, g, domain))