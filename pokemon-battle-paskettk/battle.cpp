/*
 * Author: Kate Paskett
 * File: battle.cpp
 * Description: Implementation of the battle class and its member functions,
 *              simulating the logic and flow of a Pokémon battle.
 */

#include "battle.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

battle::battle(pokemon& pokemon1, pokemon& pokemon2)
    : pokemon1(pokemon1), pokemon2(pokemon2), current_turn(1) {
}

void battle::start() {
    while (pokemon1.get_hp() > 0 && pokemon2.get_hp() > 0) {
        print_status();
        if (current_turn % 2 != 0) { // alternate between player turns
            std::cout << 
            "\n**************************************\n"
            "Player 1's Turn: \n" 
            "**************************************" << std::endl;
            take_turn(pokemon1, pokemon2);
        } else {
            std::cout << 
            "\n**************************************\n"
            "Player 2's Turn: \n" 
            "**************************************"<< std::endl;
            take_turn(pokemon2, pokemon1);
        }
        ++current_turn;
    }
    if (pokemon1.get_hp() > 0) {
        std::cout << pokemon1.get_name() << " wins!\n";
    } else {
        std::cout << pokemon2.get_name() << " wins!\n";
    }
}

void battle::take_turn(pokemon& attacker, pokemon& defender) {
    std::cout << "\nTaking turn for " << attacker.get_name() << "\n";

    int choice = move_or_heal(attacker);
    if (choice == 1) { // player selects move
        int x = select_move(attacker);

        // ensure the selected move is valid and has uses left
        while (attacker.moves[x].get_uses_left() <= 0) {
            std::cout << "*** Selected move has no uses left. Please choose a different move. ***\n";
            x = select_move(attacker);
        }
        std::cout << "Using " << attacker.moves[x].get_name() << " move!" << std::endl;

        // use the selected move
        attacker.take_damage(defender, attacker.moves[x]);
        attacker.moves[x].use_move(); // decrease number of moves left

    } else if (choice == 2) { // player selects heal
        if (attacker.has_healed() == false) {
            attacker.heal();
        } else {
            std::cout << "*** No heals left. You must make a move. ***" << std::endl;
            take_turn(attacker, defender); // Retry the turn if no heals left
        }
    }
}

void battle::print_status() const {
    std::cout << "Trainer 1's " << pokemon1.get_name() << "c HP: " << pokemon1.get_hp() << "\n";
    std::cout << "Trainer 2's " << pokemon2.get_name() << " HP: " << pokemon2.get_hp() << "\n";
}

int battle::move_or_heal(const pokemon &p) {
    int choice;
    do {
    std::cout   << "Would you like to move or use a healing potion to restore 10 HP?\n"
                << "1. Use a move\n"
                << "2. Drink healing potion\n"
                << "Enter your choice (1 or 2): "; std::cin >> choice; 

    if (choice == 1) {
        return 1;
    } else if (choice == 2) {
        return 2;
    } else {
        std::cout << "*** Invalid answer, please try again. ***" << std::endl;
    }
    } while (choice !=1 || choice !=2);
    return 0;
}

int battle::select_move(const pokemon& p) {
    int choice;
    move* moves = p.get_moves();
    int num_moves = p.get_num_moves();

    do {
    std::cout   << "\nSelect a move to play:\n" // print the move choices
                << "1. " << moves[0].get_name() << "\n  Moves left: " << moves[0].get_uses_left() << "\n" 
                << "2. " << moves[1].get_name() <<  "\n Moves left: " << moves[1].get_uses_left() << "\n"
                << "Enter your choice (1 or 2): "; std::cin >> choice;
    if (choice == 1) { // move 1
        return 0;
    } else if (choice == 2) { // move 2
        return 1;
    } else {
        std::cout << "*** Invalid answer, please try again. ***" << std::endl;
    }
    } while (choice !=0 || choice !=1); // repeat until a valid move is selected
    return 0;
}