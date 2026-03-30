//---------------------------------------------------------------------------------------------------------------------
//
// The Gorilla class represents a gorilla animal in the zoo system.
// Inherits from Animal and implements gorilla-specific attributes and behaviors.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef GORILLA_HPP
#define GORILLA_HPP

#include "Animal.hpp"
#include <cmath> // For std::abs and std::floor

class Gorilla : public Animal {
private:
    float weight_;  // The gorilla's weight in kilograms

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Gorilla with name, age, and weight.
    //
    // @param name   : The gorilla's name (std::string)
    // @param age    : The gorilla's age in years (int)
    // @param weight : The gorilla's weight in kg (float)
    //-----------------------------------------------------------------------------------------------------------------
    Gorilla(std::string name, int age, float weight);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Gorilla(const Gorilla&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Gorilla() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the gorilla's animal type (implementation of pure virtual method).
    //
    // @return AnimalType::Gorilla
    //-----------------------------------------------------------------------------------------------------------------
    AnimalType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a formatted string representing the gorilla.
    //
    // @return std::string containing gorilla information
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints complete gorilla information to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printInformation() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates and returns the gorilla's price based on weight.
    //
    // @return int representing the gorilla's price
    //-----------------------------------------------------------------------------------------------------------------
    int getPrice() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the gorilla's weight.
    //
    // @return float representing weight in kilograms
    //-----------------------------------------------------------------------------------------------------------------
    float getWeight() const;
};

#endif // GORILLA_HPP