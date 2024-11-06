/*
 * File: bottomless_pit.hpp
 * Author: Kate Paskett
 * Description:
 *  This header file defines the `bottomless_pit` class, which represents a
 *  bottomless pit event in the game. The class provides functionality for handling
 *  player encounters, displaying the event on the board, and providing perceptual
 *  feedback.
 */

#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

#include "event.hpp"
#include "player.hpp"

#include <iostream>

class bottomless_pit : public event {
public:
    /*
     * Constructor: bottomless_pit
     * Description: Initializes a bottomless pit event with the name "Bottomless Pit".
     */
    bottomless_pit();

    /*
     * Function: encounter
     * Description: Handles player interaction with the bottomless pit.
     * Parameters:
     *   - p: Pointer to the player object.
     * Return: 
     *   - true if the encounter is handled successfully.
     */
    virtual bool encounter(player* p) override;

    /*
     * Function: print
     * Description: Prints a representation of the bottomless pit on the game board.
     */
    virtual void print() const override;

    /*
     * Function: percept
     * Description: Provides perceptual feedback for the bottomless pit.
     */
    virtual void percept() const override;

    /*
     * Function: random_fall
     * Description: Determines the effect of falling into the bottomless pit.
     * Return:
     *   - true if the player falls into the pit, false otherwise.
     */
    bool random_fall();
};

#endif
