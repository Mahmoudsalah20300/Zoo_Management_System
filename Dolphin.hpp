//---------------------------------------------------------------------------------------------------------------------
//
// The Dolphin class represents a dolphin animal in the zoo system.
// Inherits from Animal and implements dolphin-specific behaviors and attributes.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef DOLPHIN_HPP
#define DOLPHIN_HPP

#include "Animal.hpp"

class Dolphin : public Animal {
private:
    int fish_eaten_per_day_;

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Dolphin with name, age, and fish consumption rate.
    //
    // @param name               : The dolphin's name (std::string)
    // @param age                : The dolphin's age in years (int)
    // @param fish_eaten_per_day : Daily fish consumption count (int)
    //-----------------------------------------------------------------------------------------------------------------
    Dolphin(std::string name, int age, int fish_eaten_per_day);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Dolphin(const Dolphin&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Dolphin() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the dolphin's animal type (implementation of pure virtual method).
    //
    // @return AnimalType::Dolphin
    //-----------------------------------------------------------------------------------------------------------------
    AnimalType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a formatted string representing the dolphin.
    //
    // @return std::string containing dolphin information
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints complete dolphin information to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printInformation() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates and returns the dolphin's price.
    //
    // @return int representing the dolphin's price
    //-----------------------------------------------------------------------------------------------------------------
    int getPrice() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the dolphin's daily fish consumption.
    //
    // @return int representing fish eaten per day
    //-----------------------------------------------------------------------------------------------------------------
    int getFishEatenPerDay() const;
};

#endif // DOLPHIN_HPP