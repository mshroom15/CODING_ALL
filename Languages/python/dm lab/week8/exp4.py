def verify_congruence(a, x, b, n): return (a * x - b) % n == 0
print("Verification:", verify_congruence(7, 23, 5, 26))