#include "characterClass.hpp"

std::string Player::GetName() const {
    return Name;
}

int Player::GetHealth() const {
    return Health;
}

void Player::SetLocation(Room* NewLocation) {
    location = NewLocation;
}

Room* Player::GetLocation() const{
    return location;
}

void Player::TakeDamage(int damage) {
    Health -= damage;
    if (Health <= 0) {
        std::cout << Name << " has been defeated!" << std::endl;
        std::cout << "GAME OVER!!" << std::endl;
        exit(0);

    } else {
        std::cout << Name << " took " << damage << " damage." << std::endl;
    }
}


