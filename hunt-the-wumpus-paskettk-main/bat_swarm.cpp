/*
 * File: bat_swarm.cpp
 * Author: Kate Paskett
 * Description:
 *  This file contains the implementation of the `bat_swarm` class, which represents
 *  a bat swarm event in the game. It handles player encounters with the bat swarm,
 *  prints a representation of the event, and provides perceptual feedback.
 */

#include "bat_swarm.hpp"

/*
 * Function: encounter
 * Description: Handles the interaction between the player and the bat swarm.
 *              The player becomes confused as a result of the encounter.
 * Parameters:
 *   - p: Pointer to the player object.
 * Return:
 *   - true if the encounter is handled successfully.
 */
bool bat_swarm::encounter(player* p) {
    std::cout << "You discover a bat swarm! You become confused..." << std::endl;
    p->become_confused();
    return true;
}

/*
 * Function: print
 * Description: Prints a representation of the bat swarm on the game board.
 */
void bat_swarm::print() const {
    std::cout << "B";
}

/*
 * Function: percept
 * Description: Provides perceptual feedback for the bat swarm.
 *              The player hears wings flapping in the vicinity.
 */
void bat_swarm::percept() const {
    std::cout << "You hear wings flapping." << std::endl;
}