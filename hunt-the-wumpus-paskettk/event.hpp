/*
 * File: event.hpp
 * Author: Kate Paskett
 * Description: Declares the abstract base class event, which serves as a 
 * blueprint for different types of events that can occur in the "Hunt the Wumpus" game. 
 * Derived classes must implement encounter, print, and percept functions.
 */

#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include "player.hpp"

// Event abstract base class
class event {
protected:
    // Coordinates of the event in the cave
    int row;
    int column;

    // Name of the event (e.g., Wumpus, Gold)
    std::string name = "";

public:
    /*
     * Function: ~event (Virtual Destructor)
     * Description: Virtual destructor for the event class to ensure proper cleanup 
     *              of derived class objects.
     */
    virtual ~event() = default;

    /*
     * Function: operator= (Assignment Operator)
     * Description: Assigns the contents of one event object to another.
     * Parameters:
     *      original (const event&): The event object to copy.
     * Returns:
     *      event&: A reference to the assigned event object.
     */
    virtual event& operator=(const event& original) {
        return *this;
    }

    /*
     * Function: encounter (Pure Virtual)
     * Description: Handles the interaction between the player and the event.
     *              Must be implemented by derived classes.
     * Parameters:
     *      p (player*): Pointer to the player encountering the event.
     * Returns:
     *      bool: True to keep the event, false to delete it.
     */
    virtual bool encounter(player* p) = 0;

    /*
     * Function: print (Pure Virtual)
     * Description: Prints the representation of the event in the room.
     *              Must be implemented by derived classes.
     */
    virtual void print() const = 0;

    /*
     * Function: percept (Pure Virtual)
     * Description: Prints the percept message when the player is near the event.
     *              Must be implemented by derived classes.
     */
    virtual void percept() const = 0;

    /*
     * Function: set_name
     * Description: Sets the name of the event.
     * Parameters:
     *      event_name (const std::string&): The name of the event.
     */
    void set_name(const std::string& event_name);

    /*
     * Function: get_name
     * Description: Retrieves the name of the event.
     * Returns:
     *      std::string: The name of the event.
     */
    std::string get_name() const;

    /*
     * Function: return_event
     * Description: Placeholder function that may be implemented or overridden in derived classes.
     */
    void return_event();

    // Uncomment or implement if relevant
    // virtual bool arrow_hits_wumpus(int r, int c);
};

#endif
