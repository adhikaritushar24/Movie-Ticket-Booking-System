#include "Show.h"
#include <iostream>
using namespace std;

Show::Show(int showId, Movie* movie, Screen* screen, string startTime) {
    this->showId = showId;
    this->movie = movie;
    this->screen = screen;
    this->startTime = startTime;
}

int Show::getShowId() { return showId; }
Movie* Show::getMovie() { return movie; }
Screen* Show::getScreen() { return screen; }
string Show::getStartTime() { return startTime; }

void Show::displayShow() {
    cout << "Show #" << showId << " | Movie: " << movie->getTitle() << " | Screen: " << screen->getScreenNumber() << " | Time: " << startTime << endl;
}
