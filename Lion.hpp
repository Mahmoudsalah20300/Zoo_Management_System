//---------------------------------------------------------------------------------------------------------------------
//
// The Lion class represents a lion animal in the zoo system.
// Inherits from Animal and implements lion-specific attributes and behaviors.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef LION_HPP
#define LION_HPP

#include "Animal.hpp"

class Lion : public Animal {
private:
    int mane_length_;  // Length of the lion's mane in centimeters

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Lion with name, age, and mane length.
    //
    // @param name        : The lion's name (std::string)
    // @param age         : The lion's age in years (int)
    // @param mane_length : Length of mane in cm (int)
    //-----------------------------------------------------------------------------------------------------------------
    Lion(std::string name, int age, int mane_length);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Lion(const Lion&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Lion() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the lion's animal type (implementation of pure virtual method).
    //
    // @return AnimalType::Lion
    //-----------------------------------------------------------------------------------------------------------------
    AnimalType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a formatted string representing the lion.
    //
    // @return std::string containing lion information
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints complete lion information to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printInformation() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates and returns the lion's price based on mane length.
    //
    // @return int representing the lion's price
    //-----------------------------------------------------------------------------------------------------------------
    int getPrice() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the lion's mane length.
    //
    // @return int representing mane length in centimeters
    //-----------------------------------------------------------------------------------------------------------------
    int getManeLength() const;
};

#endif // LION_HPP