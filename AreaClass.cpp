#include "AreaClass.hpp"

void Area::AddItemToRoom(const std::string& roomName, const Item& item) {
    auto it = Rooms.find(roomName);
    if (it != Rooms.end()) {
        it->second->AddItem(item);
    } else {
        // Handle error: Room not found
    }
}

void Area::AddEnemyToRoom(const std::string& roomName, const Enemy& enemy) {
    auto it = Rooms.find(roomName);
    if (it != Rooms.end()) {
        it->second->AddEnemy(enemy);
    } else {
        // Handle error: Room not found
    }
}

void Area::AddRoom(const std::string& name, Room* room) {
    // loop through map to find key that has the same name as the one entered through the parameters
    Rooms.insert(std::make_pair(name, room));
}

Room* Area::GetRoom(const std::string& name) {
    auto it = Rooms.find(name);
    if (it != Rooms.end()) {
        return it->second;

    }
    else {
        std::cout << "this room does not exist" << std::endl;
        return nullptr;
    }

}

void Area::ConnectRooms(const std::string& room1, const std::string& room2, const std::string& direction) {

    // Retrieve the Room objects from the map
    Room* Room1 = GetRoom(room1);
    Room* Room2 = GetRoom(room2);

    if (GetRoom(room1) != nullptr && GetRoom(room2) != nullptr) {
        Room1->AddExit(direction, Room2);
    }
    else {
        std::cout << "One or both of the specified rooms do not exist." << std::endl;
    }


}

void Area::LoadMapFromFile(const std::string& connectionsFile, const std::string& descriptionFile) {
    std::ifstream connectFile;
    std::ifstream descFile;
    std::string line;
    std::vector<std::string> connectionLines;
    std::vector<std::string> descriptionLines;

    connectFile.open(connectionsFile);
    descFile.open(descriptionFile);
    if (connectFile.is_open() && descFile.is_open()) {
        // Load lines from connectionsFile into memory
        while (std::getline(connectFile, line)) {
            connectionLines.push_back(line);
        }

        // Load lines from descriptionFile into memory
        while (std::getline(descFile, line)) {
            descriptionLines.push_back(line);
        }

        // Process connections
        for (const auto& connectionLine : connectionLines) {
            std::stringstream iss(connectionLine);
            std::string room1, room2, direction;

            if (std::getline(iss, room1, ',') && std::getline(iss, room2, ',') && std::getline(iss, direction, ',')) {

                // Process descriptions
                for (const auto& descriptionLine : descriptionLines) {
                    std::stringstream iss(descriptionLine);
                    std::string roomName, description;

                    if (std::getline(iss, roomName, ',') && std::getline(iss, description, ',')) {
                        Room* newRoom = new Room(roomName, description);
                        if (room1 == roomName || room2 == roomName) {

                            AddRoom(roomName, newRoom);

                        }


                    }
                }


            }
            ConnectRooms(room1, room2, direction);
        }

    }

    connectFile.close();
    descFile.close();


}
