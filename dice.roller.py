import random

print("🎲 Welcome to the Dice Roller!")

while True:
    print("\n1. Roll Dice")
    print("2. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        dice = random.randint(1, 6)
        print(f"\n🎲 You rolled: {dice}")

        if dice == 6:
            print("🔥 Awesome! You got a SIX!")
        elif dice == 1:
            print("😅 Better luck next time!")
        else:
            print("😊 Nice roll!")

    elif choice == "2":
        print("Thanks for playing!")
        break

    else:
        print("❌ Invalid choice! Try again.")