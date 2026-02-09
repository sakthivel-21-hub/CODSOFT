#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Define the Structure for a Book
struct Book {
    int id;
    string title;
    string author;
    string isbn;
    bool isAvailable;     // true = in library, false = borrowed
    string borrowerName;  // Stores who took the book
};

// Global vector to store the library books
vector<Book> library;

// --- Helper Functions ---

void addBook() {
    cout << "\n--- Add New Book ---\n";
    
    // We need 3 strings. We use getline for all to allow spaces.
    string t, a, i;
    
    cout << "Enter Book Title: ";
    getline(cin, t);
    
    cout << "Enter Author Name: ";
    getline(cin, a);
    
    cout << "Enter ISBN: ";
    getline(cin, i);
    
    // Auto-generate ID based on current size (ID 1, 2, 3...)
    int newID = library.size() + 1;
    
    // Create the book. Default availability is true. Borrower is empty "".
    Book newBook = {newID, t, a, i, true, ""};
    library.push_back(newBook);
    
    cout << "Book added successfully! Book ID is: " << newID << endl;
}

void searchBook() {
    cout << "\n--- Search Books ---\n";
    cout << "Enter Title, Author, or ISBN to search: ";
    string query;
    getline(cin, query);
    
    bool found = false;
    
    // Loop through all books
    for (int i = 0; i < library.size(); i++) {
        // Check if query matches Title OR Author OR ISBN
        if (library[i].title == query || library[i].author == query || library[i].isbn == query) {
            cout << "\n[FOUND] ID: " << library[i].id << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Status: " << (library[i].isAvailable ? "Available" : "Checked Out") << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No matching books found.\n";
    }
}

void checkOutBook() {
    cout << "\n--- Check Out Book ---\n";
    cout << "Enter Book ID to check out: ";
    int id;
    cin >> id;
    cin.ignore(); // Clear buffer after reading integer
    
    // Validation: Check if ID is valid
    if (id < 1 || id > library.size()) {
        cout << "Invalid Book ID!\n";
        return;
    }
    
    // Access the book (Index is ID - 1)
    // We use a reference (&) so we can modify the original book in the vector
    Book &b = library[id - 1]; 
    
    if (b.isAvailable) {
        cout << "Enter Borrower's Name: ";
        getline(cin, b.borrowerName);
        
        b.isAvailable = false; // Mark as borrowed
        cout << "Book checked out successfully to " << b.borrowerName << "!\n";
    } else {
        cout << "Sorry, this book is currently borrowed by " << b.borrowerName << ".\n";
    }
}

void returnBook() {
    cout << "\n--- Return Book ---\n";
    cout << "Enter Book ID to return: ";
    int id;
    cin >> id;
    
    if (id < 1 || id > library.size()) {
        cout << "Invalid Book ID!\n";
        return;
    }
    
    Book &b = library[id - 1];
    
    if (b.isAvailable) {
        cout << "This book is already in the library. Cannot return it.\n";
    } else {
        // Fine Calculation Logic
        cout << "How many days was the book kept? ";
        int days;
        cin >> days;
        
        int fine = 0;
        int allowedDays = 15; // Standard rule: 15 days free
        
        if (days > allowedDays) {
            int overdueDays = days - allowedDays;
            fine = overdueDays * 1; // Let's say fine is 1 unit (Rupee/Dollar) per day
            cout << "\n!!! BOOK IS OVERDUE !!!\n";
            cout << "Overdue by: " << overdueDays << " days.\n";
            cout << "Total Fine to Pay: " << fine << "\n";
        } else {
            cout << "Returned on time. No fine.\n";
        }
        
        // Reset book status
        b.isAvailable = true;
        b.borrowerName = "";
        cout << "Book returned successfully.\n";
    }
}

// --- Main Program ---
int main() {
    int choice = 0;
    
    // Pre-load some dummy data so you don't have to type it every time
    library.push_back({1, "C++ Basics", "Stroustrup", "12345", true, ""});
    library.push_back({2, "Clean Code", "Uncle Bob", "67890", true, ""});

    while (choice != 5) {
        cout << "\n===============================";
        cout << "\n   LIBRARY MANAGEMENT SYSTEM";
        cout << "\n===============================\n";
        cout << "1. Add New Book\n";
        cout << "2. Search Book\n";
        cout << "3. Check Out Book\n";
        cout << "4. Return Book (Calculate Fine)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear "Enter" key before reading strings
                addBook();
                break;
            case 2:
                cin.ignore(); // Clear "Enter" key
                searchBook();
                break;
            case 3:
                // checkOutBook has cin>> first, so we don't need cin.ignore() here
                // It handles its own buffer internally if needed.
                checkOutBook(); 
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}