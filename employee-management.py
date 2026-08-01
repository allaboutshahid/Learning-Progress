employees = {}

while True:
    print("\n========= EMPLOYEE MANAGEMENT SYSTEM =========")
    print("1. Add Employee")
    print("2. View Employees")
    print("3. Search Employee")
    print("4. Update Salary")
    print("5. Delete Employee")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        emp_id = input("Enter Employee ID: ")

        if emp_id in employees:
            print("Employee ID already exists!")
        else:
            name = input("Enter Employee Name: ")
            department = input("Enter Department: ")
            salary = float(input("Enter Salary: ₹"))

            employees[emp_id] = {
                "name": name,
                "department": department,
                "salary": salary
            }

            print("Employee Added Successfully!")

    elif choice == "2":
        if not employees:
            print("No Employees Found!")
        else:
            print("\n========== EMPLOYEE LIST ==========")
            for emp_id, details in employees.items():
                print(f"\nEmployee ID : {emp_id}")
                print(f"Name        : {details['name']}")
                print(f"Department  : {details['department']}")
                print(f"Salary      : ₹{details['salary']}")

    elif choice == "3":
        emp_id = input("Enter Employee ID: ")

        if emp_id in employees:
            print("\nEmployee Found")
            print("Name       :", employees[emp_id]["name"])
            print("Department :", employees[emp_id]["department"])
            print("Salary     : ₹", employees[emp_id]["salary"])
        else:
            print("Employee Not Found!")

    elif choice == "4":
        emp_id = input("Enter Employee ID: ")

        if emp_id in employees:
            salary = float(input("Enter New Salary: ₹"))
            employees[emp_id]["salary"] = salary
            print("Salary Updated Successfully!")
        else:
            print("Employee Not Found!")

    elif choice == "5":
        emp_id = input("Enter Employee ID: ")

        if emp_id in employees:
            del employees[emp_id]
            print("Employee Deleted Successfully!")
        else:
            print("Employee Not Found!")

    elif choice == "6":
        print("Thank You!")
        break

    else:
        print("Invalid Choice!")