#include "catalog.h"
#include <iostream>

int main() {
	// TODO Implement your main function here
    std::ifstream file;
    std::string filename;

    open_file(file, filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1; // Return non-zero value to indicate an error
    }

    int num_teams = get_num_of_teams(file); // initialize number of teams
    team* teams = nullptr; 
    teams = create_teams(num_teams); // create team arrays

    for (int i = 0; i < num_teams; i++) { // create team data arrays
        populate_team_data(teams[i], file);
    }
    file.close();

    choice_prompt(teams, num_teams); // prompt for search method
    
    delete_info(teams, num_teams);
    teams = nullptr;
}
