import json
import os
from datetime import datetime

DATA_FILE = "tasks.json"


class Task:
    def __init__(self, title, completed=False, created_at=None):
        self.title = title
        self.completed = completed
        self.created_at = created_at or datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    def to_dict(self):
        return {
            "title": self.title,
            "completed": self.completed,
            "created_at": self.created_at,
        }

    @classmethod
    def from_dict(cls, data):
        return cls(
            title=data["title"],
            completed=data["completed"],
            created_at=data["created_at"],
        )


class TodoManager:
    def __init__(self):
        self.tasks = []
        self.load_tasks()

    def load_tasks(self):
        if os.path.exists(DATA_FILE):
            with open(DATA_FILE, "r") as file:
                try:
                    data = json.load(file)
                    self.tasks = [Task.from_dict(item) for item in data]
                except json.JSONDecodeError:
                    self.tasks = []

    def save_tasks(self):
        with open(DATA_FILE, "w") as file:
            json.dump([task.to_dict() for task in self.tasks], file, indent=4)

    def add_task(self, title):
        self.tasks.append(Task(title))
        self.save_tasks()
        print("Task added successfully.")

    def list_tasks(self):
        if not self.tasks:
            print("\nNo tasks available.\n")
            return

        print("\n===== TASK LIST =====")
        for index, task in enumerate(self.tasks, start=1):
            status = "✔" if task.completed else "✘"
            print(
                f"{index}. [{status}] {task.title} "
                f"(Created: {task.created_at})"
            )
        print()

    def complete_task(self, index):
        if 0 <= index < len(self.tasks):
            self.tasks[index].completed = True
            self.save_tasks()
            print("Task marked as completed.")
        else:
            print("Invalid task number.")

    def delete_task(self, index):
        if 0 <= index < len(self.tasks):
            removed = self.tasks.pop(index)
            self.save_tasks()
            print(f"Deleted: {removed.title}")
        else:
            print("Invalid task number.")

    def search_task(self, keyword):
        results = [
            task for task in self.tasks
            if keyword.lower() in task.title.lower()
        ]

        if not results:
            print("No matching tasks found.")
            return

        print("\nSearch Results:")
        for task in results:
            status = "Completed" if task.completed else "Pending"
            print(f"- {task.title} ({status})")

    def statistics(self):
        total = len(self.tasks)
        completed = sum(task.completed for task in self.tasks)
        pending = total - completed

        print("\n===== STATISTICS =====")
        print(f"Total Tasks     : {total}")
        print(f"Completed Tasks : {completed}")
        print(f"Pending Tasks   : {pending}")
        if total:
            print(f"Completion Rate : {(completed/total)*100:.2f}%")
        print()


def menu():
    print("""
==============================
      TODO LIST MANAGER
==============================
1. Add Task
2. View Tasks
3. Complete Task
4. Delete Task
5. Search Task
6. Statistics
7. Exit
""")


def main():
    manager = TodoManager()

    while True:
        menu()

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            title = input("Task title: ").strip()
            if title:
                manager.add_task(title)
            else:
                print("Task title cannot be empty.")

        elif choice == "2":
            manager.list_tasks()

        elif choice == "3":
            manager.list_tasks()
            try:
                index = int(input("Task number: ")) - 1
                manager.complete_task(index)
            except ValueError:
                print("Please enter a valid number.")

        elif choice == "4":
            manager.list_tasks()
            try:
                index = int(input("Task number: ")) - 1
                manager.delete_task(index)
            except ValueError:
                print("Please enter a valid number.")

        elif choice == "5":
            keyword = input("Search keyword: ").strip()
            manager.search_task(keyword)

        elif choice == "6":
            manager.statistics()

        elif choice == "7":
            print("Goodbye!")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()