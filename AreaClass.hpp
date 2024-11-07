#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include "characterClass.hpp"

class Area {
private:
    std::map<std::string, Room*> Rooms;


public:
    Area() {};
    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1, const std::string& room2, const std::string& direction);
    void LoadMapFromFile(const std::string& connectionsFile, const std::string& descriptionFile);
    void AddItemToRoom(const std::string& roomName, const Item& item);
    void AddEnemyToRoom(const std::string& roomName, const Enemy& enemy);

};
