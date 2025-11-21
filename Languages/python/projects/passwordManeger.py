from cryptography.fernet import Fernet, InvalidToken
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives import hashes
import base64, os

# Persistent salt (created once)
SALT_FILE = "salt.bin"
if not os.path.exists(SALT_FILE):
    with open(SALT_FILE, "wb") as sf:
        sf.write(os.urandom(16))
with open(SALT_FILE, "rb") as sf:
    salt = sf.read()

def derive_key(master_password: str, salt: bytes) -> bytes:
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        length=32,
        salt=salt,
        iterations=390000,
    )
    return base64.urlsafe_b64encode(kdf.derive(master_password.encode()))

master_input = input("Enter the master password: ")
master_key = derive_key(master_input, salt)
cipher_suite = Fernet(master_key)



def check_password_strength(password):    
    length=len(password)
    Isupper=any(c.isupper() for c in password)
    Islower=any(c.islower() for c in password)
    Isdigit=any(c.isdigit() for c in password)
    Isspecial= any(c in "!@#$%^&*()-+" for c in password)
    if length < 8:
        return "Weak"
    if not (Isupper and Islower and Isdigit and Isspecial):
        return "Moderate"
    return "Strong"

def add_password():
    while True:
        username = input("Enter username: ")
        password = input("Enter a password to add: ")
        strength = check_password_strength(password)
        print(f"Password strength: {strength}")
        if strength == "Weak":
            print("Tips to improve your password:")
            print("- Use at least 8 characters.")
            print("- Include both uppercase and lowercase letters.")
            print("- Add numbers and special characters.")
            continue
        if strength == "Moderate":
            print("Tips to improve your password:")
            print("- Make it longer than 8 characters.")
            print("- Ensure it has a mix of uppercase, lowercase, numbers, and special characters.")
            continue
        if strength == "Strong":
            print("Your password is strong.")
            encrypted = cipher_suite.encrypt(password.encode()).decode()
            with open("passwords.txt", "a") as f:
                f.write(f"{username}:{encrypted}\n")
            return

while True:
    user_input = input("Enter 'add', 'view' (or 'exit' to quit): ").lower()
    if user_input == 'exit':
        break
    if user_input == "add":
        add_password()
    elif user_input == "view":
        try:
            with open("passwords.txt", "r") as f:
                passwords = f.readlines()
                for line in passwords:
                    user, enc_password = line.strip().split(":")
                    try:
                        decrypted = cipher_suite.decrypt(enc_password.encode()).decode()
                        print(f"User: {user}, Password: {decrypted}")
                    except InvalidToken:
                        print(f"User: {user}, Password: <cannot decrypt with this master password>")
        except FileNotFoundError:
            print("No passwords stored yet.")
    else:
        print("Invalid option. Please type 'add', 'view', or 'exit'.")

