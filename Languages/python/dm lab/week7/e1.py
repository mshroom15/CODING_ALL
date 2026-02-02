def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a

def gcd_three(a,b,c):
    return gcd(gcd(a,b),c)
print("GCD of 48,18,30 is:",gcd_three(48,18,30))
