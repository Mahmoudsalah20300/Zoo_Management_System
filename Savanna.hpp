//---------------------------------------------------------------------------------------------------------------------
//
// The Savanna class represents a savanna enclosure in the zoo system.
// Inherits from Enclosure and implements savanna-specific behaviors and restrictions.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef SAVANNA_HPP
#define SAVANNA_HPP

#include "Enclosure.hpp"

class Savanna : public Enclosure {
public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Savanna enclosure with specified dimensions and position.
    //
    // @param base_column : The leftmost column position (int)
    // @param base_row    : The topmost row position (int)
    // @param width       : The horizontal size (int)
    // @param height      : The vertical size (int)
    //-----------------------------------------------------------------------------------------------------------------
    Savanna(int base_column, int base_row, int width, int height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Savanna(const Savanna&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor (defaulted for safe polymorphic deletion).
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Savanna() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the type of this enclosure (Savanna-specific implementation).
    //
    // @return EnclosureType::Savanna
    //-----------------------------------------------------------------------------------------------------------------
    EnclosureType getType() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a display string representing the savanna enclosure.
    //
    // @return std::string containing savanna representation
    //-----------------------------------------------------------------------------------------------------------------
    std::string getDisplayString() const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if a specific animal type is allowed in this savanna enclosure.
    //
    // @param animal : The AnimalType to check
    // @return true if allowed (savanna animals only), false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isAnimalAllowed(AnimalType animal) const override;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates a quality rating score for this savanna based on zoo conditions.
    //
    // @param zoo : Reference to the containing Zoo object
    // @return int representing the calculated quality rating
    //-----------------------------------------------------------------------------------------------------------------
    int calculateRating(const Zoo& zoo) const override;
};

#endif // SAVANNA_HPP