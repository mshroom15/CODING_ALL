import math
a, b = 36, 60
print("GCD using math.gcd:", math.gcd(a, b))
def lcm(a, b): return abs(a*b) // math.gcd(a, b)
print("LCM:", lcm(a, b))