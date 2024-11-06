/*
 * File: room.cpp
 * Author: Kate Paskett
 * Description: Implements the room class, managing interactions with events and 
 *              players within a room in the "Hunt the Wumpus" game. Provides 
 *              functionality to set and retrieve events and players, and check 
 *              if the room is empty.
 */

#include "room.hpp"

// constructor
room::room() : this_event(nullptr), this_player(nullptr) {}

// AOO
room& room::operator = (const room& original) {
    if (this->this_event != original.this_event) {
        delete this->this_event;
        this->this_event = original.this_event;
    }
        if (this->this_player != original.this_player) {
        this->delete_player();
        this->this_player = original.this_player;
        }
        return *this;
}

// destructor to delete event
room::~room() {
    delete this_event;
}

// sets player pointer 
void room::set_player(player* p) {
    if (this_player != nullptr) { // check if player exists
        delete this_player;
    }
    this->this_player = p; // set player to room
}


// sets the event in the room
void room::set_event(event* e){
    if (this_event != nullptr) { // check if event already exists
        delete this_event; // this_event is the room event
    }
    this->this_event = e; // set the room event to new event
}

// returns the event pointer
event* room::get_event() const {
    return this_event;
}

// determines if room is empty (true = empty, false = occupied)
bool room::is_empty() const {
    if (this->this_event == nullptr && this->this_player == nullptr) { // if event is null and player is null
        return true; // room is empty
    }
    return false; // room is occupied
}

// free memory
void room::delete_player() {
    delete this_player;
    this_player = nullptr;
}