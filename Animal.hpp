//---------------------------------------------------------------------------------------------------------------------
//
// Abstract base class for animals in a zoo management system. 
// Defines common attributes (name, age) and enforces derived classes to implement 
// type-specific behaviors via pure virtual methods.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

enum class AnimalType {
    Lion,
    Giraffe,
    Gorilla,
    Dolphin
};

class Animal {
protected:
    std::string name_;
    int age_;

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs an Animal with specified name and age.
    //
    // @param name : The animal's name (std::string)
    // @param age  : The animal's age in years (int)
    //-----------------------------------------------------------------------------------------------------------------
    Animal(std::string name, int age);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Animal(const Animal&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Animal() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Retrieves the animal's type (pure virtual - must be implemented by derived classes).
    //
    // @return AnimalType enum value (Lion/Giraffe/Gorilla/Dolphin)
    //-----------------------------------------------------------------------------------------------------------------
    virtual AnimalType getType() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a formatted string with the animal's details (pure virtual).
    //
    // @return std::string in "Name: [name], Age: [age]" format (example)
    //-----------------------------------------------------------------------------------------------------------------
    virtual std::string getDisplayString() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints the animal's complete information to standard output (pure virtual).
    //-----------------------------------------------------------------------------------------------------------------
    virtual void printInformation() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates the animal's price (pure virtual - logic varies by derived class).
    //
    // @return int representing price in currency units
    //-----------------------------------------------------------------------------------------------------------------
    virtual int getPrice() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Accesses the animal's name.
    //
    // @return std::string containing the name
    //-----------------------------------------------------------------------------------------------------------------
    std::string getName() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Accesses the animal's age.
    //
    // @return int containing age in years
    //-----------------------------------------------------------------------------------------------------------------
    int getAge() const;
};

#endif // ANIMAL_HPP