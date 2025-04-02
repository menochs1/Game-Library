#include "library.h"
#include "game.h"
#include <iostream>
#inlcude <list>

using namespace std;

Library::Library()
{
  this->games = games;
}

Library::~Library()
{
  delete games;
}

Library::insert_sorted(string title, string publisher, string genre, float hourPlayed, float price, int year);
{
  game newGame;
  newGametitle = title;
  newGame.publisher = publisher;
  newGame.genre = genre;
  newGame.hoursPlayed = hoursPlayed;
  newGame.price = price;
  newGame.year = year;
  
  if(games.empty())
    {
      games.push_front(newGame);
    }
  else
    {
      for(it = games.begin(); it != games.end(); it++;)
	{
	  if(it->title > newGame.title)
	    {
	      games.insert(*it, newGame);
	    }
	}
      games.push_back(newGame);
    }
}

Library::delete_game(string title, int year)
{
  for(it = games.begin(); it != games.end(); it++)
    {
      if(it->title == title && it->year == year)
	{
	  games.pop(*it);
	}
    }
}
