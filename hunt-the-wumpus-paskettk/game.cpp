/*
 * File: game.cpp
 * Author: Kate Paskett
 * Description: Implements the `game` class, which manages the state and behavior of
 * the "Hunt the Wumpus" game. Includes functionality for setting up the game
 * board, managing player actions, handling events, and updating game state.
 */

#include <iostream>

#include "game.hpp"

#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

// game implementation

// game constructor
game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug),
		adventurer(new player()) {
			
	// Create the game board: 2D vector of room objects
	// game_board[height][width (inner vector)]
	game_board.resize(height, std::vector<room>(width)); 

	// Randomly insert events (2 bat_swarms, 2 bottomless_pits,
	// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board

	place_event(new wumpus());
	place_event(new gold());

 	// places player in same place
	place_event(new escape_rope());
	
	place_event(new bat_swarm());
	place_event(new bat_swarm());

	place_event(new bottomless_pit());
	place_event(new bottomless_pit());

	place_event(new arrow());
	place_event(new arrow());

	}

// destructor
game::~game() {
	game_board.clear();
	delete adventurer;
}

void game::display_game() const {

	std::cout << std::endl << std::endl;
	std::cout << "Arrows remaining: " << adventurer->get_num_arrows() << std::endl;

	std::string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	std::cout << row_border << std::endl;


	for (int i = 0; i < this->height; ++i) { // (num of rows)
		std::cout << "||";
		for (int j = 0; j < this->width; ++j) { // (num of columns)
			// The first char indicates whether there is a player in the room
			// at row index i, column index j. TODO If the room contains the
			// player, print an asterisk ("*")

			if (adventurer->get_row() == i && adventurer->get_column() == j) {
				std::cout << "*";
 			} else { // else, print a space (" ")
				std::cout << " ";
			}
			// The next char indicates the event in the room.
			
			// If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			if (!this->debug || (game_board[i][j].is_empty() == true) // if debug is disables or room is empty
		    ) { // or if adventurer is in the room
				std::cout << " ";
			} else if (game_board[i][j].get_event() != nullptr) {
				// else, print debug symbol
				game_board.at(i).at(j).get_event()->print();
			} else {
				std::cout << " ";
			}

			std::cout << " ||";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}
}

bool game::check_win() const{
	// Return true if the player has won the game. Return false otherwise.

	if (adventurer->get_win() == true) {
		std::cout << "You won!" << std::endl;
		return true;
	} else {
		return false;
	}
}

bool game::check_lose() const{
	// Return true if the player has lost the game. Return false otherwise.

	if (adventurer->get_lose() == true) {
		std::cout << "You lost!" << std::endl;
		return true;
	} else {
		return false;
	}
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction) {
	// Return true if the player can move in the given direction.
	// Return false otherwise. The player can move in the given
	// direction so long as it wouldn't cause them to move off the grid

	int player_column = adventurer->get_column(); // width
	int player_row = adventurer->get_row(); // height

	if (direction == 'w') { // up
		if (player_row > 0) { // player is not at top boundary
			return true;
		}

	} else if (direction == 's') { // down
		if (player_row < height - 1) { // player is not at the bottom
			return true;
		}
	
	} else if (direction == 'd') { // right
		if (player_column < width - 1) { // player is not at left boundary
			return true;
		}

	} else if (direction == 'a') { // left
		if (player_column > 0) { // player is not at right boundary
			return true;
		}
	}
	return false;
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return adventurer->get_num_arrows() > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "You can't move in that direction!" << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "You're out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "That's an invalid input!" << std::endl
			<< std::endl;
	}
}

char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would you like to do?" <<
			std::endl << std::endl;
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "f: fire an arrow" << std::endl;

		std::cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "That's an invalid input!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"What direction would you like to fire the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

// move player up one row
void game::move_up() { // 'w'
    int c = adventurer->get_column(); // Get current column (x-coordinate/width)
    int r = adventurer->get_row();    // Get current row (y-coordinate/height)

    if (can_move_in_direction('w')) { // Check if the move is valid
        adventurer->update_location(c, r - 1); // Move up (decrease row index)
    } else {
        print_action_error('w'); // Print error if move is invalid
    }
}

