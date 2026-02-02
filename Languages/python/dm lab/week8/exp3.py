def extended_gcd(a,b):
    if b==0:
        return a,1,0
    g,x1,y1=extended_gcd(b,a%b)
    x=y1
    y=x1-(a//b)*y1
    return g,x,y

def mod_inverse(a,n):
    g,x,y=extended_gcd(a,n)
    if g!=1:
        raise ValueError("Inverse does not exist")
    return x%n

a,b,n=7,5,26
inv=mod_inverse(a,n)
x=(b*inv)%n

print("Solution of 7x ≡ 5 (mod 26): x =",x)
