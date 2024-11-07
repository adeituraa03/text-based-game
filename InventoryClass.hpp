#include <iostream>
#include <vector>
#include "itemClass.hpp"

class Inventory {
private:
    std::vector<Item> items;
    int MaxCapacity;

public:
    Inventory(int maxCapacity) {
        MaxCapacity = maxCapacity;
    }
    bool addItem(const Item& item);
    bool removeItem(const std::string& itemName);
    void displayInventory() const;
    void UseItem(int playerHealth, int maxHealth);
    void displayUsableItems() const;
    bool HasItem(const std::string& itemName) const;
    void GetCapacity() const;
};
