/*
 * File: arrow.cpp
 * Author: Kate Paskett
 * Description:
 *  This file contains the implementation of the `arrow` class, which represents
 *  an arrow event in the game. The arrow can be picked up by the player, and
 *  it is represented on the game board.
 */

#include "arrow.hpp"

/*
 * Function: arrow (Constructor)
 * Description: Constructs an arrow object and sets its name to "Arrow".
 */
arrow::arrow() {
    this->set_name("Arrow");
}

/*
 * Function: encounter
 * Description: Handles the interaction between the player and the arrow.
 *              The player picks up the arrow and adds it to their inventory.
 * Parameters:
 *   - p: Pointer to the player object.
 * Return:
 *   - false indicating that the arrow does not change the state of the game 
 *     beyond adding it to the player's inventory.
 */
bool arrow::encounter(player* p) {
    std::cout << "You found an arrow! It has been added to your inventory." << std::endl;
    p->pick_up_arrow();
    return false;
}

/*
 * Function: print
 * Description: Prints a representation of the arrow on the game board.
 */
void arrow::print() const {
    std::cout << "A"; 
}

/*
 * Function: percept
 * Description: Provides perceptual feedback for the arrow.
 *              Currently, this function does not output anything.
 */
void arrow::percept() const {
}
