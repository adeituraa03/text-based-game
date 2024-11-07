#include "roomClass.hpp"

std::string Room::GetDescription() const {
    return description;
}

std::string Room::GetName() const {
    return name;
}

std::vector<Item> Room::GetItems() const {
    return items;
}

std::vector<Enemy> Room::GetEnemy() const {
    return enemies;
}


void Room::AddItem(const Item& item) {
    items.push_back(item);
}


void Room::RemoveItem(Item& item) {

    items.erase(std::remove(items.begin(), items.end(), item), items.end());

}

void Room::AddExit(const std::string& direction, Room* roomName) {
    //adds the connections to the map
    exits.insert(std::make_pair(direction, roomName));

}

std::map<std::string, Room*> Room::GetExits() const{
    return exits;
}

Room* Room::GetExit(const std::string& direction) {
    auto it = exits.find(direction);
    if (it != exits.end()) {

        return it->second;
    }
    else {
        return nullptr;
    }
}

void Room::AddEnemy(const Enemy& enemy) {
    enemies.push_back(enemy);
}

