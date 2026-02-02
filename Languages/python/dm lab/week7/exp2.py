def gcd_euclid(a, b):
    while b: a, b = b, a % b
    return a
print("GCD(48,18) =", gcd_euclid(48,18))