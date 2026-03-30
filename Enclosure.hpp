//---------------------------------------------------------------------------------------------------------------------
//
// The Enclosure class serves as the base class for different types of animal enclosures.
// It manages enclosure dimensions, position, and contains animals while providing
// common functionality and interface for derived enclosure types.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef ENCLOSURE_HPP
#define ENCLOSURE_HPP

#include <vector>
#include <string>
#include "Animal.hpp"

class Zoo; // Forward declaration

enum class EnclosureType {
    Savanna,
    Forest,
    Aquarium
};

class Enclosure {
protected:
    int base_column_;
    int base_row_;
    int width_;
    int height_;
    std::vector<Animal*> animals_;

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs an Enclosure with specified position and dimensions.
    //
    // @param base_column : Leftmost column position (int)
    // @param base_row    : Topmost row position (int)
    // @param width       : Horizontal size (int)
    // @param height      : Vertical size (int)
    //-----------------------------------------------------------------------------------------------------------------
    Enclosure(int base_column, int base_row, int width, int height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Enclosure(const Enclosure&) = delete;

    //-----------------------------------------------------------------------------------------------------------------
    // Virtual destructor that cleans up all contained animals.
    //-----------------------------------------------------------------------------------------------------------------
    virtual ~Enclosure()
    {
        for(Animal* animal:animals_)
            delete animal;
    }
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the specific type of this enclosure (pure virtual).
    //
    // @return EnclosureType enum value
    //-----------------------------------------------------------------------------------------------------------------
    virtual EnclosureType getType() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Generates a display string representing this enclosure (pure virtual).
    //
    // @return std::string containing enclosure representation
    //-----------------------------------------------------------------------------------------------------------------
    virtual std::string getDisplayString() const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if an animal type is allowed in this enclosure (pure virtual).
    //
    // @param animal : AnimalType to check
    // @return true if allowed, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    virtual bool isAnimalAllowed(AnimalType animal) const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Calculates a quality rating for this enclosure (pure virtual).
    //
    // @param zoo : Reference to the containing Zoo
    // @return int representing quality rating
    //-----------------------------------------------------------------------------------------------------------------
    virtual int calculateRating(const Zoo& zoo) const = 0;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the string representation for a specific field position.
    //
    // @param column : Column position to check
    // @param row    : Row position to check
    // @return std::string representation of the field
    //-----------------------------------------------------------------------------------------------------------------
    std::string getFieldString(int column, int row) const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if there is room for more animals in this enclosure.
    //
    // @return true if has room, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool hasRoom() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Adds an animal to this enclosure.
    //
    // @param animal : Pointer to Animal to add
    //-----------------------------------------------------------------------------------------------------------------
    void addAnimal(Animal* animal);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the base column position of this enclosure.
    //
    // @return int base column position
    //-----------------------------------------------------------------------------------------------------------------
    int getBaseColumn() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the base row position of this enclosure.
    //
    // @return int base row position
    //-----------------------------------------------------------------------------------------------------------------
    int getBaseRow() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the width of this enclosure.
    //
    // @return int width
    //-----------------------------------------------------------------------------------------------------------------
    int getWidth() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the height of this enclosure.
    //
    // @return int height
    //-----------------------------------------------------------------------------------------------------------------
    int getHeight() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets all animals in this enclosure.
    //
    // @return const reference to vector of Animal pointers
    //-----------------------------------------------------------------------------------------------------------------
    const std::vector<Animal*>& getAnimals() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if given position is within this enclosure's boundaries.
    //
    // @param column : Column position to check
    // @param row    : Row position to check
    // @return true if position is within enclosure, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool containsPosition(int column, int row) const;
};

#endif // ENCLOSURE_HPP