import math
def sieve(n):
    prime = [True] * (n+1)
    prime[0] = prime[1] = False
    for i in range(2, int(math.sqrt(n))+1):
        if prime[i]:
            for j in range(i*i, n+1, i):
                prime[j] = False
    return [i for i in range(2, n+1) if prime[i]]
n = 30
print(sieve(n))
def copirime(a,b):
    return math.gcd(a,b)==1
print(copirime(15,28))

def twin_primes(n):
    primes = sieve(n)
    twin_primes = []
    for i in range(len(primes)-1):
        if primes[i+1] - primes[i] == 2:
            twin_primes.append((primes[i], primes[i+1]))
    return twin_primes
print(twin_primes(n))
def prime_diff(n):
    primes = sieve(n)
    diff = []
    for i in range(len(primes)-1):
        diff.append(primes[i+1] - primes[i])
    return diff
print(prime_diff(n))

def mod_ex(a,b,n):
    result =1
    a = a%n
    while b:
        if b%2==1:
            result = (result*a)%n
        a = (a*a)%n
        b=b//2

    return result
print(mod_ex(5,3,21))
def ext_euc(a,b):
    if b==0:
        return a , 1,0
    g,x1,y1=ext_euc(b,a%b)
    x=y1
    y=x1-(a//b)*y1
    return g,x,y
def inverse(a,n):
    g,x,y=ext_euc(a,n)
    if g!=1:
        return False
    else:
        return x%n
def check_sol(a,b,n):return b%math.gcd(a,n)==0

def solve(a,b,n):
    g,x,y = ext_euc(a,n)
    if b%math.gcd(a,n)!=0:
        return False
    else:
        x0=(x*b//g)%n
        return [(x0+ i*(n//g)%n) for i in range(g)]
print (solve(14,30,100))
inv =inverse(7,26)
x = (inv*5)%26
print(x)

def verify(a,x,b,n):
    return (a*x-b)%n==0
print(verify(7,23,5,26))

print("e2: ",solve(9,15,24))
def crt(a,m):
    M=1
    for mi in m:
        M*=mi
    x=0
    for ai,mi in zip(a,m):
        Mi=M//mi
        yi=inverse(Mi,mi)
        x+=ai*Mi*yi
    return x%M
a=[2,3,2]
m=[3,5,7]
print(crt(a,m)) 
