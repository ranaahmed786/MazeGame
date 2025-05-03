#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cell {
    int x, y;
    int pos;
    float thickness;
    bool walls[4] = { true, true, true, true };
    bool isVisited = false;
    bool isActive = false;
    float cellSize;
public:
    friend class Game;
    friend class Maze;
    Cell(int posX = 0, int posY = 0, int posIndx = 0) : pos(posIndx), x(posX), y(posY), cellSize(30.f), thickness(2.f) {}
    void drawCell(RenderWindow& window) {
        RectangleShape rect;
        if (isActive) {
            rect.setFillColor(Color(255, 245, 0));
            rect.setSize(Vector2f(cellSize, cellSize));
            rect.setPosition(x, y);
            window.draw(rect);
        }
        rect.setFillColor(Color());
        //top wall
        if (walls[0]) {
            rect.setSize(Vector2f(cellSize, thickness));
            rect.setPosition(x, y);
            window.draw(rect);
        }
        //right wall
        if (walls[1]) {
            rect.setSize(Vector2f(thickness, cellSize));
            rect.setPosition(x + cellSize, y);
            window.draw(rect);
        }
        //bottom wall
        if (walls[2]) {
            rect.setSize(Vector2f(cellSize + thickness, thickness));
            rect.setPosition(x, y + cellSize);
            window.draw(rect);
        }
        //left wall
        if (walls[3]) {
            rect.setSize(Vector2f(thickness, cellSize));
            rect.setPosition(x, y);
            window.draw(rect);
        }
    }
};

