limit = int(input("Enter the upper limit for the number guesser: "))
import random
number_to_guess = random.randint(1, limit)
attempts = 0
print(f"Guess a number between 1 and {limit}.")
while True:
    guess = int(input("Enter your guess: "))
    attempts += 1
    if guess < number_to_guess:
        print("Too low! Try again.")
    elif guess > number_to_guess:
        print("Too high! Try again.")
    else:
        print(f"Congratulations! You've guessed the number {number_to_guess} in {attempts} attempts.")
        break
