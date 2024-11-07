#include "questClass.hpp"

void Quest::setItems(const std::vector<Item>& items) {
    this->Items = items;
}

void Quest::start() {
    // Implement quest start logic

    if (status == NotStarted) {
        status = InProgress;

        // Construct a string containing the names of the required items
        std::string requiredItemsList;
        for (const auto& item : Items) {
            requiredItemsList += item.GetName() + ", ";
        }
        // Remove the trailing comma and space
        if (!requiredItemsList.empty()) {
            requiredItemsList.erase(requiredItemsList.length() - 2);
        }

        // Display the quest start message with the required items
        std::cout << "This is the Quests Menu!\n";
        std::cout << "---------------------------------\n";
        std::cout << "Quests are objectives that you must complete to progress in the game.\n";
        std::cout << "Your current quests are:\n";

        if (!requiredItemsList.empty()) {
            std::cout << "- Find the required items (" << requiredItemsList << ").\n";
        } else {
            std::cout << "Quest started: No items to find.\n";
        }
        std::cout << "To complete a quest, you need to fulfill its objectives. Once done, you win the game!\n";
        std::cout << "Good luck!\n";
        std::cout << "---------------------------------\n";
    } else {
        std::cout << "Quest is already in progress or completed.\n";
    }
}

void Quest::update(const std::vector<Item>& foundItems) {
    // Check if any of the required items have been found
    bool allItemsFound = true;
    for (const auto& requiredItem : Items) {
        bool itemFound = false;
        for (const auto& foundItem : foundItems) {
            if (requiredItem == foundItem) {
                itemFound = true;
                break;
            }
        }
        if (!itemFound) {
            allItemsFound = false;
            break;
        }
    }

    // Update quest status based on whether all required items have been found
    if (status == InProgress && allItemsFound) {
        status = Completed;
        std::cout << "Quest completed: All required items found!\n";
    } else if (status == InProgress) {
        std::cout << "Keep searching for the required items.\n";
    } else {
        std::cout << "Quest is not in progress.\n";
    }
}

void Quest::complete() {
    // Implement quest start logic
    if (status == InProgress) {
        status = Completed;
        std::cout << "Quest completed!\n";
        completedQuests++;
    } else if (status == NotStarted) {
        std::cout << "Quest has not been started yet.\n";
    } else {
        std::cout << "Quest is already completed.\n";
    }

    if (completedQuests == totalQuests) {
        std::cout << "Congratulations! You have completed all quests. Game over." << std::endl;
        exit(0);
    }
}
