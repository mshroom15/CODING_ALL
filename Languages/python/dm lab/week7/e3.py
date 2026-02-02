def mod_exp(a,b,n):
    result=1
    a=a%n
    while b>0:
        if b%2==1:
            result=(result*a)%n
        a=(a*a)%n
        b//=2
    return result
print("Modular Exponentiation: 5^3 mod 13 =", mod_exp(5,3,13))