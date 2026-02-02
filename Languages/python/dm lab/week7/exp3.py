def extended_gcd(a, b):
    if b == 0: return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y
def mod_inverse(a, n):
    g, x, y = extended_gcd(a, n)
    if g != 1: raise ValueError("Inverse does not exist.")
    else: return x % n
a, n = 7, 26
print("Modular Inverse of 7 mod 26 =", mod_inverse(a, n))