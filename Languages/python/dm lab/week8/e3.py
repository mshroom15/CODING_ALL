import math

def has_unique_solution(a,n):
    return math.gcd(a,n)==1
print("Does 7x ≡ 1 (mod 26) have a unique solution?",has_unique_solution(7,26))