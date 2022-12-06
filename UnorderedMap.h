#pragma once
#include "movie.h"
#include "list"

class UnorderedMap {

public:

    list <list<pair<string, movie>>> hashTable[100];


    int hashfunction(string title) {
        return (title.size() % 100);

    }

    void insert(string key, movie value) {
        list <pair<string, movie>> m;
        m.emplace_back(key, value);

        hashTable[hashfunction(key)].emplace_back(m);
    }


    void SearchRelatedGenre(string title) {
        string genre;
        int count = 0;
        vector<movie> movieGenres;
        bool leave = false;

        for (int i = 0; i < 100; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++) {
                    if (it1->first == title) {
                        genre = it1->second.genre;
                        leave = true;
                        break;
                    }
                }
                if (leave == true) {
                    break;
                }
            }
            if (leave == true) {
                break;
            }
        }

        leave = false;
        for (int i = 0; i < 100; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++) {
                    if (count == 5) {
                        leave = true;
                        break;
                    }

                    if (it1->second.genre == genre && it1->second.name != title) {
                        movieGenres.push_back(it1->second);
                        count++;
                    }

                }
                if (count == 5) {
                    break;
                }
            }
            if (count == 5) {
                break;
            }
        }

        cout << "Movies with same Genre as " << title << ": " << endl;
        for (int i = 0; i < movieGenres.size(); i++) {
            cout << movieGenres[i].name << endl;
        }
        cout << endl;


    }


    void SearchRelatedYear(string title) {
        string year;
        int count = 0;
        vector<movie> movieYears;
        bool leave = false;

        for (int i = 0; i < 100; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++) {
                    if (it1->first == title) {
                        year = it1->second.year;
                        leave = true;
                        break;
                    }
                }
                if (leave == true) {
                    break;
                }
            }
            if (leave == true) {
                break;
            }
        }

        leave = false;
        for (int i = 0; i < 100; i++) {
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++) {
                    if (count == 5) {
                        leave = true;
                        break;
                    }

                    if (it1->second.year == year && it1->second.name != title) {
                        movieYears.push_back(it1->second);
                        count++;
                    }

                }
                if (count == 5) {
                    break;
                }
            }
            if (count == 5) {
                break;
            }
        }

        cout << "Movies made in the same year as " << title << ": " << endl;
        for (int i = 0; i < movieYears.size(); i++) {
            if (movieYears[i].name != title) {
                cout << movieYears[i].name << endl;
            }
        }
        cout << endl;
    }
};