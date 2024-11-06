/*
 * Author: Kate Paskett
 * File: battle.hpp
 * Description: Header file defining the battle class and its associated
 *              member functions for simulating a battle between two Pokémon.
 */

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include <cmath>
#include "pokemon.hpp"

class battle {
private:
    // Member Variables
    pokemon& pokemon1;
    pokemon& pokemon2;
    int current_turn;
    
    /*
     * Function: take_turn
     * Description: Executes a turn for the attacker pokemon.
     * Parameters:
     *  - attacker (pokemon&): The attacking pokemon.
     *  - defender (pokemon&): The defending pokemon.
     * Returns: void
     */
    void take_turn(pokemon& attacker, pokemon& defender);

    /*
     * Function: print_status
     * Description: Prints the current status of both pokemon.
     * Returns: void
     */
    void print_status() const;

    /*
     * Function: move_or_heal
     * Description: Prompts the player to choose between making a move or healing.
     * Parameters:
     *  - p (const pokemon&): The pokemon making the choice.
     * Returns: int - 1 if the player chooses to move, 2 if the player chooses to heal.
     */
    int move_or_heal(const pokemon &p);

    /*
     * Function: select_move
     * Description: Prompts the player to select a move for the attacking pokemon.
     * Parameters:
     *  - p (const pokemon&): The pokemon selecting the move.
     * Returns: int - The index of the selected move.
     */
    int select_move(const pokemon& p);

public:
    /*
     * Function: battle
     * Description: Constructor for the battle class.
     * Parameters:
     *  - pokemon1 (pokemon&): Reference to the first pokemon.
     *  - pokemon2 (pokemon&): Reference to the second pokemon.
     */
    battle(pokemon& pokemon1, pokemon& pokemon2);

    /*
     * Function: start
     * Description: Starts the battle between two pokemon.
     * Returns: void
     */
    void start();

};

#endif // BATTLE_HPP
