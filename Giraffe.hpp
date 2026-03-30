//---------------------------------------------------------------------------------------------------------------------
//
// The Giraffe class represents a giraffe animal in the zoo system.
// Inherits from Animal and implements giraffe-specific attributes and behaviors.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef GIRAFFE_HPP
#define GIRAFFE_HPP

#include "Animal.hpp"

class Giraffe : public Animal {
private:
    float neck_height_;  // The height of the giraffe's neck in meters

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Giraffe with name, age, and neck height.
    //
    // @param name        : The giraffe's name (std::string)
    // @param age         : The giraffe's age in years (int)
    // @param neck_height : The height of the neck in meters (float)
    //-----------------------------------------------------------------------------------------------------------------
    Giraffe(std::string name, int age, float neck_height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Giraffe(const Giraffe&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Giraffe() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the giraffe's animal type (implementation of pure virtual method).
    //
    // @return AnimalType::Giraffe
    //-----------------------------------------------------------------------------------------------------------------
    AnimalType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a formatted string representing the giraffe.
    //
    // @return std::string containing giraffe information
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints complete giraffe information to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printInformation() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates and returns the giraffe's price.
    //
    // @return int representing the giraffe's price
    //-----------------------------------------------------------------------------------------------------------------
    int getPrice() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the giraffe's neck height.
    //
    // @return float representing neck height in meters
    //-----------------------------------------------------------------------------------------------------------------
    float getNeckHeight() const;
};

#endif // GIRAFFE_HPP