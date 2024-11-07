#pragma once

#include <iostream>
#include <string>


class Item {
private:
    std::string Name;
    std::string Description;

public:
    Item(const std::string& name, const std::string& description) {
        Name = name;
        Description = description;
    };
    std::string Interact();
    void UseItem(int& playerHealth, int& maxHealth);

    std::string GetDescription() const;
    std::string GetName() const;

    bool operator== (const Item& other) const{
        return Name == other.Name;
    }

};
