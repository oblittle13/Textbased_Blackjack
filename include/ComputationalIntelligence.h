#ifndef COMPUTATIONALINTELLIGENCE_H
#define COMPUTATIONALINTELLIGENCE_H

#include <string>

#include "Player.h"

class ComputationalIntelligence : public Player {
 public:
    /**
     * Constructor for ComputationalIntelligence objects
    */
    ComputationalIntelligence();

    /**
    * Constructor
    * @param name : The computational intelligence's name
    */
    ComputationalIntelligence(std::string name);

    /**
     * Destructor for ComputationalIntelligence objects
    */
    virtual ~ComputationalIntelligence() {}
};

#endif
