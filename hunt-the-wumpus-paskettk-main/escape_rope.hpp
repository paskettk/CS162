/*
 * File: game.cpp
 * Author: Kate Paskett
 * Description:
 * Implements the `game` class, which manages the overall game state, including
 * the game board, player actions, and event interactions.
 */

#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

#include "event.hpp"
#include "player.hpp"

#include <iostream>

class escape_rope : public event {
private:
    
public:
    escape_rope();

    virtual bool encounter(player* p) override;

    virtual void print() const override;

    virtual void percept() const override;
};

#endif