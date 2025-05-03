# Maze Game 🎮

A **C++ object-oriented maze game** that blends creativity, challenge, and polished design. This project applies core OOP concepts — including inheritance, polymorphism, file handling, and exception handling — while offering an engaging user experience through a carefully designed graphical user interface.

---

## 📋 Table of Contents

1. [Introduction](#introduction)
2. [Project Features](#project-features)
3. [Objectives](#objectives)
4. [OOP Concepts Used](#oop-concepts-used)
5. [System Requirements](#system-requirements)
6. [Installation & Setup](#installation--setup)
7. [Usage Guide](#usage-guide)
8. [User Interface Screenshots](#user-interface-screenshots)
9. [Project Structure](#project-structure)
10. [Contributing](#contributing)
11. [License](#license)

---

## 🏁 Introduction

The **Maze Game** challenges the player to navigate a character through a complex maze, avoiding obstacles and collecting rewards to reach the finish point. Designed with a modular architecture, this project aims to demonstrate clean code practices, effective use of OOP, and interactive gameplay.

---

## ✨ Project Features

- Interactive maze navigation
- Player character with movement controls
- Obstacles and reward items
- Dynamic score tracking
- Save/load game states (using file handling)
- Exception handling for invalid inputs and system errors
- Expandable and maintainable design

---

## 🎯 Objectives

1. Apply **object-oriented programming (OOP)** principles effectively.
2. Design a **graphical maze interface** for user interaction.
3. Implement **file handling** to save/load progress.
4. Incorporate **exception handling** for robust gameplay.
5. Ensure **code reusability and modularity**.
6. Provide an **engaging and user-friendly experience**.

---

## 🛠 OOP Concepts Used

| Concept              | How It’s Used                                      |
|----------------------|----------------------------------------------------|
| **Inheritance**      | Shared base classes for game objects (player, walls, rewards). |
| **Polymorphism**     | Overridden methods for unique behaviors of different objects. |
| **Encapsulation**    | Private attributes with public getters/setters.     |
| **Abstraction**      | High-level interfaces for handling gameplay logic. |
| **File Handling**    | Save/load game data to/from external files.         |
| **Exception Handling** | Graceful error handling for invalid moves or file errors. |

---

## 💻 System Requirements

- **Operating System:** Windows / Linux / macOS
- **Compiler:** C++11 or higher
- **Libraries:** SFML (Simple and Fast Multimedia Library) or similar graphics framework if used
- **Disk Space:** Minimum 100 MB

---

## ⚙ Installation & Setup

1. **Clone the repository**
    ```bash
    git clone https://github.com/yourusername/maze-game.git
    ```

2. **Navigate to the project folder**
    ```bash
    cd maze-game
    ```

3. **Compile the project**
    - If using Makefile:
        ```bash
        make
        ```
    - If using g++ directly:
        ```bash
        g++ -std=c++11 main.cpp -o MazeGame
        ```

4. **Run the executable**
    ```bash
    ./MazeGame
    ```

---

## 🕹 Usage Guide

- **Arrow Keys:** Move the player up, down, left, right.
- **S Key:** Save current game state.
- **L Key:** Load previously saved game.
- **Esc Key:** Exit the game.

Make sure you don’t run into obstacles, and try to collect all rewards before reaching the maze exit!

---

## 🖼 User Interface Screenshots

| Main Menu                                                                                      | Gameplay Screen                                                                                      |
|-------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| ![Main Menu](https://github.com/user-attachments/assets/688d6a9c-9aae-41ef-a494-ce7e2dec052d)   | ![Gameplay](https://github.com/user-attachments/assets/1a9ee4ae-3a50-4c3a-83a2-ac2695cba91d)         |

| Move Tracking                                                                                   | Save/Load Player Data                                                                               |
|-------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| ![Move Tracking](https://github.com/user-attachments/assets/ccd2510a-7f23-48d6-9995-0f8ab53f8a50) | ![Save Load](https://github.com/user-attachments/assets/720759d4-8fa9-4f04-bda0-0aff27b0b21f)        |

---

## 📁 Project Structure

maze-game/
├── src/
│ ├── main.cpp
│ ├── player.cpp
│ ├── maze.cpp
│ └── ...
├── include/
│ ├── player.h
│ ├── maze.h
│ └── ...
├── assets/
│ ├── images/
│ ├── sounds/
│ └── ...
├── save/
│ └── saved_game.dat
├── screenshots/
│ ├── main_menu.png
│ ├── gameplay.png
│ └── ...
├── Makefile
└── README.md

yaml
Copy
Edit

---

## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch.
3. Commit your changes.
4. Push to your fork.
5. Create a pull request.

---

## 📜 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---
