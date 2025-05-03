
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Maze.h"
#include "ProfessionalPlayer.h"
#include "AmateurPlayer.h"
using namespace sf;
using namespace std;

class Game {
    int currentPos;
    Maze maze;
    Player* player;

public:
    friend istream& operator>>(istream& is, Game& game);
    friend ostream& operator<<(ostream& os, Game& game);

    Game(int mazesize = 30, int pos = 0, string name = "unknown", int age = 0)
        : currentPos(pos), maze(mazesize) {
        char choice;
        cout << endl << "Are you a professional player (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            player = new ProfessionalPlayer(name, age);
        }
        else {
            player = new AmateurPlayer(name, age);
        }
    }

    void playGame() {
        SoundBuffer BgBuffer;
        if (!BgBuffer.loadFromFile("mazebg.wav")) {
            cout << "Could not load background music" << endl;
        }
        Sound BgSound;
        BgSound.setBuffer(BgBuffer);
        BgSound.play();
        BgSound.setLoop(true);

        player->setPlayer();

        RenderWindow window(VideoMode((maze.Mazesize * maze.cellWidth), (maze.Mazesize * maze.cellWidth)), "Maze Game");
        window.setVerticalSyncEnabled(true);

        maze.makeMaze();
        maze.grid[currentPos].isActive = true;

        RectangleShape currentPosRect;
        currentPosRect.setFillColor(Color(52, 148, 132));
        currentPosRect.setSize(Vector2f(maze.cellWidth, maze.cellWidth));

        RectangleShape finishRect;
        finishRect.setFillColor(Color(233, 82, 82));
        finishRect.setSize(Vector2f(maze.cellWidth, maze.cellWidth));

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    maze.handleMove(event, currentPos);
                    break;
                default:
                    break;
                }
            }

            if (currentPos == (maze.Mazesize * maze.Mazesize - 1)) {
                maze.makeMaze();
                currentPos = 0; // Reset current position to 0
                maze.grid[currentPos].isActive = true;
                player->incrementGamesPlayed();
            }

            window.clear(Color(190, 255, 244));

            for (int i = 0; i < (maze.Mazesize * maze.Mazesize); i++) {
                maze.grid[i].drawCell(window);
            }

            currentPosRect.setPosition(maze.grid[currentPos].x, maze.grid[currentPos].y);
            window.draw(currentPosRect);

            finishRect.setPosition(maze.grid[maze.Mazesize * maze.Mazesize - 1].x, maze.grid[maze.Mazesize * maze.Mazesize - 1].y);
            window.draw(finishRect);

            window.display();
        }

        player->getPlayer();
        cout << "Player rating score: " << player->ratingScore() << endl;
        player->writeToFile();
    }

    ~Game() {
        delete player;
    }
};

ostream& operator<<(ostream& os, Game& game) {
    game.playGame();
    return os;
}

istream& operator>>(istream& is, Game& game) {
    cout << endl << "Update player details";
    game.player->setPlayer();
    return is;
}