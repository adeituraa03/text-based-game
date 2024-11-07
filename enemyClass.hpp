#pragma once

#include <iostream>

class Enemy {
private:
    std::string Name;
    int Health;
    int AttackPower;

public:
    Enemy(const std::string& name, int health, int attackPower) {
        Name = name;
        Health = health;
        AttackPower = attackPower;
    }

    Enemy() {};
    std::string GetName() const;
    int GetHealth() const;
    int GetAttackPower() const;


};
