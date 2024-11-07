#include "InventoryClass.hpp"

void Inventory::GetCapacity() const {
    std::cout << "Inventory size: " << MaxCapacity << "\n";
}


bool Inventory::addItem(const Item& item) {
    if (items.size() < MaxCapacity) {
        items.push_back(item);
        return true;
    }
    return false; // Inventory full
}
bool Inventory::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            items.erase(it);
            return true;
        }
    }
    return false; // Item not found

}

void Inventory::displayInventory() const {
    std::cout << "Inventory:\n";
    if (items.empty()) {
        std::cout << "The inventory is empty" << std::endl;
    } else {
        for (const auto& item : items) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << "\n" << std::endl;
        }
    }

}

void Inventory::displayUsableItems() const {
    std::cout << "Usable Items:\n";
    for (const auto& item : items) {
        if (item.GetName() == "First_Aid_Kit" || item.GetName() == "Bread_Loaf" || item.GetName() == "Mysterious_Potion") {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << "\n";
        }
    }
}

bool Inventory::HasItem(const std::string& itemName) const {
    // Find the item in the inventory
    auto it = items.begin();
    for (; it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            // Item found
            break;
        }
    }
}

void Inventory::UseItem(int playerHealth, int maxHealth) {
    if (items.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }
    displayInventory();
    displayUsableItems();
    std::cout << "Enter the name of the item you want to use: ";
    std::string itemName;
    std::cin >> itemName;

    // Find the item in the inventory
    auto it = items.begin();
    for (; it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            // Item found
            break;
        }
    }

    if (it != items.end()) {
        it->UseItem(playerHealth, maxHealth);
        items.erase(it); // Remove the used item from the inventory
    } else {
        std::cout << "Item not found in your inventory.\n";
    }
}
