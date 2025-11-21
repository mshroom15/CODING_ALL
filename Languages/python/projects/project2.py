import random  
def player_turn(player_id):
    score = 0
    roll = random.randint(1, 6)
    print(f"Player {player_id} rolled a {roll}")
    while roll != 1:
        score += roll
        choice = input(f"Player {player_id}, your current score is {score}. Do you want to 'roll' again or 'hold'? ").lower()
        if choice == 'hold':
            break
        roll = random.randint(1, 6)
        print(f"Player {player_id} rolled a {roll}")
    if roll == 1:
        print(f"Player {player_id} rolled a 1 and loses all points this turn!")
        score = 0
    return score
    


player_num=int(input("Enter the number of players: "))
scores=[0]*player_num
winning_score=100
while True:
    for i in range(player_num):
        print(f"\nPlayer {i+1}'s turn:")
        turn_score = player_turn(i+1)
        scores[i] += turn_score
        print(f"Player {i+1}'s total score is now {scores[i]}")
        if scores[i] >= winning_score:
            print(f"Player {i+1} wins with a score of {scores[i]}!")
            exit()
         