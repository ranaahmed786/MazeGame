#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Player {
protected:
    string name;
    int age;
    int gamesPlayed;
public:
    Player(string name = "unknown", int age = 0) : name(name), age(age), gamesPlayed(0) {}
    virtual ~Player() {}
    virtual int ratingScore() const = 0;
    void validationError() {
        cout << "Invalid input.Try again :";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };
    void setPlayer() {
            cout << "Enter player name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter player age: ";
            while (!(cin >> age)&&(age<0))
            {
                validationError();
            };
    }
    void getPlayer() const {
        cout << "Player name: " << name << endl;
        cout << "Player age: " << age << endl;
        cout << "Player games played: " << gamesPlayed << endl;
    }
    void incrementGamesPlayed() {
        gamesPlayed++;
    }
    void writeToFile() const {
        ofstream file;
        try {
            file.open("player.txt", ios::app);
            if (!file) {
                throw runtime_error("Unable to open file");
            }
            file << name << " " << age << " " << gamesPlayed << " " << ratingScore() << endl;
            file.close();
        }
        catch (const exception& e) {
            cerr << "An error occurred while writing to file: " << e.what() << endl;
        }
    }
};
