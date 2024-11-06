/*
 * File: gold.cpp
 * Author: Kate Paskett
 * Description: Implements the gold class, handling interactions between the 
 *              player and gold in the "Hunt the Wumpus" game. Defines the behavior 
 *              for encountering, printing, and perceiving gold. Includes functionality 
 *              for picking up the gold and updating the player's status.
 */

#include "gold.hpp"

gold::gold() {
    this->set_name("Gold");
}

bool gold::encounter(player* p){
    std::cout << "You found gold! You pick it up and take it with you." << std::endl;
    pick_up(p);
    return false;
}

void gold::print() const {
    std::cout << "G";
}

void gold::percept() const {
    std::cout << "You see something shimmer nearby." << std::endl;
}

void gold::pick_up(player* p) {
    p->pick_up_gold();
}