expenses = []

while True:
    print("\n===== Expense Tracker =====")
    print("1. Add Expense")
    print("2. View Expenses")
    print("3. Show Total Expense")
    print("4. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        item = input("Enter expense name: ")
        amount = float(input("Enter amount: ₹"))
        expenses.append({"item": item, "amount": amount})
        print("✅ Expense added successfully!")

    elif choice == "2":
        if not expenses:
            print("No expenses found.")
        else:
            print("\n----- Expense List -----")
            for i, expense in enumerate(expenses, start=1):
                print(f"{i}. {expense['item']} - ₹{expense['amount']:.2f}")

    elif choice == "3":
        total = sum(expense["amount"] for expense in expenses)
        print(f"\n💰 Total Expense: ₹{total:.2f}")

    elif choice == "4":
        print("Thank you for using Expense Tracker!")
        break

    else:
        print("❌ Invalid choice! Please try again.")