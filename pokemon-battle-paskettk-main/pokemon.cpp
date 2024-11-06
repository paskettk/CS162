/*
 * Author: Kate Paskett
 * File: pokemon.cpp
 * Description: Implementation of the member functions of the pokemon class,
 *              representing the attributes and actions of Pokémon in battle.
 */

#include "pokemon.hpp"

// constructor
pokemon::pokemon(const std::string &name, const std::string &type, int attack, 
    int defense, int hp, int max_hp, int num_moves, move* moves, bool healed) 
    : name(name), attack(attack), defense(defense), hp(hp), max_hp(max_hp), 
    num_moves(num_moves), healed(healed) {
    
    this -> moves = new move[num_moves];
    for (int i = 0; i < num_moves; i++) {
        this -> moves[i] = moves[i];
    }
}

// copy constructor
pokemon::pokemon(const pokemon& original) {
    copy_moves(original);
}

// assignment operator
pokemon& pokemon::operator = (const pokemon& original) {
    if (this != &original) {
        delete_moves();
        copy_moves(original);
    }
    return *this;
}

// destructor
pokemon::~pokemon(){
    delete_moves();
}

// member functions
void pokemon::copy_moves(const pokemon& original) {
    name = original.name;
    type = original.type;
    attack = original.attack;
    defense = original.defense;
    hp = original.hp;
    max_hp = original.max_hp;
    num_moves = original.num_moves;
    moves = new move[num_moves];
    for (int i = 0; i < num_moves; i++) {
        moves[i] = original.moves[i];
    }
    healed = original.healed;
}

void pokemon::delete_moves() {
    delete [] moves;
}

std::string pokemon::get_name() const {
    return name;
}

std::string pokemon::get_type() const {
    return type;
}

int pokemon::get_attack() const{
    return attack;
}

int pokemon::get_defense() const {
    return defense;
}

int pokemon::get_hp() const {
    return hp;
}
int pokemon::random_critical() {
    int num = (rand() % 10);
    if (num == 0) {
        num = 3;
    } else {
        num = 1;
        std::cout << "Not a critical hit..." << std::endl;
    }
    if (num == 3) {
        std::cout << "It's a critical hit!" << std::endl;
    }
    return num;
}

double pokemon::random_multiplier() { // generates number between 0.8 and 1.2
    double num = (static_cast<double>(rand()) / RAND_MAX); // num between 0 and 1 
    num = 0.8 + (num * 0.4); // num between 0.8 and 1.2
    return num;
}

void pokemon::take_damage(pokemon& defender, const move& move_used) {
    double attack = this->get_attack();
    double defense = defender.get_defense();
    int base_damage = move_used.get_base_damage();
    double multiplier = random_multiplier();
    double critical = random_critical();

    std::string move_type = move_used.get_type();
    std::string defender_type = defender.get_type();
    double type_interaction = get_type_interaction(move_type, defender_type);

    double damage = ceil(attack / defense) * type_interaction
        * base_damage * multiplier * critical;

    defender.hp -= static_cast<int>(damage);
    if (defender.hp < 0) {
        defender.hp = 0;
    };

    std::cout << "Attack did " << damage << " damage!" << std::endl;
}

void pokemon::heal() {
    if (pokemon::has_healed() == false) {

        pokemon::hp += 10;
        pokemon::healed = true;
        std::cout << pokemon::get_name() << " healed 10 HP!" << std::endl;

        if (pokemon::hp >= pokemon::max_hp) {
            pokemon::hp = max_hp;
            std::cout << pokemon::get_name() << " is at full health!" << std::endl;
        }

    } else {
        std::cout << "\n** You have no heals left. You must make a move. **" << std::endl;
    }
}

move* pokemon::get_moves() const {
    return moves;
}

int pokemon::get_num_moves() const {
    return num_moves;
}

bool pokemon::has_healed() const {
    return healed;
}

double pokemon::get_type_interaction(const std::string move_type, const std::string& defense_type) {
    std::string type1 = move_type;
    std::string type2 = defense_type;

    if (type1 == "Fire") {
        if (type2 == "Fire" || type2 == "Water") {
            return 0.5;
        } else if (type2 == "Grass") {
            return 2.0;
        }
    } else if (type1 == "Water") {
        if (type2 == "Water" || type2 == "Grass") {
            return 0.5;
        } else if (type2 == "Fire") {
            return 2.0;
        }
    } else if (type1 == "Grass") {
        if (type2 == "Grass" || type2 == "Fire") {
            return 0.5;
        } else if (type2 == "Water") {
            return 2.0;
        }
    } else {
        return 1.0;
    }
    return 1;
}