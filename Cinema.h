#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>
#include "Screen.h"
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name);

    void addScreen(Screen screen);
    vector<Screen>& getScreens();

    void displayScreens();
};

#endif
