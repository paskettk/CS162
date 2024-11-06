/*
 * File: gold.hpp
 * Author: Kate Paskett
 * Description: Declares the gold class, which represents the gold event in the 
 * "Hunt the Wumpus" game. The player can pick up the gold when they encounter it.
 */

#ifndef GOLD_HPP
#define GOLD_HPP

#include "event.hpp"
#include "player.hpp"

#include <iostream>

class gold : public event {
private:

public:
     /*
     * Function: encounter
     * Description: Handles the encounter between the player and the gold. 
     *              The player picks up the gold if they encounter it.
     * Parameters:
     *      p (player*): Pointer to the player encountering the gold.
     * Returns:
     *      bool: Always true to keep the event.
     */
    gold();

    /*
     * Function: encounter
     * Description: Handles the encounter between the player and the gold. 
     *              The player picks up the gold if they encounter it.
     * Parameters:
     *      p (player*): Pointer to the player encountering the gold.
     * Returns:
     *      bool: Always true to keep the event.
     */
    virtual bool encounter(player* p) override;

    /*
     * Function: print
     * Description: Prints the representation of the gold in the room.
     */
    virtual void print() const override;

    /*
     * Function: percept
     * Description: Prints the percept for when the player is near the gold.
     */
    virtual void percept() const override;

    /*
     * Function: pick_up
     * Description: Allows the player to pick up the gold.
     * Parameters:
     *      p (player*): Pointer to the player picking up the gold.
     */
    void pick_up(player* p);
};

#endif