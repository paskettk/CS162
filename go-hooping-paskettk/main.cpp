/************************
** Program: hooping.cpp
** Author: Kate Paskett
** Date: 07/08/2024
** Description: A program to calculate the rack shoots of basketball game
** Input: num of players, moneyball shot, and play again msg
** Output: the result of the shot and the winner among players.
*********************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

const int num_rows = 7; // Number of racks
const int num_cols = 5; // Number of shots per rack

// Function to prompt for moneyball rack input
/*
* Function: mb_rack_prompt
* Description: Prompts the user to enter their moneyball rack selection (1-5).
* Parameters: None
* Returns: The selected moneyball rack number.
* Side effects: Outputs messages to the console.
*/
int mb_rack_prompt() {
    int mb_rack = 0;
    do {
        std::cout << "Enter your moneyball rack (1-5): ";
        std::cin >> mb_rack;
        if (mb_rack < 1 || mb_rack > 5) {
            std::cout << "Wrong input, please enter a number within the limits." << std::endl;
        }
    } while (mb_rack < 1 || mb_rack > 5);
    return mb_rack;
}

// Function to prompt for number of players
/*
* Function: num_of_players
* Description: Prompts the user to enter the number of players for the game.
* Parameters: None
* Returns: The number of players entered by the user.
* Side effects: Outputs messages to the console.
*/
int num_of_players() {
    int num_players = 0;
    std::cout << "Enter the number of players: ";
    std::cin >> num_players;
    return num_players;
}

// Function to allocate players' scores array
/*
* Function: allocate_players
* Description: Allocates memory for an array to store scores for each player.
* Parameters:
*   num_players - Number of players for whom the array should be allocated.
* Returns: Pointer to the allocated array of player scores.
* Side effects: Allocates memory dynamically.
*/
int* allocate_players(int num_players) {
    int* players_array = new int[num_players]();
    return players_array;
}

// Function to populate shot results randomly
/*
* Function: populate_array
* Description: Generates random shot results for each rack.
* Parameters: None
* Returns: Pointer to a 2D array representing shot results for each rack.
* Side effects: Allocates memory dynamically and uses random number generation.
*/
bool** populate_array() {
    bool** shot = new bool*[num_rows];
    for (int i = 0; i < num_rows; ++i) {
        shot[i] = new bool[num_cols];
        for (int j = 0; j < num_cols; ++j) {
            shot[i][j] = (rand() % 2 == 1); // Generate random results
        }
    }
    return shot;
}

// Function to display results and calculate scores
/*
* Function: display_results
* Description: Displays the results of shots for each rack, calculates scores, and prints total score.
* Parameters:
*   shot - 2D array representing shot results for each rack.
*   mb_rack - Moneyball rack selected by the player.
*   num_rows - Number of racks.
*   num_cols - Number of shots per rack.
* Returns: Total score for the player.
* Side effects: Outputs messages to the console.
*/
int display_results(bool** shot, int mb_rack, int num_rows, int num_cols) {
    int total_score = 0;

    for (int i = 0; i < num_rows; ++i) {
        std::cout << "Rack " << i + 1 << ": ";
        int rack_score = 0;
        // Print rack shots
        for (int j = 0; j < num_cols; ++j) {
            if (i == mb_rack - 1 || j == 4) {
                std::cout << "M ";
                rack_score += 2;
            } else if (shot[i][j]) {
                std::cout << "O ";
                rack_score += 1;
            } else {
                std::cout << "_ ";
            }
        }

        std::cout << " | " << rack_score << " pts" << std::endl;
        total_score += rack_score;

        // Print starry ball rack
        if (i == 1 || i == 2) {
            std::cout << "Starry: ";
            int rack_score = 0;
            if (shot[i][0]) {
                std::cout << "S ";
                rack_score += 3;
            } else {
                std::cout << "_ ";
            }
            std::cout << "         | " << rack_score << " pts" << std::endl;
            total_score += rack_score;
            num_rows -= 1;
        }
    }
    std::cout << "Total Score: " << total_score << std::endl;
    return total_score;
}

// Function to determine if players want to play again
/*
* Function: play_again
* Description: Prompts the user to decide if they want to play another round.
* Parameters: None
* Returns: True if the user wants to play again, false otherwise.
* Side effects: Outputs messages to the console.
*/
bool play_again() {
    int answer;
    std::cout << "Would you like to play again? (type 1 for yes, 0 for no): ";
    std::cin >> answer;
    return answer == 1;
}

// Function to find the index of the winner based on scores
/*
* Function: find_winner
* Description: Finds the index of the player with the highest score.
* Parameters:
*   players_array - Array containing scores of all players.
*   num_players - Number of players in the game.
* Returns: Index (1-based) of the player with the highest score.
* Side effects: None.
*/
int find_winner(int* players_array, int num_players) {
    int winner_index = 0;
    for (int i = 1; i < num_players; ++i) {
        if (players_array[i] > players_array[winner_index]) {
            winner_index = i;
        }
    }
    return winner_index + 1; // Adjust index to player number
}

int main() {
    srand(time(nullptr)); // Seed the random number generator

    do {
        int num_players = num_of_players();
        int* players_array = allocate_players(num_players);

        for (int i = 0; i < num_players; ++i) {
            std::cout << "Player " << i + 1 << std::endl;

            int mb_rack = mb_rack_prompt();
            bool** results = populate_array();
            int player_score = display_results(results, mb_rack, num_rows, num_cols);
            players_array[i] += player_score;

            // Clean up allocated memory
            for (int j = 0; j < num_rows; ++j) {
                delete[] results[j];
            }
            delete[] results;
        }

        int winner_index = find_winner(players_array, num_players);
        std::cout << "The winner is: Player " << winner_index << "!" << std::endl;

        delete[] players_array; // Clean up allocated memory

    } while (play_again());

    return 0;
}

