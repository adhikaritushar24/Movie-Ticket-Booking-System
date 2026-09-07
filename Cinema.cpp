#include "Cinema.h"
#include <iostream>
using namespace std;

Cinema::Cinema(string name) {
    this->name = name;
}

void Cinema::addScreen(Screen screen) {
    screens.push_back(screen);
}

vector<Screen>& Cinema::getScreens() {
    return screens;
}

void Cinema::displayScreens() {
    cout << "Cinema: " << name << " has " << screens.size() << " screen(s)" << endl;
    for (int i = 0; i < screens.size(); i++) {
        cout << "  Screen " << screens[i].getScreenNumber() << endl;
    }
}
