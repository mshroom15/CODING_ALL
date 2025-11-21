import random
choices = ["rock", "paper", "scissors"]
user_score = 0
computer_score = 0
while True:
    user_choice = input("Please Choose between Rock,Paper or Scissors (or quit to exit)").lower()
    if user_choice == "quit":
        print("Thank you for playing")
        break   
    elif user_choice not in choices:
        print ("Invalid , Please give a valid input")   
        continue
    computer_choice=random.choice(choices) 
    print(f"The computer chose {computer_choice}") 
    if user_choice == computer_choice:
        print("Tied!")
    elif (user_choice == "rock" and computer_choice == "scissors") or (user_choice == "paper" and computer_choice == "rock") or (user_choice == "scissors" and computer_choice == "paper") :
        print("you won")
        user_score+=1
    else:
        print("computer won")
        computer_score+=1
print(f"Scores => You: {user_score}, Computer: {computer_score}")