import math

def has_solution(a,b,n):
    return b%math.gcd(a,n)==0

print("Does 14x ≡ 30 (mod 100) have a solution?",has_solution(14,30,100))
