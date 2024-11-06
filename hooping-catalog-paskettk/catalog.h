#ifndef CATALOG_HPP
#define CATALOG_HPP

#include <string>
#include <fstream>
#include <iostream>

// DO NOT MODIFY THIS STRUCT TYPE DEFINITION
struct team {
    std::string name; // Name of the team
    std::string owner; // Owner of the team
    int market_value; // Market value of the team
    int num_player; // Number of players in the team
	// Pointer to base address of array that holds all players
    struct player* p;
    float total_ppg; // Total points per game
};

// DO NOT MODIFY THIS STRUCT TYPE DEFINITION
struct player {
    std::string name; // Name of the player
    int age; // Age of the player
    std::string nation; // Nationality of the player
    float ppg; // Points per game of the player
    float fg; // Field goal percentage
};

/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: create_teams
 * Description: This function will dynamically allocate an array of teams
 * Parameters:
 * 		size (int): Size of the array to allocate
 * Returns: Pointer storing the base address of the allocated team array
 * Post-conditions: A team array of requested size is dynamically allocated
 * 		The responsibility of freeing this dynamic memory falls on the function
 * 		caller.
 */
team* create_teams(int size);

/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: populate_team_data
 * Description: This function will fill a single team struct with information
 * 		that is read in from the file
 * Parameters:
 * 		t (team&): Reference to the team struct to be filled with
 * 			information. NOTE: An alternative way to design this function
 *			would be to make it construct a team and return it rather
 *			than accepting one by reference and modifying it. Actually,
 *			that'd be a better idea, but use this prototype anyways as an
 *			opportunity to practice pass-by-reference.
 * 		file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the team struct
 * Post-conditions: The given team struct is populated with the next
 * 		information from the input file. This will also modify the input file's
 * 		state so that subsequent reads operate on whatever data comes after
 * 		the data read to populate the team struct.
 */
void populate_team_data(team& t, std::ifstream& file);

/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: create_players
 * Description: This function will dynamically allocate an array of players
 * Parameters:
 * 		size (int): Size of the array to allocate
 * Returns: Pointer storing the base address of the allocated player array
 * Post-conditions: A player array of requested size is dynamically allocated
 * 		The responsibility of freeing this dynamic memory falls on the function
 * 		caller.
 */
player* create_players(int size);

/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: populate_player_data
 * Description: This function will fill a single player struct with
 * 		information that is read in from the file
 * Parameters:
 * 		p (player&): Reference to the player struct to be filled with
 * 			information. NOTE: An alternative way to design this function
 *			would be to make it construct a player and return it rather
 *			than accepting one by reference and modifying it. Actually,
 *			that'd be a better idea, but use this prototype anyways as an
 *			opportunity to practice pass-by-reference.
 * 		file (std::ifstream&): Reference to the input file stream from which to
 * 			retrieve information for filling the player struct
 * Post-conditions: The given player struct is populated with the next
 * 		information from the input file. This will also modify the input file's
 * 		state so that subsequent reads operate on whatever data comes after
 * 		the data read to populate the player struct.
 */
void populate_player_data(player& p, std::ifstream& file);

/*
 * THIS IS A REQUIRED FUNCTION. DO NOT MODIFY ITS PROTOTYPE. YOU MUST
 * 		IMPLEMENT IT IN `catalog.cpp`.
 * Name: delete_info
 * Description: This function will delete all of the dynamically allocated
 * 		memory
 * Parameters:
 * 		teams (team*): Pointer to the base address of the team array
 * 		size (int): The number of teams
 * Pre-conditions: The team array at the provided pointer is valid and hasn't
 * 		been freed yet
 * Post-conditions: The team array, along with all players inside, is freed
 */
void delete_info(team* teams, int size);

/*
* Function: open_file
* Description: Prompts user to enter a filename and opens the file.
* Parameters: std::ifstream& file - input file stream.
*             std::string& filename - name of the file.
* Returns: void
* Side effects: Opens the specified file.
*/
void open_file(std::ifstream &file, std::string& filename);

/*
* Function: get_new_file_name
* Description: Prompts the user to enter a new filename.
* Parameters: None
* Returns: std::string - the entered filename.
* Side effects: Reads input from the user.
*/std::string get_new_file_name();

/*
* Function: get_num_of_teams
* Description: Reads the number of teams from the input file.
* Parameters: std::ifstream& file - input file stream.
* Returns: int - number of teams.
* Side effects: Reads from the file.
*/
int get_num_of_teams(std::ifstream& filename);

/*
* Function: choice_prompt
* Description: Prompts the user for a search choice and performs the corresponding action.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
* Returns: void
* Side effects: Reads input from the user and calls other functions based on the choice.
*/
void choice_prompt(team* teams, int num_teams);

/*
* Function: data_display_prompt
* Description: Prompts the user to choose how they want the data displayed.
* Parameters: None
* Returns: int - user's choice (1 for print to screen, 2 for write to file).
* Side effects: Reads input from the user.
*/
int data_display_prompt();

/*
* Function: data_display_choice
* Description: Displays the data based on user's choice (print to screen or write to file).
* Parameters: std::stringstream &output - stream to hold the output data.
* Returns: void
* Side effects: Outputs data to the screen or writes to a file based on user's choice.
*/
void data_display_choice(std::stringstream &output);

/*
* Function: search_team_by_name
* Description: Searches for a team by name and outputs its details.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
*             std::stringstream& output - stream to hold the output data.
* Returns: void
* Side effects: Outputs data to the stringstream.
*/
void search_team_by_name(team* teams, int num_teams);

/*
* Function: team_name_search_prompt
* Description: Prompts the user to enter a team name and validates it.
* Parameters: team* teams - pointer to the array of teams.
*             const int num_teams - number of teams.
* Returns: std::string - valid team name entered by the user.
* Side effects: Reads input from the user and validates it.
*/
std::string team_name_search_prompt(team* teams, const int num_teams);

/*
* Function: display_top_scorer
* Description: Displays the top scorer for each team.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
*             std::stringstream& output - stream to hold the output data.
* Returns: void
* Side effects: Outputs data to the stringstream.
*/
void display_top_scorer(team* teams, int num_teams, std::stringstream &output);

/*
* Function: search_by_nationality
* Description: Searches for players by nationality and outputs their details.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
*             std::stringstream& output - stream to hold the output data.
* Returns: void
* Side effects: Outputs data to the stringstream and may print a message if no players are found.
*/
void search_by_nationality(team* teams, int num_teams, std::stringstream &output);

/*
* Function: nationality_prompt
* Description: Prompts the user to enter a nationality.
* Parameters: None
* Returns: std::string - the entered nationality.
* Side effects: Reads input from the user.
*/
std::string nationality_prompt();

/*
* Function: sort_teams
* Description: Sorts teams based on total points per game.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
* Returns: void
* Side effects: Modifies the order of teams in the array.
*/
void sort_teams(team *teams, int num_teams);

/*
* Function: calculate_total_ppg
* Description: Calculates the total points per game for a team.
* Parameters: team &teams - reference to a team.
* Returns: float - total points per game for the team.
* Side effects: None
*/
float calculate_total_ppg(team &teams);

/*
* Function: search_sorted_teams
* Description: Outputs the sorted teams based on total points per game.
* Parameters: team* teams - pointer to the array of teams.
*             int num_teams - number of teams.
*             std::stringstream& output - stream to hold the output data.
* Returns: void
* Side effects: Outputs data to the stringstream.
*/
void search_sorted_teams(team *teams, int num_teams, std::stringstream &output);

#endif
