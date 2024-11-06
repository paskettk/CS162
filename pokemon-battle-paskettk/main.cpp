/*
 * Author: Kate Paskett
 * File: main.cpp
 * Description: The main entry point for the Pokémon battle simulation.
 *              This file initializes the game, prompts the trainers to
 *              choose their Pokémon, and starts the battle.
 */

#include <iostream>

#include "startup.hpp"
#include "battle.hpp"

int main() {
	int trainer_1_pokemon_choice = prompt_first_pokemon();
	int trainer_2_pokemon_choice = prompt_second_pokemon(
		trainer_1_pokemon_choice
	);

	// define pointers for chosen pokemon
	pokemon* pokemon1 = nullptr;
	pokemon* pokemon2 = nullptr;

	// define moves for each pokemon
	move* charmander_moves = new move[2] {move("Scratch", "Normal", 3, 10000, 10000), move("Ember", "Fire", 5, 3, 3)};
    move* squirtle_moves = new move[2] {move("Tackle", "Normal", 3, 10000, 10000), move("Water Gun", "Water", 5, 3, 3)};
    move* bulbasaur_moves = new move[2] {move("Tackle", "Normal", 3, 10000, 10000), move("Vine Whip", "Grass", 5, 3, 3)};

	// create dynamic array of pokemon and moves
	if (trainer_1_pokemon_choice == 1) { // trainer 1 picks Charmander
			pokemon1 = new pokemon("Charmander", "Fire", 6, 4, 18, 18, 2, charmander_moves, false);

			if (trainer_2_pokemon_choice == 2) { // trainer 2 picks Squirtle
				
				pokemon2 = new pokemon("Squirtle", "Water", 4, 6, 22, 22, 2, squirtle_moves, false);

			} else if (trainer_2_pokemon_choice == 3) { // trainer 2 picks Bulbasaur

				pokemon2 = new pokemon("Bulbasaur", "Grass", 5, 5, 20, 20, 2, bulbasaur_moves, false);
			}
		}

	if (trainer_1_pokemon_choice == 2) { // trainer 1 picks Squirtle

		pokemon1 = new pokemon("Squirtle", "Water", 4, 6, 22, 22, 2, squirtle_moves, false);

		if (trainer_2_pokemon_choice == 1) { // trainer 2 picks Charmander

			pokemon2 = new pokemon("Charmander", "Fire", 6, 4, 18, 18, 2, charmander_moves, false);

		} else if (trainer_2_pokemon_choice == 3) { // trainer 2 picks Bulbasaur

			pokemon2 = new pokemon("Bulbasaur", "Grass", 5, 5, 20, 20, 2, bulbasaur_moves, false);
		}	
	}

	if (trainer_1_pokemon_choice == 3) { // trainer 1 picks Bulbasaur

		pokemon1 = new pokemon("Bulbasaur", "Grass", 5, 5, 20, 20, 2, bulbasaur_moves, false);
		
		if (trainer_2_pokemon_choice == 1) { // trainer 2 picks Charmander
			pokemon2 = new pokemon("Charmander", "Fire", 6, 4, 18, 18, 2, charmander_moves, false);

		} else if (trainer_2_pokemon_choice == 2) { // trainer 2 picks Squirtle

			pokemon2 = new pokemon("Squirtle", "Water", 4, 6, 22, 22, 2, squirtle_moves, false);
		}
	}
	
	battle the_battle(*pokemon1, *pokemon2);
	the_battle.start();

// delete dynamic memory
    delete[] charmander_moves;
    delete[] squirtle_moves;
    delete[] bulbasaur_moves;
    delete pokemon1;
    delete pokemon2;
}
