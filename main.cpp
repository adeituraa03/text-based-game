#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <vector>
#include "AreaClass.hpp"


int main() {
    // Initialize an empty vector of items
    std::vector<Item> availableItems;
    std::vector<Item> questItems;

    Area gameWorld;
    gameWorld.LoadMapFromFile("game_map.txt", "room_description.txt");


    availableItems.push_back(Item("Lair Key", "A shiny key that looks important."));
    availableItems.push_back(Item("Regular_Sword", "A sharp sword with a golden hilt."));
    availableItems.push_back(Item("Potion", "A bubbling potion in a glass vial."));
    availableItems.push_back(Item("Spellbook", "An ancient tome filled with magical incantations."));
    availableItems.push_back(Item("Scroll", "A delicate scroll written in elven script."));
    availableItems.push_back(Item("Quill", "An enchanted quill that never runs out of ink."));
    availableItems.push_back(Item("Pearl_Necklace", "A necklace adorned with lustrous pearls."));
    availableItems.push_back(Item("Seashell", "A beautifully crafted seashell."));
    availableItems.push_back(Item("Legendary_Sword", "A mighty sword forged by skilled dwarven blacksmiths."));
    availableItems.push_back(Item("First_Aid_Kit", "A healing kit to boost your health"));
    availableItems.push_back(Item("Mysterious_Potion", "A potion with unknown effects."));
    availableItems.push_back(Item("Trinket", "A small goblin-made trinket."));
    availableItems.push_back(Item("Ghostly_Lantern", "A lantern that glows with an eerie light."));
    availableItems.push_back(Item("Bread_Loaf", "A loaf of bread to give you energy"));
    availableItems.push_back(Item("Ancient_Relic", "An artifact of unknown origin."));
    availableItems.push_back(Item("Dragon_Scale", "A shimmering scale shed by the dragon."));
    availableItems.push_back(Item("Treasure_Hoard", "A pile of glittering treasure guarded by the dragon."));

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Add items to rooms


    // Generate a random number between 0 and 99
    int chance = std::rand() % 100;
    // Shuffle the available items
    std::random_shuffle(availableItems.begin(), availableItems.end());

    // If the random number is less than 70 (70% chance), add an item to the room
    if (chance < 70) {
        // Select a random item from availableItems and add it to the room
        int randomIndex = std::rand() % availableItems.size();
        gameWorld.AddItemToRoom("EnchantedForest", availableItems[randomIndex]);
        gameWorld.AddItemToRoom("CrystalCavern", availableItems[(randomIndex+1)%availableItems.size()]);
        gameWorld.AddItemToRoom("WitchesDen", availableItems[(randomIndex+2)%availableItems.size()]);
        gameWorld.AddItemToRoom("ElvenLibrary", availableItems[(randomIndex+3)%availableItems.size()]);
        gameWorld.AddItemToRoom("MermaidGrotto", availableItems[(randomIndex+4)%availableItems.size()]);
        gameWorld.AddItemToRoom("DwarvesForge", availableItems[(randomIndex+5)%availableItems.size()]);
        gameWorld.AddItemToRoom("GoblinMarket", availableItems[(randomIndex+6)%availableItems.size()]);
        gameWorld.AddItemToRoom("HauntedManor", availableItems[(randomIndex+7)%availableItems.size()]);
        gameWorld.AddItemToRoom("TempleOfTheAncients", availableItems[(randomIndex+8)%availableItems.size()]);
        gameWorld.AddItemToRoom("DragonsLair", availableItems[(randomIndex+9)%availableItems.size()]);

    }

    gameWorld.AddEnemyToRoom("WitchesDen",Enemy("Wicked Witch", 50, 30));
    gameWorld.AddEnemyToRoom("MermaidGrotto",Enemy("Slimy Sea Creature", 20, 5));
    gameWorld.AddEnemyToRoom("GoblinMarket", Enemy("Goblin", 45, 30));
    gameWorld.AddEnemyToRoom("HauntedManor", Enemy("Ghastly Ghost", 65, 45));
    gameWorld.AddEnemyToRoom("DragonsLair", Enemy("Dragon", 80, 70));


    questItems.emplace_back("Legendary_Sword", "A mighty sword forged by skilled dwarven blacksmiths.");
    questItems.emplace_back("Lair_Key", "A shiny key that looks important");
    questItems.emplace_back("Ancient_Relic", "An artifact of unknown origin.");
    questItems.emplace_back("Dragon_Scale", "A shimmering scale shed by the dragon.");

    Inventory playerInventory(5);

    Player player("Player 1", 100);
    Room* currentRoom = gameWorld.GetRoom("EnchantedForest");
    player.SetLocation(currentRoom);


    while (true) {
        std::cout << "\nWelcome to Adventure Quest!\n";
        std::cout << "---------------------------------\n";
        std::cout << "- In this game, you'll embark on an epic adventure filled with mystery, danger, and excitement.\n";
        std::cout << "- Explore various rooms, search for valuable items, and complete quests to progress.\n";
        std::cout << "- But beware! Along the way, you'll encounter enemies and face challenges that test your skills.\n";
        std::cout << "- Keep an eye on your health and inventory, and use your wits to overcome obstacles.\n";
        std::cout << "- Are you ready to begin your journey?\n";
        std::cout << "---------------------------------\n";


        std::cout << "\n";
        Quest quest(questItems);
        quest.start();
        std::cout << "\n---- PLAYER SPECS ----" << std::endl;
        std::cout << "Player: " << player.GetName() << "\nHealth: " << player.GetHealth() << std::endl;
        playerInventory.displayInventory();
        playerInventory.GetCapacity();

        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }

        std::cout << "Exits available: ";
        for (const auto& exit : player.GetLocation()->GetExits()) {
            std::cout << exit.first << ", ";
        }


        std::cout << "\n";
        std::cout << "Options: " << "\n";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
            for (const Enemy& enemy : player.GetLocation()->GetEnemy()) {
                std::cout << "You have encountered a(n) " << enemy.GetName() << ": " << enemy.GetHealth() << " health points" << std::endl;
                player.TakeDamage(enemy.GetAttackPower());
                std::cout <<"\n";
            }
        } else if (choice == 2) {
            // Player interacts with an item in the room
            // check if there is an item in the room if not skip all of this
            std::cout << "Enter the name of the item you want to interact with (if there is no item press 'Q'): ";
            std::string itemName;
            std::cin >> itemName;
            for (Item& item : player.GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    if (item.Interact() == "Y") {
                        playerInventory.addItem(item);
                        // Check if the player has found the Sword
                        if (playerInventory.HasItem("Legendary_Sword") || playerInventory.HasItem("Lair_Key") || playerInventory.HasItem("Ancient_Relic") || playerInventory.HasItem("Dragon_Scale")) {
                            quest.complete();
                        }
                        player.GetLocation()->RemoveItem(item);
                    }
                    std::cout << "Would you like to use an item? (Y/N) ";
                    std::string itemToUse;
                    std::cin >> itemToUse;
                    if (itemToUse == "Y") {
                        playerInventory.UseItem(player.GetHealth(), 100);
                    }

                    break;
                } else {
                    break;
                }
            }


        } else if (choice == 3) {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south, east, west): ";
            std::string direction;
            std::cin >> direction;

            Room* nextRoom = player.GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                player.SetLocation(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        } else if (choice == 4) {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }


    }

    return 0;


}

