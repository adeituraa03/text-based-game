#pragma once

#include <iostream>
#include "roomClass.hpp"

class Quest {
private:
    std::vector<Item> Items;
    int totalQuests = 4;
    int completedQuests = 0;


public:
    enum Status { NotStarted, InProgress, Completed };
    Status status;

    Quest(const std::vector<Item>& Items) : status(NotStarted), Items(Items) {}


    void setItems(const std::vector<Item>& items);
    void start();
    void update(const std::vector<Item>& foundItems);
    void complete();
};
