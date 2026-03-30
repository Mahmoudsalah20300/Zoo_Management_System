//---------------------------------------------------------------------------------------------------------------------
//
// The Forest class represents a forest enclosure in the zoo system.
// Inherits from Enclosure and implements forest-specific behaviors and restrictions.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Enclosure.hpp"

class Forest : public Enclosure {
public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Forest enclosure with specified dimensions and position.
    //
    // @param base_column : The leftmost column position (int)
    // @param base_row    : The topmost row position (int)
    // @param width       : The horizontal size (int)
    // @param height      : The vertical size (int)
    //-----------------------------------------------------------------------------------------------------------------
    Forest(int base_column, int base_row, int width, int height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Forest(const Forest&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Forest() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the type of this enclosure (Forest-specific implementation).
    //
    // @return EnclosureType::Forest
    //-----------------------------------------------------------------------------------------------------------------
    EnclosureType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a display string representing the forest enclosure.
    //
    // @return std::string containing forest representation
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if a specific animal type is allowed in this forest enclosure.
    //
    // @param animal : The AnimalType to check
    // @return true if allowed (forest animals only), false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isAnimalAllowed(AnimalType animal) const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates a quality rating score for this forest based on zoo conditions.
    //
    // @param zoo : Reference to the containing Zoo object
    // @return int representing the calculated quality rating
    //-----------------------------------------------------------------------------------------------------------------
    int calculateRating(const Zoo& zoo) const override;
};

#endif // FOREST_HPP