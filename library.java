import java.util.ArrayList;
import java.util.Scanner;

class Book {
    private int id;
    private String title;
    private String author;
    private boolean issued;

    public Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.issued = false;
    }

    public int getId() {
        return id;
    }

    public boolean isIssued() {
        return issued;
    }

    public void issueBook() {
        issued = true;
    }

    public void returnBook() {
        issued = false;
    }

    public void display() {
        System.out.println("--------------------------------");
        System.out.println("Book ID     : " + id);
        System.out.println("Title       : " + title);
        System.out.println("Author      : " + author);
        System.out.println("Status      : " +
                (issued ? "Issued" : "Available"));
        System.out.println("--------------------------------");
    }
}

public class LibraryManagementSystem {

    static Scanner scanner = new Scanner(System.in);
    static ArrayList<Book> books = new ArrayList<>();

    static void addBook() {
        System.out.print("\nEnter Book ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter Book Title: ");
        String title = scanner.nextLine();

        System.out.print("Enter Author Name: ");
        String author = scanner.nextLine();

        books.add(new Book(id, title, author));

        System.out.println("\nBook added successfully!");
    }

    static Book findBook(int id) {
        for (Book book : books) {
            if (book.getId() == id) {
                return book;
            }
        }

        return null;
    }

    static void displayBooks() {
        if (books.isEmpty()) {
            System.out.println("\nNo books available.");
            return;
        }

        System.out.println("\n========== LIBRARY BOOKS ==========");

        for (Book book : books) {
            book.display();
        }
    }

    static void issueBook() {
        System.out.print("\nEnter Book ID: ");
        int id = scanner.nextInt();

        Book book = findBook(id);

        if (book == null) {
            System.out.println("Book not found.");
            return;
        }

        if (book.isIssued()) {
            System.out.println("Book is already issued.");
            return;
        }

        book.issueBook();

        System.out.println("Book issued successfully.");
    }

    static void returnBook() {
        System.out.print("\nEnter Book ID: ");
        int id = scanner.nextInt();

        Book book = findBook(id);

        if (book == null) {
            System.out.println("Book not found.");
            return;
        }

        if (!book.isIssued()) {
            System.out.println("Book is already available.");
            return;
        }

        book.returnBook();

        System.out.println("Book returned successfully.");
    }

    static void searchBook() {
        System.out.print("\nEnter Book ID: ");
        int id = scanner.nextInt();

        Book book = findBook(id);

        if (book != null) {
            System.out.println("\nBook Found:");
            book.display();
        } else {
            System.out.println("Book not found.");
        }
    }

    public static void main(String[] args) {

        int choice;

        while (true) {
            System.out.println("\n\n========== LIBRARY MANAGEMENT ==========");
            System.out.println("1. Add Book");
            System.out.println("2. Display Books");
            System.out.println("3. Search Book");
            System.out.println("4. Issue Book");
            System.out.println("5. Return Book");
            System.out.println("6. Exit");
            System.out.println("========================================");

            System.out.print("Enter Choice: ");
            choice = scanner.nextInt();

            switch (choice) {

                case 1:
                    addBook();
                    break;

                case 2:
                    displayBooks();
                    break;

                case 3:
                    searchBook();
                    break;

                case 4:
                    issueBook();
                    break;

                case 5:
                    returnBook();
                    break;

                case 6:
                    System.out.println("\nThank you for using the system!");
                    scanner.close();
                    return;

                default:
                    System.out.println("\nInvalid choice!");
            }
        }
    }
}