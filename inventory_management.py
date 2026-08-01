inventory = {}

while True:
    print("\n========== INVENTORY MANAGEMENT SYSTEM ==========")
    print("1. Add Product")
    print("2. View Products")
    print("3. Search Product")
    print("4. Update Product Quantity")
    print("5. Delete Product")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        product_id = input("Enter Product ID: ")

        if product_id in inventory:
            print("❌ Product ID already exists!")
        else:
            name = input("Enter Product Name: ")
            quantity = int(input("Enter Quantity: "))
            price = float(input("Enter Price: ₹"))

            inventory[product_id] = {
                "name": name,
                "quantity": quantity,
                "price": price
            }

            print("✅ Product Added Successfully!")

    elif choice == "2":
        if not inventory:
            print("No Products Available.")
        else:
            print("\n========== PRODUCT LIST ==========")
            for pid, details in inventory.items():
                print(f"\nProduct ID : {pid}")
                print(f"Name       : {details['name']}")
                print(f"Quantity   : {details['quantity']}")
                print(f"Price      : ₹{details['price']:.2f}")

    elif choice == "3":
        product_id = input("Enter Product ID: ")

        if product_id in inventory:
            details = inventory[product_id]
            print("\nProduct Found!")
            print("Name     :", details["name"])
            print("Quantity :", details["quantity"])
            print("Price    : ₹", details["price"])
        else:
            print("❌ Product Not Found!")

    elif choice == "4":
        product_id = input("Enter Product ID: ")

        if product_id in inventory:
            quantity = int(input("Enter New Quantity: "))
            inventory[product_id]["quantity"] = quantity
            print("✅ Quantity Updated Successfully!")
        else:
            print("❌ Product Not Found!")

    elif choice == "5":
        product_id = input("Enter Product ID: ")

        if product_id in inventory:
            del inventory[product_id]
            print("✅ Product Deleted Successfully!")
        else:
            print("❌ Product Not Found!")

    elif choice == "6":
        print("Thank you for using Inventory Management System!")
        break

    else:
        print("❌ Invalid Choice!")