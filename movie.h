#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct movie {
    string name;
    string genre;
    string year;
    // movie() : name(" "), genre(" "), year(" ") {}
    movie(string name, string genre, string year) {
        this->name = name;
        this->genre = genre;
        this->year = year;

    }
};
