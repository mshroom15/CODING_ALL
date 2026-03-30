def is_valid(code):
    if code % 4 == 0 and code % 6 == 0:
        return True
    else:
        return False

code = int(input("Enter access code: "))

if is_valid(code):
    print("Access code is valid")
else:
    print("Access code is not valid")