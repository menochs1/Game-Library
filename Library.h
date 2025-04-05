#ifndef LIBRARY_H
#define LIBRARY_H

#include "game.h"
#include <list>
#include <string>

using namespace std;

class Library {
private:
    list<Game> games;

public:
    Library();
    ~Library();

    void insert_sorted(string title, string publisher, string genre, float hourPlayed, float price, int year);
    void delete_game(string title, int year);
    void find_game(string title);
    void find_genre(string genre);
    void load_from(const string& filename);
    void save_to(const string& filename);
    void print();
};

#endif // LIBRARY_H
