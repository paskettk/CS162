/*
 * File: arrow.hpp
 * Author: Kate Paskett
 * Description:
 *  This header file defines the `arrow` class, which represents an arrow event
 *  in the game. The class provides functionality for handling player encounters,
 *  displaying the event on the board, and providing perceptual feedback.
 */

#ifndef ARROW_HPP
#define ARROW_HPP

#include "event.hpp"
#include "player.hpp"

#include <iostream>

class arrow : public event {
public:
    /*
     * Constructor: arrow
     * Description: Initializes an arrow event with the name "Arrow".
     */
    arrow();

    /*
     * Function: encounter
     * Description: Handles player interaction with the arrow.
     * Parameters:
     *   - p: Pointer to the player object.
     * Return:
     *   - true if the encounter is handled successfully.
     */
    virtual bool encounter(player* p) override;

    /*
     * Function: print
     * Description: Prints a representation of the arrow on the game board.
     */
    virtual void print() const override;

    /*
     * Function: percept
     * Description: Provides perceptual feedback for the arrow.
     */
    virtual void percept() const override;
};

#endif
