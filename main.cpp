#include "UnorderedMap.h"
#include "mapImplementation.h"
#include "fstream"

int main() {
    cout << "Hello! Welcome to Movies/TV Series Recommendation Generator" << endl;
    cout << "  " << endl;
    int rec = 0;
    while (rec != 4) {
        int mapOrUm = 0;
        cout << "            Menu      " << endl;
        cout << "-------------------------------" << endl;
        cout << "1. UNORDERED MAP" << endl;
        cout << "2. MAP" << endl;
        cout << "-------------------------------" << endl;
        cout << "Menu Choice: ";
        cin >> mapOrUm;
        cout << endl;


        string fileName = "data.tsv";

        ifstream inFile(fileName);

        UnorderedMap um;
        map m;

        if (inFile.is_open()) {
            string wholeLine;

            getline(inFile, wholeLine);
            //map
            if (mapOrUm == 1) {
                for (int i = 0; i < 100000; i++) {
                    string title;
                    string year;
                    string temp;
                    string genre;
                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, title, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, year, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, genre);


                    movie c(title, genre, year);
                    um.insert(title, c);

                    //m.mapInsert(title, c, false);
                }
            }
                //map
            else {
                for (int j = 0; j < 100000; ++j) {

                    string title;
                    string year;
                    string temp;
                    string genre;


                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, title, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, year, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, temp, '\t');
                    getline(inFile, genre);


                    movie c(title, genre, year);
                    m.mapInsert(title, c, false);

                }

            }
        }

        while (rec != 4 || rec != 3) {
            cout << "Type of Recommendation" << endl;
            cout << "-------------------------------" << endl;
            cout << "1.Search by genre recommendation" << endl;
            cout << "2.Search by year recommendation" << endl;
            cout << "3.Change Data Structure" << endl;
            cout << "4.Exit" << endl;
            cout << "-------------------------------" << endl;
            cout << "Menu Choice: ";
            cin >> rec;
            cout << endl;

            if (rec == 4) {
                cout << "Thank you for using our recommendation system! Bye!" << endl;
                rec = 4;
                break;
            }
            if (rec == 3) {
                rec = 3;
                break;
            }

            cin.ignore();

            string title;
            if (mapOrUm == 1) {
                if (rec == 1) {

                    cout << "Enter the movie name: ";
                    getline(cin, title);
                    cout << endl;
                    um.SearchRelatedGenre(title);
                }
                else if (rec == 2) {

                    cout << "Enter the movie name : ";
                    getline(cin, title);
                    cout << endl;
                    um.SearchRelatedYear(title);
                }
            }
            else if (mapOrUm == 2) {
                set<string> recommended;
                if (rec == 1) {
                    cout << "Enter the movie name: ";
                    getline(cin, title);
                    recommended = m.mapSearch(rec, title);
                    cout << "Movies with same Genre as " << title << ": " << endl;
                }
                else if (rec == 2) {
                    cout << "Enter the movie name: ";
                    getline(cin, title);
                    recommended = m.mapSearch(rec, title);
                    cout << "Movies made in the same year as " << title << ": " << endl;
                }

                int size = 0;
                for (auto i = recommended.begin(); i != recommended.end(); ++i) {
                    if (*i != title) {
                        cout << *i << endl;
                        size++;
                    }
                    if (size == 5) {
                        break;
                    }
                }
                cout << endl;
            }
        }
    }

}