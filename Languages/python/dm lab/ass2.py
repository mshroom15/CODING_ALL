a =17
b = 5
n = 12

left = (a + b) % n
right = ((a % n) + (b % n)) % n

print("Left side:", left)
print("Right side:", right)

if left == right :
    print("Verified")
else:
    print("Not verified")
