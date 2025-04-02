#ifndef LIBRARY_H
#define LIBRARY_H

#include "game.h"
#include <string>
#include <list>

using namespace std;

class Library {
 private:
  list<Game> games;

 public:
  Library();
  ~Library();

  void insert_sorted(string title, string publisher, string genre, float hoursPlayed, float price, int year);
  void delete_game(string title, int year);
  void find_game(string title);
  void find_genre(string genre);
  void print();
};

#endif // LIBRARY_H library.h
