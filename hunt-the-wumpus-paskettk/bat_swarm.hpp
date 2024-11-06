/*
File: game.cpp
Author: Kate Paskett
Description:
*/

#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

#include "event.hpp"
#include "player.hpp"

#include <iostream>

class bat_swarm : public event {
private:
public:

    /*
     * Function: encounter
     * Description: Handles the encounter between the player and the bat swarm. 
     *              The player is moved to a random room.
     * Parameters:
     *      p (player*): Pointer to the player encountering the bat swarm.
     * Returns:
     *      bool: Always true to keep the event.
     */

    virtual bool encounter(player* p) override;

    /*
     * Function: print
     * Description: Prints the representation of the bat swarm in the room.
     */

    virtual void print() const override;

    /*
     * Function: percept
     * Description: Prints the percept for when the player is near the bat swarm.
     */
     
    virtual void percept() const override;
};

#endif