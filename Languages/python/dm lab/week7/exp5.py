def check_congruence(a, b, n):
    return (a - b) % n == 0

print("17 \equiv 5 (mod 12)?", check_congruence(17, 5, 12))