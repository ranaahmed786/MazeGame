#pragma once
#include "Player.h"
class ProfessionalPlayer : public Player {
public:
    ProfessionalPlayer(string name = "unknown", int age = 1) : Player(name, age) {}
    int ratingScore() const override {
        if (age <= 0) {
            return 0;
        }
        return (gamesPlayed * 20) / age;
    }
};