// move player down one row
void game::move_down() { // 's'
    int c = adventurer->get_column(); // Get current column (x-coordinate)
    int r = adventurer->get_row();    // Get current row (y-coordinate)

    if (can_move_in_direction('s')) { // Check if the move is valid
        adventurer->update_location(c, r + 1); // Move down (increase row index)
    } else {
        print_action_error('s'); // Print error if move is invalid
    }
}

// move player left one column space
void game::move_left() { // 'a'
    int c = adventurer->get_column(); // Get current column (x-coordinate)
    int r = adventurer->get_row();    // Get current row (y-coordinate)

    if (can_move_in_direction('a')) { // Check if the move is valid
        adventurer->update_location(c - 1, r); // Move left (decrease column index)
    } else {
        print_action_error('a'); // Print error if move is invalid
    }
}

// move player right one column space
void game::move_right() { // 'd'
    int c = adventurer->get_column(); // Get current column (x-coordinate)
    int r = adventurer->get_row();    // Get current row (y-coordinate)

    if (can_move_in_direction('d')) { // Check if the move is valid
        adventurer->update_location(c + 1, r); // Move right (increase column index)
    } else {
        print_action_error('d'); // Print error if move is invalid
    }
}

void game::move(char direction) {
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 'd') {
		this->move_right();
	} else {
		this->move_down();
	}
}

void game::random_move() {
	int move = rand() % 4;
	if (move == 0) {
		this->move_up();
	} else if (move == 1) {
		this->move_left();
	} else if (move == 2) {
		this->move_right();
	} else if (move == 3) {
		this->move_down();
	} else {
		return;
	}
	std::cout << "\nYour confusion leads you to a random room!" << std::endl;
}

void game::fire_arrow_up() {
    int c = adventurer->get_column();
    int r = adventurer->get_row();

    for (int i = 1; i <= 3; i++) { // arrow moves up 3 rooms
        r -= 1;
        if (r < 0) { // arrow hits wall (out of bounds)
            arrow_hit_wall_msg();
            return;
        }
        auto event = game_board.at(r).at(c).get_event();
        if (event != nullptr && event->get_name() == "Wumpus") { // event is Wumpus
            arrow_killed_wumpus_msg();
            adventurer->set_win();
            return; // exit the function
        }
    }
    // arrow does not hit the Wumpus
    arrow_missed_wumpus_msg();
    move_wumpus();
}

void game::fire_arrow_down() {
    int c = adventurer->get_column();
    int r = adventurer->get_row();

    for (int i = 1; i <= 3; i++) { // arrow moves down 3 rooms
        r += 1;
        if (r >= height) { // arrow hits wall (out of bounds)
            arrow_hit_wall_msg();
            return;
        }
        auto event = game_board.at(r).at(c).get_event();
        if (event != nullptr && event->get_name() == "Wumpus") { // event is Wumpus
            arrow_killed_wumpus_msg();
            adventurer->set_win();
            return; // exit the function
        }
    }
    // arrow does not hit the Wumpus
    arrow_missed_wumpus_msg();
    move_wumpus();
}

void game::fire_arrow_left() {
    int c = adventurer->get_column();
    int r = adventurer->get_row();

    for (int i = 1; i <= 3; i++) { // arrow moves left 3 rooms
        c -= 1;
        if (c < 0) { // arrow hits wall (out of bounds)
            arrow_hit_wall_msg();
            return;
        }
        auto event = game_board.at(r).at(c).get_event();
        if (event != nullptr && event->get_name() == "Wumpus") { // event is Wumpus
            arrow_killed_wumpus_msg();
            adventurer->set_win();
            return; // exit the function
        }
    }
    // arrow does not hit the Wumpus
    arrow_missed_wumpus_msg();
    move_wumpus();
}

void game::fire_arrow_right() {
    int c = adventurer->get_column();
    int r = adventurer->get_row();

    for (int i = 1; i <= 3; i++) { // arrow moves right 3 rooms
        c += 1;
        if (c >= width) { // arrow hits wall (out of bounds)
            arrow_hit_wall_msg();
            return;
        }
        auto event = game_board.at(r).at(c).get_event();
        if (event != nullptr && event->get_name() == "Wumpus") { // event is Wumpus
            arrow_killed_wumpus_msg();
            adventurer->set_win();
            return; // exit the function
        }
    }
    // arrow does not hit the Wumpus
    arrow_missed_wumpus_msg();
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 's') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}
	adventurer->use_arrow();
}

