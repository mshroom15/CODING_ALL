import math 
a ,b = 23 , 12

gcd = math.gcd(a,b)
print(gcd)
def lcm(a,b):
    return (a*b)//math.gcd(a,b)
print(lcm(a,b))




