#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

struct Game {
  string title;
  string publisher;
  string genre;
  float hoursPlayed;
  float price;
  int year;
  Game* next;
};

#endif // GAME_H here is the game.h
