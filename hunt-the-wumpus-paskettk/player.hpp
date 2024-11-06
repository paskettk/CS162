/* 
 * File: player.cpp
 * Author: Kate Paskett
 * Description: Declares the player class, which represents the player 
 * character in the "Hunt the Wumpus" game. The player tracks their location 
 * in the cave, the number of arrows they have, whether they possess gold, 
 * and their win/loss status.
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class player {
private:
    int column; // x coordinate (width)
    int row; // y coordinate (height)
    int num_arrows = 0;
    bool have_gold = false;
    bool is_confused = false;
    bool win = false;
	bool lose = false;
    bool remove_event;

public:
    /*
     * Function: player (Constructor)
     * Description: Constructs a player object with default values.
     */
    player();

    /*
     * Function: ~player (Destructor)
     * Description: Destructor for the player object.
     */
    ~player();

    /*
     * Function: operator= (Assignment Operator)
     * Description: Assigns the contents of one player object to another.
     * Parameters:
     *      original (const player&): The player object to copy
     * Returns:
     *      player&: A reference to the assigned player object.
     */
    player& operator = (const player& original);

    /*
     * Function: get_row
     * Description: Retrieves the row position of the player.
     * Returns:
     *      int: The row position of the player.
     */
    int get_row();

    /*
     * Function: get_column
     * Description: Retrieves the column position of the player.
     * Returns:
     *      int: The column position of the player.
     */
    int get_column();

    /*
     * Function: get_num_arrows
     * Description: Retrieves the number of arrows the player has.
     * Returns:
     *      int: The number of arrows.
     */
    int get_num_arrows();

    /*
     * Function: update_location
     * Description: Updates the player's position in the cave.
     * Parameters:
     *      new_column (int): The new x coordinate (width)
     *      new_row (int): The new y coordinate (height)
     */
    void update_location(int new_column, int new_row);

    /*
     * Function: pick_up_gold
     * Description: Sets the player's status to indicate they have picked up gold.
     */
    void pick_up_gold();

    /*
     * Function: check_for_gold
     * Description: Checks if the player has picked up gold.
     * Returns:
     *      bool: True if the player has gold, false otherwise.
     */
    bool check_for_gold();

    /*
     * Function: pick_up_arrow
     * Description: Increases the player's arrow count by one when they pick up an arrow.
     */
    void pick_up_arrow();

    /*
     * Function: use_arrow
     * Description: Decreases the player's arrow count by one when they use an arrow.
     */
    void use_arrow();

    /*
     * Function: become_confused
     * Description: Sets the player's confused status to true, indicating they are disoriented.
     */
    void become_confused();

    /*
     * Function: set_unconfused
     * Description: Sets the player's confused status to false, indicating they are no longer disoriented.
     */
    void set_unconfused();

    /*
     * Function: check_confused
     * Description: Checks if the player is currently confused.
     * Returns:
     *      bool: True if the player is confused, false otherwise.
     */
    bool check_confused();

    /*
     * Function: get_win
     * Description: Checks if the player has won the game.
     * Returns:
     *      bool: True if the player has won, false otherwise.
     */
    bool get_win();

    /*
     * Function: get_lose
     * Description: Checks if the player has lost the game.
     * Returns:
     *      bool: True if the player has lost, false otherwise.
     */
    bool get_lose();

    /*
     * Function: set_win
     * Description: Sets the player's win status to true.
     */
    void set_win();

    /*
     * Function: set_lose
     * Description: Sets the player's lose status to true.
     */
    void set_lose();
};

#endif