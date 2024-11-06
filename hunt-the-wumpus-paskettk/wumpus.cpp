/*
 * File: wumpus.cpp
 * Author: Kate Paskett
 * Description: Implements the wumpus class, which represents the Wumpus 
 * creature in the "Hunt the Wumpus" game. The Wumpus has specific behavior when 
 * encountered by the player, and it also provides a percept for nearby rooms.
 */

#include "wumpus.hpp"

wumpus::wumpus() {
    this->set_name("Wumpus");
}

bool wumpus::encounter(player* p) {
    std::cout << "Uh oh! You have awoken the Wumpus!" << std::endl;
    p->set_lose();
    return true;
}

void wumpus::print() const {
    std::cout << "W";
}

void wumpus::percept() const {
    std::cout << "You smell a terrible stench." << std::endl;
}