/*
File: game.cpp
Author: Kate Paskett
Description:
*/

#include "bottomless_pit.hpp"

bottomless_pit::bottomless_pit() {
    this->name = "Bottomless Pit";
}

bool bottomless_pit::encounter(player* p) {
    std::cout << "You encounter a bottomless pit!" << std::endl;
    if (random_fall() == true) {
        std::cout << "You slip but catch your balance! That was a close call." << std::endl;
    } else {
        std::cout << "You lose your balance and slip into the pit!" << std::endl;
        p->set_lose();
    }
    return true;
}

void bottomless_pit::print() const {
    std::cout << "P";
}

void bottomless_pit::percept() const {
    std::cout << "You feel a breeze." << std::endl;
}

bool bottomless_pit::random_fall() {
    int num = (rand() % 2);
    if (num == 1) {
        return true;
    } else {
        return false;
    }
}
