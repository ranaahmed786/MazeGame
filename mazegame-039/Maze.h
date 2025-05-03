#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include<stack>
#include <random>
using namespace std;
using namespace sf;
class Maze {
    int Mazesize;
    Cell* grid;
    int cellWidth;
public:
    friend class Game;
    Maze(int size = 30, int cellWidth = 30) : Mazesize(size), grid(new Cell[Mazesize * Mazesize]), cellWidth(cellWidth) {
        for (int i = 0, k = 0; i < Mazesize; i++) {
            for (int j = 0; j < Mazesize; j++, k++) {
                grid[k] = Cell(j * cellWidth, i * cellWidth, k);
            }
        }
    }
    void resetMaze() {
        for (int i = 0; i < Mazesize * Mazesize; i++) {
            for (int j = 0; j < 4; j++) {
                grid[i].walls[j] = true;
                grid[i].isVisited = false;
                grid[i].isActive = false;
            }
        }
    }
    void removeWallsBetween(Cell& current, Cell& chosen) {
        if (current.pos - Mazesize == chosen.pos) {
            current.walls[0] = false;
            chosen.walls[2] = false;
        }
        else if (current.pos + 1 == chosen.pos) {
            current.walls[1] = false;
            chosen.walls[3] = false;
        }
        else if (current.pos + Mazesize == chosen.pos) {
            current.walls[2] = false;
            chosen.walls[0] = false;
        }
        else if (current.pos - 1 == chosen.pos) {
            current.walls[3] = false;
            chosen.walls[1] = false;
        }
    }
    void makeMaze() {
        resetMaze();
        stack<Cell> stack;
        grid[0].isVisited = true;
        stack.push(grid[0]);
        while (!stack.empty()) {
            Cell current = stack.top();
            stack.pop();
            int pos = current.pos;
            int neighbors[4];
            int neighborCount = 0;

            if (pos % Mazesize != 0 && pos > 0) {
                Cell& left = grid[pos - 1];
                if (!left.isVisited) {
                    neighbors[neighborCount++] = pos - 1;
                }
            }
            if ((pos + 1) % (Mazesize) != 0 && pos < Mazesize * Mazesize) {
                Cell& right = grid[pos + 1];
                if (!right.isVisited) {
                    neighbors[neighborCount++] = pos + 1;
                }
            }
            if ((pos + Mazesize) < Mazesize * Mazesize) {
                Cell& bottom = grid[pos + Mazesize];
                if (!bottom.isVisited) {
                    neighbors[neighborCount++] = pos + Mazesize;
                }
            }
            if ((pos - Mazesize) > 0) {
                Cell& top = grid[pos - Mazesize];
                if (!top.isVisited) {
                    neighbors[neighborCount++] = pos - Mazesize;
                }
            }

            if (neighborCount > 0) {
                random_device dev;
                mt19937 rng(dev());
                uniform_int_distribution<mt19937::result_type> dist6(0, neighborCount - 1);
                int randNeighborPos = dist6(rng);
                Cell& chosen = grid[neighbors[randNeighborPos]];
                stack.push(current);
                removeWallsBetween(grid[current.pos], chosen);
                chosen.isVisited = true;
                stack.push(chosen);
            }
        }
    }
    void handleMove(Event event, int& currentPos) {
        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A) {
            if (!grid[currentPos].walls[3] && !grid[currentPos - 1].walls[1]) {
                currentPos = currentPos - 1;
                grid[currentPos].isActive = true;
            }
        }
        else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D) {
            if (!grid[currentPos].walls[1] && !grid[currentPos + 1].walls[3]) {
                currentPos = currentPos + 1;
                grid[currentPos].isActive = true;
            }
        }
        else if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W) {
            if ((currentPos - Mazesize) < 0) {
                return;
            }
            if (!grid[currentPos].walls[0] && !grid[currentPos - Mazesize].walls[2]) {
                currentPos = currentPos - Mazesize;
                grid[currentPos].isActive = true;
            }
        }
        else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S) {
            if ((currentPos + Mazesize) > Mazesize * Mazesize) {
                return;
            }
            if (!grid[currentPos].walls[2] && !grid[currentPos + Mazesize].walls[0]) {
                currentPos = currentPos + Mazesize;
                grid[currentPos].isActive = true;
            }
        }
    }
    ~Maze() {
        delete[] grid;
    }
};