/**
 * @file game.h
 * @brief Defines the Game struct
 * 
 * Each Game holds  title, publisher, genre,hours played, price, and release year.
 * 
 * @author 
 * Jalen Jones, Mason E
 * @date 4/3/2025
 */

#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

/**
 * @struct Game
 * @brief Represents a single game entry with properties.
 */
struct Game {
    string title;        // Title of the game
    string publisher;    // Publisher of the game
    string genre;        // Genre/category of the game
    float hoursPlayed;   // Total hours the game has been played
    float price;         // Price of the game in USD
    int year;            // Year the game was released
};

#endif // GAME_H
