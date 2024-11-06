/*
 * File: wumpus.hpp
 * Author: Kate Paskett
 * Description: Declares the wumpus class, which represents the Wumpus in the 
 * "Hunt the Wumpus" game. The Wumpus is an event that can be encountered by 
 * the player, leading to a loss if the Wumpus is awoken.
 */

#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include "event.hpp"
#include "player.hpp"
#include <iostream>

// Wumpus class interface
class wumpus : public event {
public:
    /*
     * Function: wumpus (Constructor)
     * Description: Constructs a wumpus object and sets its name.
     */
    wumpus();

    /*
     * Function: ~wumpus (Destructor)
     * Description: Destructor for the wumpus object.
     */
    ~wumpus() override = default;

    /*
     * Function: encounter
     * Description: Handles the player's encounter with the Wumpus. If the player
     *              enters the room with the Wumpus, the player loses the game.
     * Parameters:
     *      p (player*): A pointer to the player object that encountered the Wumpus.
     * Returns:
     *      bool: True if the encounter occurs.
     */
    bool encounter(player* p) override;

    /*
     * Function: print
     * Description: Prints the symbol representing the Wumpus ('W') in the cave.
     */
    void print() const override;

    /*
     * Function: percept
     * Description: Outputs a perceptual clue indicating that the player is near 
     *              the Wumpus ("You smell a terrible stench.").
     */
    void percept() const override;
};

#endif
