/*
 * File: game.hpp
 * Author: Kate Paskett
 * Description: This file contains the declaration of the game class, which 
 * provides the interface and core functionality for the "Hunt the Wumpus" 
 * game. The game class manages the game grid, handles player actions, 
 * processes events, and controls the flow of the game. Key responsibilities 
 * include player movement, firing arrows, event handling, and determining 
 * game outcomes.
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "room.hpp"
#include "event.hpp"
#include "player.hpp"

// game interface
class game {
private:
	// 2D vector of Room objects:
	// game_board[height][width]
	std::vector<std::vector<room>> game_board;

	int width;				// width of the game grid
	int height;				// height of the game grid
	bool debug;				// debug mode or not

	// pointer to the adventurer
	player* adventurer;

public:
	// Suggested functions (there are no required functions here):
	
	/*
	 * Function: Constructor
	 * Description: Constructs game object with a grid matching the given
	 * 		width and height
	 * Parameters:
	 * 		width (int): Width of the grid
	 * 		height (int): Height of the grid
	 * 		debug (bool): Whether or not debug mode should be enabled
	 */
	game(int width, int height, bool debug);

    /*
     * Function: Destructor
     * Description: Cleans up dynamically allocated memory.
     */
	~game();

	/*
	 * Function: display_game
	 * Description: Displays the game grid in the terminal
	 */
	void display_game() const;

	/*
	 * Function: check_win
	 * Description: Determines whether the player has won the game
	 * Returns (bool): True if the player has won, false otherwise
	 */
	bool check_win() const;

	/*
	 * Function: check_lose
	 * Description: Determines whether the player has lost the game
	 * Returns (bool): True if the player has lost, false otherwise
	 */
	bool check_lose() const;

	/*
	 * Function: is_direction
	 * Description: Returns true if the given character is a valid direction
	 * 		character (w/a/s/d) and false otherwise
	 * Parameters:
	 * 		c (char): The character to check
	 * Returns (bool): Boolean indicating whether the character is a valid
	 * 		direction character (w/a/s/d)
	 */
	bool is_direction(char c);

	/*
	 * Function: to_lower
	 * Description: Converts a given character to lowercase. Used to standardize
	 * 		a user's character input.
	 * Parameters:
	 * 		direction (char): Character to convert to lowercase
	 * Returns (char): Character converted to lowercase
	 */
	char to_lower(char direction);

	/*
	 * Function: can_move_in_direction
	 * Description: Determines whether the player can move in the given
	 * 		direction, based on their current location and the size of the
	 * 		grid.
	 * Parameters:
	 * 		direction (char): Direction the player wishes to move in
	 * Returns (bool): True if the player can move in the given direction
	 * 		without moving off the grid. False otherwise.
	 */
	bool can_move_in_direction(char direction);

	/*
	 * Function: is_valid_action
	 * Description: Determines whether the given action is valid.
	 * Parameters:
	 * 		action (char): Action the player wishes to perform.
	 * Returns (bool): True if the requested action is valid. False otherwise.
	 */
	bool is_valid_action(char action);

	/*
	 * Function: print_action_error
	 * Description: Prints a clear error message associated with the user's
	 * 		provided invalid action
	 * Parameters:
	 * 		action (char): Invalid action that the user requested
	 */
	void print_action_error(char action);

	/*
	 * Function: get_player_action
	 * Description: Prompts the player for their action for the turn and
	 * 		returns it as a char (w, a, s, d, or f). If the player enters
	 * 		an invalid action, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid action provided by the player.
	 */
	char get_player_action();

	/*
	 * Function: get_arrow_fire_direction
	 * Description: Prompts the player for the direction they want to fire an
	 * 		arrow (w, a, s, or d) and returns it as a char. If the player enters
	 * 		an invalid direction, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid direction provided by the player.
	 */
	char get_arrow_fire_direction();

	/*
	 * Function: move_up
	 * Description: Moves the player up one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_up();

	/*
	 * Function: move_down
	 * Description: Moves the player down one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_down();

	/*
	 * Function: move_left
	 * Description: Moves the player left one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_left();

	/*
	 * Function: move_right
	 * Description: Moves the player right one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_right();

	/*
	 * Function: move
	 * Description: Moves the player in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to move the player (a for
	 * 			west, s for south, d for east, w for north).
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move(char direction);

	/*
	 * Function: fire_arrow_up
	 * Description: Fires an arrow upward
	 * Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_up();

	/*
	 * Function: fire_arrow_down
	 * Description: Fires an arrow downward
	 * Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_down();

	/*
	 * Function: fire_arrow_left
	 * Description: Fires an arrow leftward
	 * Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_left();

	/*
	 * Function: fire_arrow_right
	 * Description: Fires an arrow rightward
	 * Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_right();

	/*
	 * Function: fire_arrow
	 * Description: Fires an arrow in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to fire arrow (a for
	 * 			west, s for south, d for east, w for north).
	 * Post-condition: Arrow is fired. Wumpus is killed if hit and moves if
	 * 		missed.
	 */
	void fire_arrow(char direction);

	/*
	 * Function: play_game
	 * Description: Runs one full iteration of the game
	 */
	void play_game();

    /*
     * Function: check_for_empty_room
     * Description: Checks if a room at given coordinates is empty.
     * Parameters:
     *      x (int): The x-coordinate of the room to check
     *      y (int): The y-coordinate of the room to check
     * Returns:
     *      bool: True if the room is empty, false otherwise.
     */
	bool check_for_empty_room(int x, int y);

    /*
     * Function: place_event
     * Description: Places an event in a random empty room.
     * Parameters:
     *      event (event*): Pointer to the event to place
     */
	void place_event(event* event);
	

    /*
     * Function: place_player
     * Description: Places the player at the given coordinates.
     * Parameters:
     *      x (int): The x-coordinate to place the player
     *      y (int): The y-coordinate to place the player
     *      player (player*): Pointer to the player object
     */
	void place_player(int x, int y, player* player);

    /*
     * Function: print_percepts
     * Description: Prints the percepts for the current room.
     */
	void print_percepts();

    /*
     * Function: trigger_event
     * Description: Triggers the event in the current room.
     */
	void trigger_event();

    /*
     * Function: random_move
     * Description: Randomly moves the Wumpus to an empty room.
     */
	void random_move();

	/*
	* Function: move_wumpus
	* Description: Moves the Wumpus to a random empty room after the player misses with an arrow.
	*/
		void move_wumpus();

	/*
	* Function: arrow_hit_wall_msg
	* Description: Displays a message when the player's arrow hits a wall.
	*/
	void arrow_hit_wall_msg();

	/*
	* Function: arrow_missed_wumpus_msg
	* Description: Displays a message when the player's arrow misses the Wumpus.
	*/
	void arrow_missed_wumpus_msg();

	/*
	* Function: arrow_killed_wumpus_msg
	* Description: Displays a message when the player's arrow kills the Wumpus.
	*/
	void arrow_killed_wumpus_msg();
};

#endif