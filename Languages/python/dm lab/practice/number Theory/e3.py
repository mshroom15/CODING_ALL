
a,b,n=12,23242,26

def modular_exponentiation(a,b,n):
    result =1
    a=a%n
    while b>0:
        if b%2==1:
            result= (result*a)%n
        a = (a*a)%n
        b=b//2
    return result

print(modular_exponentiation(a,b,n))