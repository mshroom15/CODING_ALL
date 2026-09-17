import math
def euclid_gcd(a, b):
    while b:
        temp =b
        b = a%b
        a = temp
    return a
a, b = 60, 12

print(f"gcd = {euclid_gcd(a,b)}")
