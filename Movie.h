#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int duration;

public:
    Movie(string title, string language, int duration);

    string getTitle();
    string getLanguage();
    int getDuration();

    void displayMovie();
};

#endif
