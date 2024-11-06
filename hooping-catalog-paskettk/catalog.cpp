#include "catalog.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

// Function to create an array of teams
team* create_teams(int size) {
    team* teams = new team[size]; // size = num_teams
    return teams;
}

// Gets data from file and creates array
void populate_team_data(team& t, std::ifstream& file) {
    file >> t.name >> t.owner >> t.market_value >> t.num_player; // read team data

    t.p = create_players(t.num_player); // create players for team

    for (int i = 0; i < t.num_player; i++) { // populate data for players
        populate_player_data(t.p[i], file);
    }

    t.total_ppg = 0; // initialize points per game to 0
    for (int i = 0; i < t.num_player; i++) {
        t.total_ppg += t.p[i].ppg; // each player in t.p has their ppg added to the total
    }
}

// Creates players array
player* create_players(int size) {
    player* players = new player[size]; // creates dynamic array
    return players;
}

// Gets player data from file
void populate_player_data(player& p, std::ifstream& file) {
    file >> p.name >> p.age >> p.nation >> p.ppg >> p.fg;
}

// Deletes dynamic array 
void delete_info(team* teams, int size) {
    for (int i = 0; i < size; i++ ) {
        delete[] teams[i].p;
        teams[i].p = nullptr;
    }
    delete[] teams;
    teams = nullptr;
}

// Gets file name with team info
void open_file(std::ifstream &file, std::string& filename) {
    std::cout << "Enter the file name: "; // prompt for filename
    std::cin >> filename;
    file.open(filename);
}

// Gets number of teams
int get_num_of_teams(std::ifstream& file) {
    int num_teams; // initialize the number of teams
    file >> num_teams; // read first line
    return num_teams;
}

// Prompts user for new file name
std::string get_new_file_name() {
    std::string filename;
    std::cout << "Enter the file name:"; // prompt for filename
    std::cin >> filename;
    return filename;
}

// Prompts user for team name
std::string team_name_search_prompt(team* teams, const int num_teams) {
    std::string name;
    bool valid_name = false; // set valid value to false to initiate loop
    do {
        valid_name = false; // reset value to false for each input
        std::cout << "Enter a team name: \n";
        std::cin >> name;

            for (int i = 0; i < num_teams; i++) {
                if (teams[i].name == name) {
                    valid_name = true;
                    break;
                }
            }
            if (valid_name == false) {
                std::cout << "Invalid team name. Please try again." << std::endl;
            }
    } while (valid_name == false);
    return name;
}

// Searches for teams with name
void search_team_by_name(team* teams, int num_teams, std::stringstream &output) {
    std::string name = team_name_search_prompt(teams, num_teams);

    for (int i = 0; i < num_teams; i++) {
        if (teams[i].name == name) {
            output  << "Team Name: " << teams[i].name
                    << ", Owner: " << teams[i].owner
                    << ", Market Value: " << teams[i].market_value
                    << ", Number of players: " << teams[i].num_player << std::endl;

            for (int j = 0; j < teams[i].num_player; j++) {
                output  << "Name: " << teams[i].p[j].name
                        << ", Age: " << teams[i].p[j].age
                        << ", Nationality: " << teams[i].p[j].nation
                        << ", Points per Game: " << teams[i].p[j].ppg
                        << ", Field Goal Percentage: " << teams[i].p[j].fg << std::endl;
            }
        }
    }
    data_display_choice(output); // Passes output to data display function

}

// Displays top scorers from each team
void display_top_scorer(team* teams, int num_teams, std::stringstream &output) {
    std::string ppg;

     for (int i = 0; i < num_teams; i++) {
        player* top_scorer = nullptr; // create array for top scorer
        float max_ppg = 0.0; // initialize max ppg

        for (int j = 0; j < teams[i].num_player; j++) {
            if (teams[i].p[j].ppg > max_ppg) { // check if score is higher than max
                max_ppg = teams[i].p[j].ppg;
                top_scorer = &teams[i].p[j]; // update top scorer
            }
        }
        if (top_scorer != nullptr) { // check for top scorer
            output      << "Team: " << teams[i].name
                        << ", Player: " << top_scorer->name
                        << ", Points per Game: " << top_scorer->ppg << std::endl;
        }
    }
    data_display_choice(output); // Passes output to data display function

}

// Prompts user to enter nationality
std::string nationality_prompt() {
    std::string nation;
    std::cout << "Enter the nationality: ";
    std::cin >> nation;
    return nation;
}

