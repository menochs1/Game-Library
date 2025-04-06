/**                                                                                                  
 * @file library.cpp                                                                                 
 * @brief Implementation for the Library class                                                       
 *                                                                                                   
 * Operations for inserting, deleting, finding, printing, and saving/loading games.                  
 *                                                                                                   
 * @author Jalen Jones, Mason E                                                                      
 * @date 4/3/2025                                                                                    
 */                                                                                                  
                                                                                                     
#include "Library.h"                                                                                 
#include "Game.h"                                                                                    
#include <iostream>                                                                                  
#include <fstream>                                                                                   
#include <list>                                                                                      
#include <sstream>                                                                                   
                                                                                                     
using namespace std;                                                                                 
                                                                                                     
/**                                                                                                  
 * @class Library                                                                                    
 * @brief A game library manager using a sorted list.                                                
 *                                                                                                   
 * This class allows users to add, remove, search, display, and persist                              
 * a collection of games using a `std::list` as the underlying data structure.                       
 */                                                                                                  
                                                                                                     
/**                                                                                                  
 * @brief Constructs an empty Library.                                                               
 */                                                                                                  
Library::Library() {}                                                                                
                                                                                                     
/**                                                                                                  
 * @brief Destructor for Library.                                                                    
 */                                                                                                  
Library::~Library() {}                                                                               
                                                                                                     
/**                                                                                                  
 * @brief Inserts a new game into the library in sorted order by title.                              
 *                                                                                                   
 * @param title Game title                                                                           
 * @param publisher Game publisher                                                                   
 * @param genre Game genre                                                                           
 * @param hoursPlayed Hours played                                                                   
 * @param price Game price                                                                           
 * @param year Release year                                                                          
 */                                                                                                  
void Library::insert_sorted(string title, string publisher, string genre, float hoursPlayed, float p\
rice, int year) {                                                                                    
    Game newGame;                                                                                    
    newGame.title = title;             // Set the title of the new game                              
    newGame.publisher = publisher;     // Set the publisher
    newGame.genre = genre;             // Set the genre                                              
    newGame.hoursPlayed = hoursPlayed; // Set hours played                                           
    newGame.price = price;             // Set the price                                              
    newGame.year = year;               // Set the year of release                                    
                                                                                                     
    // If the list is empty, insert the new game                                                     
    if (games.empty()) {                                                                             
        games.push_front(newGame);                                                                   
        return;                                                                                      
    }                                                                                                
                                                                                                     
    // Traverse the list to find the correct sorted position                                         
    for (auto it = games.begin(); it != games.end(); ++it) {                                         
        if (it->title > newGame.title) {  // Compare titles                                          
            games.insert(it, newGame);    // Insert before the first title that is greater           
            return;                                                                                  
        }                                                                                            
    }                                                                                                
                                                                                                     
    // If no larger title is found, add the new game to the end                                      
    games.push_back(newGame);                                                                        
}

/**                                                                                                  
 * @brief Deletes a game from the library based on title and year.                                   
 *                                                                                                   
 * @param title Game title to delete                                                                 
 * @param year Release year of the game                                                              
 */                                                                                                  
void Library::delete_game(string title, int year) {                                                  
    // Iterate through the list of games                                                             
    for (auto it = games.begin(); it != games.end(); it++) {                                         
                                                                                                     
        // Check if the current game's title and year match                                          
        if (it->title == title && it->year == year) {                                                
            it = games.erase(it); // Delete the game and update iterator                             
            return;                                                                                  
                                                                                                     
        }  else {                                                                                    
            it++; // Move to the next element if none match                                          
        }                                                                                            
    }                                                                                                
}

/**                                                                                                  
 * @brief Searches for a game by the title.                                                          
 *                                                                                                   
 * @param title Title to search for                                                                  
 */                                                                                                  
void Library::find_game(string title) {                                                              
    bool found = false;  // Track if a matching game was found                                       
                                                                                                     
    // Loop through each game in the list                                                            
    for (const auto& game : games) {                                                                 
        // Check if the game's title matches                                                         
        if (game.title == title) {                                                                   
            // If match, display all the details of the game                                         
            cout << "Title: " << game.title << "\n"                                                  
                << "Publisher: " << game.publisher << "\n"                                           
                << "Genre: " << game.genre << "\n"                                                   
                << "Hours Played: " << game.hoursPlayed << "\n"                                      
                << "Price: $" << game.price << "\n"                                                  
                << "Year: " << game.year << "\n";                                                    
            found = true;                                                                            
        }                                                                                            
    }                                                                                                
                                                                                                     
    // If no game with the title was found, print                                                    
    if (!found) {                                                                                    
        cout << title << " not found!" << "\n";                                                      
    }                                                                                                
}

