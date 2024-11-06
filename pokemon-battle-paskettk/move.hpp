/*
 * Author: Kate Paskett
 * File: move.hpp
 * Description: Header file defining the move class and its associated
 *              member functions for representing and manipulating Pokémon moves.
 */

#ifndef MOVE_HPP
#define MOVE_HPP

#include <iostream>

class move {
private:
	// Member Variables
	std::string name;
	std::string type;
	int base_damage;
	int uses_max;
	int uses_left;
	
public:
    /*
     * Function: move
     * Description: Default constructor for the move class.
     */
	move();

    /*
     * Function: move
     * Description: Parameterized constructor for the move class.
     * Parameters:
     *  - name (const std::string&): The name of the move.
     *  - type (const std::string&): The type of the move.
     *  - base_damage (int): The base damage of the move.
     *  - uses_max (int): The maximum uses of the move.
     *  - uses_left (int): The uses left for the move.
     */
	move(const std::string &name, const std::string &type, int base_damage, int uses_max, int uses_left);

    /*
     * Function: ~move
     * Description: Destructor for the move class.
     */
	~move();

    /*
     * Function: get_name
     * Description: Returns the name of the move.
     * Returns: std::string - The name of the move.
     */
	std::string get_name() const;

    /*
     * Function: get_type
     * Description: Returns the type of the move.
     * Returns: std::string - The type of the move.
     */
	std::string get_type() const;

    /*
     * Function: get_base_damage
     * Description: Returns the base damage of the move.
     * Returns: int - The base damage.
     */
	int get_base_damage() const;

    /*
     * Function: get_uses_left
     * Description: Returns the number of uses left for the move.
     * Returns: int - The number of uses left.
     */
	int get_uses_left() const;

    /*
     * Function: use_move
     * Description: Decrements the uses left for the move.
     * Returns: void
     */
	void use_move();
};

#endif // MOVE_HPP
