/**
 * @file library.h
 * @brief Header for the Library class
 *
 * @author Jalen J, Mason E
 * @date 4/3/2025
 */

 #ifndef LIBRARY_H
 #define LIBRARY_H
 
 #include "game.h"
 #include <list>
 #include <string>
 
 using namespace std;
 
 /**
  * @class Library
  * @brief Manages a collection of games
  *
  * The Library class provides methods to insert, delete, search, print, and read/write game data
  */

 class Library {
 private:
     list<Game> games;  // List to store Game objects
 
 public:
     /**
      * @brief Constructs a new Library object
      */
     Library();
 
     /**
      * @brief Destroys the Library object
      */
     ~Library();
 
     /**
      * @brief Inserts a game into the the sorted list
      * 
      * @param title The title of the game
      * @param publisher The publisher of the game
      * @param genre The genre of the game
      * @param hourPlayed Number of hours played
      * @param price Price of the game
      * @param year Release year of the game
      */
     void insert_sorted(string title, string publisher, string genre, float hourPlayed, float price, int year);
 
     /**
      * @brief Deletes a game by its title and release year
      * 
      * @param title The title of the game to delete
      * @param year The release year of the game
      */
     void delete_game(string title, int year);
 
     /**
      * @brief Finds and displays a game by the title
      * 
      * @param title The title of the game to search for
      */
     void find_game(string title);
 
     /**
      * @brief Finds and displays all games of a genre
      * 
      * @param genre The genre to search for
      */
     void find_genre(string genre);
 
     /**
      * @brief Loads games from a file
      * 
      * @param filename The file to read games from
      */
     void load_from(const string& filename);
 
     /**
      * @brief Saves all games in the library to a file
      * 
      * @param filename The file to write games to
      */
     void save_to(const string& filename);
 
     /**
      * @brief Prints all games in the library
      */
     void print();
 };
 
 #endif // LIBRARY_H
