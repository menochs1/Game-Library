Authors: Jalen Jones, Mason Enochs.

## Features
- Add Games: Insert new games into the list, sorted by release year.
- Delete Games: Remove games by title and year.
- Find by Title: Search for a specific game by title.
- Find by Genre: List all games within a given genre.
- Print Library: Display all games currently in the library.
- Load from File: Read a list of games from a user-specified text file.
- Save to File: Write the current list of games to a text file.

## Files
-library.cpp: Implementation of the Library class.
-library.h: Header file defining the Game struct and Library class methods.
-main.cpp: A menu-driven interface for interacting with the library.
-game.h: Header file containing the Game struct.

## How to Run
- Compile the project with g++ main.cpp library.cpp -o game_library
- Run the program with ./game_library

## Program Flow
- The program asks the user to enter a filename for loading and saving the game.
- If the file exists, its contents are loaded.
- A menu is displayed, allowing the user to:
-- Add new games
-- Delete existing games
-- Search games by title or genre
-- Print the entire game library
-- Manually load or save the specified file at any point
- On exiting, the library is saved to the file provided
