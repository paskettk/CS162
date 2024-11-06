/*
 * File: player.cpp
 * Author: Kate Paskett
 * Description: Defines player class functions
*/

#include "player.hpp"

// member functions:

// default constructor
player::player() : column(0), row(0) {}

// assignment operator overload
player& player::operator = (const player& original) {
    this->column = original.column;
    this->row = original.row;
    this->num_arrows = original.num_arrows;
    this->have_gold = original.have_gold;
    this->win = original.win;
    this->lose = original.lose;
    this->remove_event = original.remove_event;
    return *this;
}

// destructor
player::~player() {}

// returns player row
int player::get_row() {
    return this->row;
}

// returns player comlumn
int player::get_column() {
    return this->column;
}

// returns number of arrows
int player::get_num_arrows() {
    return this->num_arrows;
}

// update player location
void player::update_location(int new_column, int new_row) {
    this->column = new_column; // width
    this->row = new_row; // height
}

// decreases arrows by 1
void player::use_arrow() {
    if (num_arrows > 0) {
        this->num_arrows -= 1;
    } else {
        std::cout << "You have no arrows!" << std::endl;
    }
}

void player::pick_up_gold() {
    this->have_gold = true;
}

bool player::check_for_gold() {
    if (have_gold == true) {
        return true;
    } else {
        return false;
    }
}

void player::pick_up_arrow() {
    this->num_arrows += 1;
}

void player::become_confused() {
    if (is_confused == false) {
        this->is_confused = true;
    }
}

void player::set_unconfused() {
    this->is_confused = false;
}

bool player::check_confused() {
    if (this->is_confused == true) {
        return true;
    } else {
    return false; 
    }
}


// return win result
bool player::get_win() {
    return this->win;
}

// return lose result
bool player::get_lose() {
    return this->lose;
}

// sets win = true
void player::set_win() {
    this->win = true;
}

// sets lose = true
void player::set_lose() {
    this->lose = true;
}
