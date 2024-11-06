/*
 * File: room.hpp
 * Author: Kate Paskett
 * Description: Declares the room class, which represents a single room in the 
 * "Hunt the Wumpus" game. A room can contain a player, an event, or be empty.
 */

#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"
#include "player.hpp"

// Room class interface
class room {
private:
    // Pointer to the event in the room
    event* this_event;
    
    // Pointer to the player in the room
    player* this_player;

public:
    /*
     * Function: room (Constructor)
     * Description: Constructs a room object with default values. 
     *              Initially, the room has no player or event.
     */
    room();

    /*
     * Function: ~room (Destructor)
     * Description: Destructor for the room object. Cleans up any dynamically 
     *              allocated resources.
     */
    ~room();

    /*
     * Function: operator= (Assignment Operator)
     * Description: Assigns the contents of one room object to another.
     * Parameters:
     *      original (const room&): The room object to copy.
     * Returns:
     *      room&: A reference to the assigned room object.
     */
    room& operator = (const room& original);

    /*
     * Function: set_event
     * Description: Sets the event in the room.
     * Parameters:
     *      e (event*): A pointer to the event object to be placed in the room.
     */
    void set_event(event* e);

    /*
     * Function: set_player
     * Description: Sets the player in the room.
     * Parameters:
     *      p (player*): A pointer to the player object to be placed in the room.
     */
    void set_player(player* p);

    /*
     * Function: get_player
     * Description: Retrieves the player currently in the room.
     * Returns:
     *      player*: A pointer to the player object in the room, or nullptr if none.
     */
    player* get_player() const;

    /*
     * Function: get_event
     * Description: Retrieves the event currently in the room.
     * Returns:
     *      event*: A pointer to the event object in the room, or nullptr if none.
     */
    event* get_event() const;

    /*
     * Function: is_empty
     * Description: Checks if the room is empty (i.e., has no event).
     * Returns:
     *      bool: True if the room is empty, false otherwise.
     */
    bool is_empty() const;

    /*
     * Function: delete_player
     * Description: Removes the player from the room, setting the player pointer to nullptr.
     */
    void delete_player();
};

#endif
