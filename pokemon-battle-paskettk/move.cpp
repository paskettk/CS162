/*
 * Author: Kate Paskett
 * File: move.cpp
 * Description: Implementation of the member functions of the move class,
 *              which represents the moves used by Pokémon during battle.
 */

#include "move.hpp"

// TODO Implement member functions of the move class

// dedault constructor definition
move::move() : name(""), type(""), base_damage(0), uses_max(0), uses_left(0) {
}

// destructor definition
move::~move() {
}

// constructor definition
move::move(const std::string &name, const std::string &type, int base_damage, int uses_max, int uses_left) 
    // initialization list
    : name(name), type(type), base_damage(base_damage), uses_max(uses_max), uses_left(uses_left) {}

// member functions
std::string move::get_name() const {
    return name;
}

std::string move::get_type() const {
    return type;
}

int move::get_base_damage() const {
    return base_damage;
}

int move::get_uses_left() const {
    return uses_left;
}

void move::use_move() {
    if (uses_left > 0) {
    uses_left -= 1;
    }
}