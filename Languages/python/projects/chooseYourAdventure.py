import os

import google.generativeai as genai

# Configure the Gemini API
genai.configure(api_key="insert api")

# Initialize the model
model = genai.GenerativeModel('gemini-2.5-flash')

def generate_scenario(context, player_action=None):
    """Generate a D&D-style scenario using Gemini AI as the DM."""
    if player_action:
        prompt = f"""You are an experienced Dungeon Master running a D&D adventure.
        
Current situation: {context}
Player action: {player_action}

Describe what happens next in 2-3 paragraphs. Be creative, dramatic, and engaging.
End with presenting the player with 3-4 possible actions they can take.
Format the options as numbered list at the end."""
    else:
        prompt = f"""You are an experienced Dungeon Master starting a new D&D adventure.
        
Create an engaging opening scenario for the player. Set the scene in 2-3 paragraphs.
End with presenting the player with 3-4 possible actions they can take.
Format the options as numbered list at the end."""
    
    response = model.generate_content(prompt)
    return response.text

def main():
    print("=== D&D Adventure with AI Dungeon Master ===\n")
    print("Type 'quit' to exit the game.\n")
    
    # Start the adventure
    context = "A fantasy medieval world"
    scenario = generate_scenario(context)
    print(scenario)
    print("\n" + "="*50 + "\n")
    
    # Game loop
    while True:
        player_input = input("What do you do? (describe your action): ").strip()
        
        if player_input.lower() == 'quit':
            print("\nThanks for playing!")
            break
        
        if not player_input:
            print("Please enter an action.\n")
            continue
        
        # Update context with player action
        context = f"Previous: {scenario}\nPlayer chose: {player_input}"
        
        # Generate next scenario
        print("\n" + "="*50 + "\n")
        scenario = generate_scenario(context, player_input)
        print(scenario)
        print("\n" + "="*50 + "\n")

if __name__ == "__main__":
    main()