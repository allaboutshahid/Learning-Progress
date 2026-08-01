contacts = {}

while True:
    print("\n===== CONTACT BOOK =====")
    print("1. Add Contact")
    print("2. View Contacts")
    print("3. Search Contact")
    print("4. Delete Contact")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter Name: ")
        phone = input("Enter Phone Number: ")

        if name in contacts:
            print("Contact already exists!")
        else:
            contacts[name] = phone
            print("✅ Contact Added Successfully!")

    elif choice == "2":
        if not contacts:
            print("No contacts available.")
        else:
            print("\n----- CONTACT LIST -----")
            for name, phone in contacts.items():
                print(f"Name : {name}")
                print(f"Phone: {phone}")
                print("-" * 25)

    elif choice == "3":
        name = input("Enter Name to Search: ")

        if name in contacts:
            print(f"Name : {name}")
            print(f"Phone: {contacts[name]}")
        else:
            print("❌ Contact Not Found!")

    elif choice == "4":
        name = input("Enter Name to Delete: ")

        if name in contacts:
            del contacts[name]
            print("✅ Contact Deleted!")
        else:
            print("❌ Contact Not Found!")

    elif choice == "5":
        print("Thank you for using Contact Book!")
        break

    else:
        print("❌ Invalid Choice!")