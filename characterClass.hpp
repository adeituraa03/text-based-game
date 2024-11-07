#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "roomClass.hpp"
#include "InventoryClass.hpp"
#include "questClass.hpp"


class Enemy;

class Character {
protected:
    std::string Name;
    int Health;
    std::vector<Item> Inventory;
    Enemy enemy;
public:
    Character(const std::string& name, int health) {
        Name = name;
        Health = health;
    };

};

class Player : Character {
private:
    Room* location;
    std::vector<Item> Inventory;
public:
    Player(const std::string& name, int health) : Character(name, health) {};

    std::string GetName() const;
    int GetHealth() const;
    void SetLocation(Room* NewLocation);
    Room* GetLocation() const;
    void TakeDamage(int damage);


};
