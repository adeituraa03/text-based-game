#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "itemClass.hpp"
#include "enemyClass.hpp"


class Room {
private:
    std::string description;
    std::string name;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;
    std::vector<Enemy> enemies;

public:
    Room(const std::string& roomName, const std::string& desc) {
        name = roomName;
        description = desc;
    };

    std::string GetDescription() const;
    std::vector<Item> GetItems() const;
    std::string GetName() const;

    void AddItem(const Item& item);
    void RemoveItem(Item& item);

    void AddExit(const std::string& direction, Room* roomName);
    std::map<std::string, Room*> GetExits() const;
    Room* GetExit(const std::string& direction);

    void AddEnemy(const Enemy& enemy);
    std::vector<Enemy> GetEnemy() const;

};
