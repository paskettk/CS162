/*
 * Author: Kate Paskett
 * File: pokemon.hpp
 * Description: Header file defining the pokemon class and its associated
 *              member functions for representing and manipulating Pokémon entities.
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include <cmath>
#include "move.hpp"

class pokemon {
private: 
	// Member Variables
	std::string name;
	std::string type;
	int attack;
	int defense;
	int hp;
	int max_hp;
	int num_moves;
	bool healed;
	
    /*
     * Function: copy_moves
     * Description: Copies the moves from another pokemon instance.
     * Parameters:
     *  - original (const pokemon&): The pokemon instance to copy from.
     * Returns: void
     */
	void copy_moves(const pokemon& original);

    /*
     * Function: delete_moves
     * Description: Deletes the dynamic array of moves.
     * Returns: void
     */
	void delete_moves();

public:
	move* moves;

	/*
	 * Function: pokemon
	 * Description: Default constructor for the pokemon class.
	 */
	pokemon();

	/*
	 * Function: pokemon
	 * Description: Parameterized constructor for the pokemon class.
	 * Parameters:
	 *  - name (const std::string&): The name of the pokemon.
	 *  - type (const std::string&): The type of the pokemon.
	 *  - attack (int): The attack value of the pokemon.
	 *  - defense (int): The defense value of the pokemon.
	 *  - hp (int): The current hit points of the pokemon.
	 *  - max_hp (int): The maximum hit points of the pokemon.
	 *  - num_moves (int): The number of moves the pokemon has.
	 *  - moves (move*): The moves array.
	 *  - healed (bool): Indicates if the pokemon has healed.
	 */
	pokemon(const std::string &name, const std::string &type, int attack, 
	int defense, int hp, int max_hp, int num_moves, move* moves, bool healed);

	/*
	 * Function: pokemon
	 * Description: Copy constructor for the pokemon class.
	 * Parameters:
	 *  - original (const pokemon&): The original pokemon to copy.
	 */
	pokemon(const pokemon& original);

	/*
	 * Function: operator=
	 * Description: Assignment operator for the pokemon class.
	 * Parameters:
	 *  - original (const pokemon&): The original pokemon to assign from.
	 * Returns: pokemon& - Reference to the assigned pokemon.
	 */
	pokemon& operator = (const pokemon& original);

	/*
	 * Function: ~pokemon
	 * Description: Destructor for the pokemon class.
	 */
	~pokemon();

	/*
	 * Function: get_name
	 * Description: Returns the name of the pokemon.
	 * Returns: std::string - The name of the pokemon.
	 */
	std::string get_name() const;

	/*
	 * Function: get_type
	 * Description: Returns the type of the pokemon.
	 * Returns: std::string - The type of the pokemon.
	 */
	std::string get_type() const;

	/*
	 * Function: get_attack
	 * Description: Returns the attack value of the pokemon.
	 * Returns: int - The attack value.
	 */
	int get_attack() const;

	/*
	 * Function: get_defense
	 * Description: Returns the defense value of the pokemon.
	 * Returns: int - The defense value.
	 */
	int get_defense() const;

	/*
	 * Function: get_hp
	 * Description: Returns the current hit points of the pokemon.
	 * Returns: int - The current hit points.
	 */
	int get_hp() const;

	/*
	 * Function: take_damage
	 * Description: Calculates and applies damage to the defender pokemon.
	 * Parameters:
	 *  - defender (pokemon&): The defending pokemon.
	 *  - move_used (const move&): The move used for the attack.
	 * Returns: void
	 */
	void take_damage(pokemon& defender, const move& move_used);

	/*
	 * Function: heal
	 * Description: Heals the pokemon, increasing its hp.
	 * Returns: void
	 */
	void heal();

	/*
	 * Function: get_moves
	 * Description: Returns the array of moves.
	 * Returns: move* - Pointer to the array of moves.
	 */
	move* get_moves() const;

	/*
	 * Function: get_num_moves
	 * Description: Returns the number of moves the pokemon has.
	 * Returns: int - The number of moves.
	 */
	int get_num_moves() const;

	/*
	 * Function: has_healed
	 * Description: Checks if the pokemon has healed.
	 * Returns: bool - True if the pokemon has healed, false otherwise.
	 */
	bool has_healed() const;

	/*
	 * Function: random_critical
	 * Description: Calculates if the move is a critical hit.
	 * Returns: int - 3 for critical hit, 1 otherwise.
	 */
	int random_critical();

    /*
     * Function: random_multiplier
     * Description: Calculates a random multiplier between 0.8 and 1.2.
     * Returns: double - The multiplier value.
     */
    double random_multiplier();

    /*
     * Function: get_type_interaction
     * Description: Calculates the type interaction multiplier.
     * Parameters:
     *  - move_type (const std::string): The type of the move used.
     *  - defense_type (const std::string&): The type of the defending pokemon.
     * Returns: double - The type interaction multiplier.
     */
    double get_type_interaction(const std::string move_type, const std::string& defense_type);
};

#endif // POKEMON_HPP
