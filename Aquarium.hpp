//---------------------------------------------------------------------------------------------------------------------
//
// The Aquarium class represents a specialized water-based enclosure in a zoo system.
// Inherits from Enclosure and implements aquarium-specific behaviors and restrictions.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "Enclosure.hpp"

class Aquarium : public Enclosure {
public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs an Aquarium enclosure with specified dimensions and position.
    //
    // @param base_column : The leftmost column position of the aquarium (int)
    // @param base_row    : The topmost row position of the aquarium (int)
    // @param width       : The horizontal size of the aquarium (int)
    // @param height      : The vertical size of the aquarium (int)
    //-----------------------------------------------------------------------------------------------------------------
    Aquarium(int base_column, int base_row, int width, int height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Aquarium(const Aquarium&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Aquarium() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the type of this enclosure (Aquarium-specific implementation).
    //
    // @return EnclosureType::Aquarium
    //-----------------------------------------------------------------------------------------------------------------
    EnclosureType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a display string representing the aquarium.
    //
    // @return std::string containing aquarium representation
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if a specific animal type is allowed in this aquarium.
    //
    // @param animal : The AnimalType to check
    // @return true if allowed (water animals only), false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isAnimalAllowed(AnimalType animal) const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates a quality rating score for this aquarium based on zoo conditions.
    //
    // @param zoo : Reference to the containing Zoo object
    // @return int representing the calculated quality rating
    //-----------------------------------------------------------------------------------------------------------------
    int calculateRating(const Zoo& zoo) const override;
};

#endif // AQUARIUM_HPP