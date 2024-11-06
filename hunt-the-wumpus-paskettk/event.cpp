/*
 * File: event.cpp
 * Author: Kate Paskett
 * Description: Implements the `event` class, which is an abstract base class for different types
 * of events in the game. This file includes the implementation of non-pure-virtual
 * member functions such as setting and getting the event's name. The `return_event`
 * function is a placeholder and can be overridden in derived classes as needed. 
 */


#include "event.hpp"

// Event implementation (define non-pure-virtual event member functions below,
// if relevant)

void event::set_name(const std::string& event_name) {
    name = event_name;
}

std::string event::get_name() const {
    return this->name;
}

void event::return_event() {
}