void game::play_game () {

	while (!this->check_win() && !this->check_lose()) {

		// Print game board
		this->display_game();

		// TODO Display precepts around player's location
		this->print_percepts();

		// Ask player for their action
		char action = this->get_player_action();
		
		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;

			if (adventurer->check_confused() == true) {

				random_move();
				adventurer->set_unconfused();
						
			} else {
				this->move(direction);
			}
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}
		// If the user is on a space with an event, trigger its encounter
		int c = adventurer->get_column();
		int r = adventurer->get_row();
		this->trigger_event();
		move_wumpus();

	} 
	game_board.clear();
}

// checks if position is occupied: true = empty, false = occupied
bool game::check_for_empty_room(int r, int c) {
	if (game_board.at(r).at(c).is_empty() == true) { // if room is empty
		return true; // true = empty
	}
	return false; // false = occupied
}

// randomly places event on an unoccupied position
void game::place_event(event* event) {
	int c, r;

	do {
		c = rand() % width;
		r = rand() % height;
	} while (check_for_empty_room(r, c) == false); // continue checking until unoccupied room is found 

	game_board.at(r).at(c).set_event(event);

	if (event->get_name() == "Escape Rope") {
		place_player(c, r, adventurer);
	}
}

void game::place_player(int c, int r, player* player) {
	adventurer->update_location(c, r);
	game_board.at(r).at(c).set_player(player);
}

// call percepts for adjacent events
void game::print_percepts() {
    int player_column = adventurer->get_column();
	int player_row = adventurer->get_row();
    
    // define the relative positions for adjacent rooms
    int directions[4][2] = {
        {0, -1}, // up
        {0, 1},  // down
        {-1, 0}, // left
        {1, 0}   // right
    };

    for (const auto& direction : directions) {
        int new_column = player_column + direction[0]; // player column + x component
        int new_row = player_row + direction[1]; // player row + y component
        
        // check if the new position is within the bounds of the grid
        if (new_row >= 0 && new_row < height && new_column >= 0 && new_column < width) {
            // check if there is an event in the adjacent room
            room& adjacent_room = game_board[new_row][new_column];
            if (adjacent_room.get_event() != nullptr) {
                adjacent_room.get_event()->percept(); 
            }
        } else {
			std::cout << "";
		}
    }
}

// call encounter function for room events
void game::trigger_event() {
	// if game is over, return 
	if (adventurer->get_win() == true || adventurer->get_lose() == true) {
		return;	
	}

    int c = adventurer->get_column();
    int r = adventurer->get_row();

    if (c >= 0 && c < width && r >= 0 && r < height) {
		room& current_room = game_board.at(r).at(c);
		event* current_event = current_room.get_event();
        if (current_event != nullptr) {
            // Trigger the event
			std::cout << std::endl;

			// set event to nullptr if it is picked up (returns false)
			if (current_event->encounter(adventurer) == false) {
				current_room.set_event(nullptr);
				current_event = nullptr;
			}
        }
    }
}

void game::move_wumpus() {
    int wumpus_r = -1, wumpus_c = -1;

    // find wumpus location
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            auto event = game_board.at(i).at(j).get_event();
            if (event != nullptr && event->get_name() == "Wumpus") {
                wumpus_r = i;
                wumpus_c = j;
                break;
            }
        }
        if (wumpus_r != -1) break; // Break out of the outer loop if Wumpus is found
    }

    if (wumpus_r == -1) {
        std::cerr << "Error: Wumpus not found!" << std::endl;
        return; // Exit if Wumpus was not found
    }

    // move location
    int new_r, new_c;
    do {
        new_c = rand() % width;
        new_r = rand() % height;
    } while (!check_for_empty_room(new_r, new_c)); // continue checking until unoccupied room is found 

    game_board.at(wumpus_r).at(wumpus_c).set_event(nullptr); // Remove Wumpus from current room
    game_board.at(new_r).at(new_c).set_event(new wumpus()); // Add new Wumpus to the new room

    std::cout << "The Wumpus has moved to a new room!" << std::endl;
}


void game::arrow_hit_wall_msg() {
	std::cout << "\nOops! Your arrow hit a wall!" << std::endl;
}

void game::arrow_missed_wumpus_msg() {
	std::cout << "\nUh oh, Your arrow missed the Wumpus! He has woken up and moved to a different room!" << std::endl;
}

void game::arrow_killed_wumpus_msg() {
    std::cout << "\nWow! Your arrow has killed the Wumpus!" << std::endl;
}