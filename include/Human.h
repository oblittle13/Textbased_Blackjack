#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Player.h"

class Human : public Player {
 public:
    /**
     * Constructor for Human objects
    */
    Human();

    /**
    * Constructor
    * @param name : The human's name
    */
    Human(std::string name);

    /**
     * Destructor for Human objects
    */
    virtual ~Human() {}
};

#endif