// Searches players by nationality given my user
void search_by_nationality(team* teams, int num_teams, std::stringstream &output) {
    std::string nation = nationality_prompt();

    bool found = false; // initilize variable to track whether players are found
        for (int i = 0; i < num_teams; i++) {
            for (int j = 0; j < teams[i].num_player; j++) {
                if (teams[i].p[j].nation == nation) {
                    output << "Name: " << teams[i].p[j].name
                        << ", Age: " << teams[i].p[j].age << std::endl;
                    found = true;
                }
            }
        }
        if (!found) {
            std::cout << "No players found of nationality: " << nation << std::endl;
            return;
        }
    data_display_choice(output); // Passes output to data display function

}

// Prompts user for searching method
void choice_prompt(team* teams, int num_teams) {
    std::stringstream output;
    int choice; // initilize choice
    do {
        std::cout << "How would you like to search? " << std::endl;
        std::cout << "1. Search by team name" << std::endl;
        std::cout << "2. View top scorer by team" << std::endl;
        std::cout << "3. Search players by nationality" << std::endl;
        std::cout << "4. Sort teams by total points per game" << std::endl;
        std::cout << "5. Quit" << std::endl;

        std::cout << "Enter a number 1-5: "; std::cin >> choice;

        if (choice == 1) { // search by name
            search_team_by_name(teams, num_teams, output);

        } else if (choice == 2) { // view top scorer of each team
            display_top_scorer(teams, num_teams, output);

        } else if (choice == 3) { // search by nationality
            search_by_nationality(teams, num_teams, output);

        } else if (choice == 4) {
            sort_teams(teams, num_teams);
            search_sorted_teams(teams, num_teams, output);

        } else if (choice == 5) {
            std::cout << "Quitting program." << std::endl;
            return;

        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
}

// Gets data display choice from user
int data_display_prompt() {
    int choice;
    do {
        std::cout << "\nHow would you like the data?" << std::endl;
        std::cout << "1. Print to screen" << std::endl;
        std::cout << "2. Write to file" << std::endl;

        std::cout << "Enter a number 1-2: "; std::cin >> choice;

        if (choice < 1 || choice > 2) {
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice < 1 || choice > 2);
    return choice;
}

// Displays data in the method chosen by user
void data_display_choice(std::stringstream &output) {
    int choice = data_display_prompt();
        if (choice == 1) {  // print to screen
            std::cout << "\n" << output.str() << std::endl;

        } else if (choice == 2) { // write to file
            std::string filename = get_new_file_name(); // get filename
            std::ofstream outputfile(filename, std::ios::app); // start ofstream
                if (outputfile.is_open()) { // check if file is open
                    outputfile << output.str() << std::endl; // append stringstream into file
                    outputfile.close(); // close file stream
                    std::cout << "Data appended to: " << filename << std::endl;
                } else {
                    std::cout << "Cannot open file: " << filename << std::endl;
                    return;
                }
        } else {
        std::cout << "Invalid choice." << std::endl;
        }

output.str(""); // clear any previous output (if more than one search method has been used)
}

// Calculates total PPG
float calculate_total_ppg(team &teams) {
    float total_ppg = 0.0;
    for (int i=0; i < teams.num_player; i++) {
        total_ppg += teams.p[i].ppg;
    }
    return total_ppg;
}

// Sorts teams by PPG
void sort_teams(team *teams, int num_teams) {
    // Outer loop: iterate through the team array
    for (int i = 0; i < num_teams - 1; i++) {
        // Tracks the index in the array that currently holds the team with the highest PPG
        int max_index = i;
        
        // Inner loop: iterate through the remaining part of the array (starts after i)
        for (int j = i + 1; j < num_teams; j++) {
            // Calculates total PPG for team at index j
            float total_ppg_j = calculate_total_ppg(teams[j]);
            // Calculates total PPG for team at index "max_index"
            float total_ppg_max_index = calculate_total_ppg(teams[max_index]);
            
            // Compare PPG values
            if (total_ppg_j > total_ppg_max_index) {
                // If new team has higher max PPG, update max_index
                max_index = j;
            }
        }
        
        // If max_index doesn't equal i, we need to swap the teams
        if (max_index != i) {
            std::swap(teams[i], teams[max_index]);
        }
    }
}


// Displays teams in order by PPG
void search_sorted_teams(team *teams, int num_teams, std::stringstream &output) {
    for (int i = 0; i < num_teams; i++) {
        float total_ppg = calculate_total_ppg(teams[i]);
        output << "Team: " << teams[i].name << ", Total PPG: " << total_ppg << std::endl;
    }
    data_display_choice(output); // Passes output to data display function
}


