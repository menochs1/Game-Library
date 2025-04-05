#include "library.h"
#include <iostream>

using namespace std;

void print_menu() {
    cout << "\nGame Library Menu:\n";
    cout << "1. Add Game\n";
    cout << "2. Delete Game\n";
    cout << "3. Find Game by Title\n";
    cout << "4. Find Games by Genre\n";
    cout << "5. Print All Games\n";
    cout << "6. Load Games from File\n";
    cout << "7. Save Games to File\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Library library;
    int choice;
    string title, publisher, genre;
    float hoursPlayed, price;
    int year;
    string filename;

    // Ask the user to input the filename
    cout << "Enter the filename: ";
    getline(cin, filename);  // Get the filename from the user

    // Load games from file
    library.load_from(filename);

    while (true) {
        print_menu();
        cin >> choice;

        switch (choice) {
            case 1: // Add Game
                cout << "Enter game title: ";
                getline(cin, title);
                cout << "Enter publisher: ";
                getline(cin, publisher);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter hours played: ";
                cin >> hoursPlayed;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter release year: ";
                cin >> year;
                library.insert_sorted(title, publisher, genre, hoursPlayed, price, year);
                cout << "Game added to library.\n";
                break;

            case 2: // Delete Game
                cout << "Enter game title to delete: ";
                getline(cin, title);
                cout << "Enter release year: ";
                cin >> year;
                library.delete_game(title, year);
                cout << "Game deleted.\n";
                break;

            case 3: // Find Game by Title
                cout << "Enter game title to search: ";
                getline(cin, title);
                library.find_game(title);
                break;

            case 4: // Find Games by Genre
                cout << "Enter genre to search: ";
                getline(cin, genre);
                library.find_genre(genre);
                break;

            case 5: // Print All Games
                library.print();
                break;

            case 6: // Load Games from File
                cout << "Loading games from file...\n";
                library.load_from(filename);
                cout << "Games loaded from " << filename << ".\n";
                break;

            case 7: // Save Games to File
                cout << "Saving games to file...\n";
                library.save_to(filename);
                cout << "Games saved to " << filename << ".\n";
                break;

            case 8: // Exit
                cout << "Exiting program.\n";
                library.save_to(filename);  // Save before exiting
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
