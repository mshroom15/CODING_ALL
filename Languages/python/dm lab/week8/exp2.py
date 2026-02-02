def extended_gcd(a,b):
    if b==0:
        return a,1,0
    g,x1,y1=extended_gcd(b,a%b)
    x=y1
    y=x1-(a//b)*y1
    return g,x,y

def solve_congruence(a,b,n):
    g,x,y=extended_gcd(a,n)
    if b%g!=0:
        return None
    x0=(x*(b//g))%n
    return [(x0+i*(n//g))%n for i in range(g)]

solutions=solve_congruence(14,30,100)

print("Does 14x ≡ 30 (mod 100) have a solution?",solutions is not None)
print("Solutions:",solutions)
