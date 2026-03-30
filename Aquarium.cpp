#include "Aquarium.hpp"
#include "Zoo.hpp"
#include <vector>
#include <algorithm>

// Constructor implementation
Aquarium::Aquarium(int base_column, int base_row, int width, int height)
    : Enclosure(base_column, base_row, width, height) {}

// Overridden methods
EnclosureType Aquarium::getType() const {
    return EnclosureType::Aquarium;
}

std::string Aquarium::getDisplayString() const {
    return "A";
}

bool Aquarium::isAnimalAllowed(AnimalType animal) const {
    return animal == AnimalType::Dolphin;
}

int Aquarium::calculateRating(const Zoo& zoo) const {
    int rating = 0;
    int dolphinCount = 0;

    // Base points for each field
    rating += 3 * (width_ * height_);

    // Count dolphins and add their points
    for (const Animal* animal : animals_) {
        if (animal->getType() == AnimalType::Dolphin) {
            dolphinCount++;
            rating += 4;
        }
    }

    // Calculate penalty from neighboring forest enclosures
    int forestNeighbors = zoo.countNeighboringForests(*this);
    
    // Apply penalty (integer division)
    if (forestNeighbors > 0) {
        rating /= (1 + forestNeighbors);
    }

    return rating;
}