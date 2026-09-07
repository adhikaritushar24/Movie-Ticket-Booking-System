#ifndef SHOW_H
#define SHOW_H

#include <string>
#include "Movie.h"
#include "Screen.h"
using namespace std;

class Show {
private:
    int showId;
    Movie* movie;
    Screen* screen;
    string startTime;

public:
    Show(int showId, Movie* movie, Screen* screen, string startTime);

    int getShowId();
    Movie* getMovie();
    Screen* getScreen();
    string getStartTime();

    void displayShow();
};

#endif
