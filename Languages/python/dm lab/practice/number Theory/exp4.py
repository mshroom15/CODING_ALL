a,b,n=17,5,12
print((a+b)%n)
print((a-b)%n)
print((a*b)%n)
def congruence(a,b,n):
    return (a-b)%n==0
print(congruence(a,b,n))