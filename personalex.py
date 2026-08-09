# Python — Medium: Personal Expense Analyzer
# Runs directly in IDLE, VS Code, PyCharm, or any Python editor.

import json
import os
from datetime import datetime

FILE_NAME = "expenses.json"


def load_expenses():
    if not os.path.exists(FILE_NAME):
        return []

    try:
        with open(FILE_NAME, "r") as file:
            return json.load(file)
    except (json.JSONDecodeError, OSError):
        return []


def save_expenses(expenses):
    with open(FILE_NAME, "w") as file:
        json.dump(expenses, file, indent=4)


def add_expense(expenses):
    print("\n--- Add Expense ---")

    title = input("Description: ").strip()

    if not title:
        print("Description cannot be empty.")
        return

    try:
        amount = float(input("Amount: "))
    except ValueError:
        print("Invalid amount.")
        return

    category = input(
        "Category (food/travel/shopping/bills/other): "
    ).strip().lower()

    expense = {
        "id": len(expenses) + 1,
        "title": title,
        "amount": amount,
        "category": category,
        "date": datetime.now().strftime("%Y-%m-%d")
    }

    expenses.append(expense)
    save_expenses(expenses)

    print("Expense added successfully.")


def show_expenses(expenses):
    if not expenses:
        print("\nNo expenses found.")
        return

    print("\n" + "=" * 70)
    print(f"{'ID':<5}{'Description':<25}"
          f"{'Category':<15}{'Amount':>10}{'Date':>15}")
    print("=" * 70)

    for expense in expenses:
        print(
            f"{expense['id']:<5}"
            f"{expense['title'][:23]:<25}"
            f"{expense['category']:<15}"
            f"₹{expense['amount']:>9.2f}"
            f"{expense['date']:>15}"
        )

    print("=" * 70)


def total_expenses(expenses):
    total = sum(
        expense["amount"]
        for expense in expenses
    )

    print(f"\nTotal spending: ₹{total:.2f}")


def category_report(expenses):
    if not expenses:
        print("\nNo data available.")
        return

    categories = {}

    for expense in expenses:
        category = expense["category"]

        categories[category] = (
            categories.get(category, 0)
            + expense["amount"]
        )

    print("\n--- Category Report ---")

    for category, amount in sorted(
        categories.items(),
        key=lambda item: item[1],
        reverse=True
    ):
        print(f"{category:<15} ₹{amount:.2f}")


def search_expenses(expenses):
    query = input("\nSearch description: ").strip().lower()

    results = [
        expense
        for expense in expenses
        if query in expense["title"].lower()
    ]

    if not results:
        print("No matching expenses.")
        return

    show_expenses(results)


def delete_expense(expenses):
    try:
        expense_id = int(
            input("\nEnter expense ID to delete: ")
        )
    except ValueError:
        print("Invalid ID.")
        return

    for expense in expenses:
        if expense["id"] == expense_id:
            expenses.remove(expense)

            # Re-number IDs
            for index, item in enumerate(expenses, 1):
                item["id"] = index

            save_expenses(expenses)

            print("Expense deleted.")
            return

    print("Expense not found.")


def main():
    expenses = load_expenses()

    while True:
        print("\n")
        print("=" * 35)
        print("     PERSONAL EXPENSE ANALYZER")
        print("=" * 35)
        print("1. Add Expense")
        print("2. View Expenses")
        print("3. Total Spending")
        print("4. Category Report")
        print("5. Search Expense")
        print("6. Delete Expense")
        print("7. Exit")
        print("=" * 35)

        choice = input("Choose: ").strip()

        if choice == "1":
            add_expense(expenses)

        elif choice == "2":
            show_expenses(expenses)

        elif choice == "3":
            total_expenses(expenses)

        elif choice == "4":
            category_report(expenses)

        elif choice == "5":
            search_expenses(expenses)

        elif choice == "6":
            delete_expense(expenses)

        elif choice == "7":
            print("\nData saved. Goodbye!")
            break

        else:
            print("Invalid option.")


if __name__ == "__main__":
    main()