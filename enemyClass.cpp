#include "enemyClass.hpp"

std::string Enemy::GetName() const {
    return Name;
}
int Enemy::GetHealth() const {
    return Health;
}
int Enemy::GetAttackPower() const {
    std::cout << "You have been attacked!!" << "\n";
    return AttackPower;
}
