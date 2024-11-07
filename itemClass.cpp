#include "itemClass.hpp"

std::string Item::GetName() const{
    return Name;
}

std::string Item::GetDescription() const{
    return Description;
}


std::string Item::Interact() {
    std::cout << "Would you like to pick up this item? (Y/N) " << std::endl;
    std::string pickUp;
    std::cin >> pickUp;

    if (pickUp == "Y" || pickUp == "N") {
        return pickUp;
    } else {
        return "";
    }

}

void Item::UseItem(int& playerHealth, int& maxHealth) {
    if (Name == "First_Aid_Kit") {
        playerHealth += maxHealth;
        std::cout << "Your health is back to max!" << "\n";
    } else if (Name == "Bread_Loaf") {
        playerHealth += 10;
        std::cout << "Your health has increased by 10!" << "\n";
    } else if (Name == "Mysterious_Potion") {
        playerHealth -= 15;
        std::cout << "Oh on! Your health has reduced by 15 points :(" << "\n";
    }

    std::cout << "You used the " << Name << ".\n";
}


