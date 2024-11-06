/*
 * File: game.cpp
 * Author: Kate Paskett
 * Description:
 * This file contains the implementation of the `escape_rope` class, which is a subclass
 * of the `event` class.
*/

#include "escape_rope.hpp"

escape_rope::escape_rope() {
    this->set_name("Escape Rope");
}

bool escape_rope::encounter(player* p){
    std::cout << "You have encountered the escape rope!" << std::endl;
    // option to escape if gold is aquired
    if (p->check_for_gold() == true) {
        int selection;
        do {
        std::cout << "You have the gold! Would you like to escape?\n"
                    "(1 = yes, 0 = no): " << std::endl;
                    std::cin >> selection;
        if (selection == 1) {
            std::cout << "\nCongratulations! You escaped with the gold!" << std::endl;
            p->set_win();
        } else if (selection == 0) {
            std::cout << "\nYou have decided to stay in the cave. Good Luck!" << std::endl;
        } else {
            std::cout << "Please enter a valid option." << std::endl;
        }
        } while (selection != 1 && selection != 0);
    } else {
        std::cout << "You don't have any gold yet, try again once you've found it!" << std::endl;
    }
    return true;
}

void escape_rope::print() const {
    std::cout << "E";
}

void escape_rope::percept() const {
}