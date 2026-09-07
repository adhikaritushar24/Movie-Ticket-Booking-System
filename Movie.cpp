#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie(string title, string language, int duration) {
    this->title = title;
    this->language = language;
    this->duration = duration;
}

string Movie::getTitle() { return title; }
string Movie::getLanguage() { return language; }
int Movie::getDuration() { return duration; }

void Movie::displayMovie() {
    cout << "Title    : " << title << endl;
    cout << "Language : " << language << endl;
    cout << "Duration : " << duration << " min" << endl;
}