**                                                                                                  
 * @brief Finds all games in the library that match the given genre.                                 
 *                                                                                                   
 * @param genre Genre to search for                                                                  
 */                                                                                                  
void Library::find_genre(string genre) {                                                             
    bool found = false; // Track if a matching game was found                                        
                                                                                                     
    // Loop through each game in the list                                                            
    for (const auto& game : games) {                                                                 
        // Check if the game's genre matches                                                         
        if (game.genre == genre) {                                                                   
            // If match, display all the details of the game                                         
            cout << "Title: " << game.title << "\n"
                 << "Publisher: " << game.publisher << "\n"                                          
                 << "Genre: " << game.genre << "\n"                                                  
                 << "Hours Played: " << game.hoursPlayed << "\n"                                     
                 << "Price: $" << game.price << "\n"                                                 
                 << "Year: " << game.year << "\n";                                                   
            found = true;                                                                            
        }                                                                                            
    }                                                                                                
                                                                                                     
    // If no game with the genre was found, print                                                    
    if (!found) {                                                                                    
        cout << genre << " was not found" << "\n";                                                   
    }                                                                                                
}

/**                                                                                                  
 * @brief Loads game data from a file into the library.                                              
 *                                                                                                   
 * @param filename Name of the file to load from                                                     
 */                                                                                                  
void Library::load_from(const string& filename) {                                                    
    ifstream file(filename); // Open the input file                                                  
    string line; // String to hold number values as strings                                          
    Game game; // Game object to hold the read data                                                  
                                                                                                     
    // Read game data                                                                                
    while (getline(file, game.title) && getline(file, game.publisher) &&                             
           getline(file, game.genre) && getline(file, line)) {                                       
                                                                                                     
        // Check if hoursPlayed is a valid float                                                     
        stringstream ss(line);                                                                       
        if (!(ss >> game.hoursPlayed)) {                                                             
            cout << "Invalid data for hours played: " << line << endl;                               
            continue;                                                                                
        }                                                                                            
                                                                                                     
        getline(file, line);                                                                         
        // Check if price is a valid float                                                           
        stringstream ss2(line);                                                                      
        if (!(ss2 >> game.price)) {                                                                  
            cout << "Invalid data for price: " << line << endl;                                      
            continue;                                                                                
        }                                                                                            
                                                                                                     
        getline(file, line);                                                                         
        // Check if year is a valid int                                                              
        stringstream ss3(line);                                                                      
        if (!(ss3 >> game.year)) {                                                                   
            cout << "Invalid data for year: " << line << endl;                                       
            continue;                                                                                
        }                                                                                            
                                                                                                     
        games.push_back(game); // Add the game to the list                                           
    }                                                                                                
                                                                                                     
    file.close(); // Close the file                                                                  
}

/**                                                                                                  
 * @brief Saves all games in the library to a file.                                                  
 *                                                                                                   
 * @param filename Name of the file to save to                                                       
 */                                                                                                  
void Library::save_to(const string& filename) {                                                      
    ofstream file(filename); // Open the file for writing                                            
                                                                                                     
    // Loop through each game                                                                        
    for (const auto& game : games) {                                                                 
         // Write the game details to the file                                                       
        file << game.title << "\n"                                                                   
             << game.publisher << "\n"                                                               
             << game.genre << "\n"                                                                   
             << game.hoursPlayed << "\n"                                                             
             << game.price << "\n"                                                                   
             << game.year << "\n\n";                                                                 
    }                                                                                                
                                                                                                     
    file.close(); // Close the file                                                                  
}

/**                                                                                                  
 * @brief Prints all games stored in the library.                                                    
 */                                                                                                  
void Library::print() {                                                                              
    // Check is the games list is empty                                                              
    if (games.empty()) {                                                                             
        cout << "No games in the library.\n";                                                        
        return;                                                                                      
    }                                                                                                
                                                                                                     
    cout << "Library of Games:\n";                                                                   
    cout << "------------------\n";                                                                  
                                                                                                     
    // Print game details                                                                            
    for (const auto& game : games) {                                                                 
        cout << "Title: " << game.title << "\n"                                                      
             << "Publisher: " << game.publisher << "\n"                                              
             << "Genre: " << game.genre << "\n"                                                      
             << "Hours Played: " << game.hoursPlayed << "\n"                                         
             << "Price: $" << game.price << "\n"                                                     
             << "Year: " << game.year << "\n";                                                       
    }                                                                                                
}
