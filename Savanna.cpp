#include "Savanna.hpp"
#include "Zoo.hpp"
#include <algorithm>

// Constructor implementation
Savanna::Savanna(int base_column, int base_row, int width, int height)
    : Enclosure(base_column, base_row, width, height) {}

// Overridden methods
EnclosureType Savanna::getType() const {
    return EnclosureType::Savanna;
}

std::string Savanna::getDisplayString() const {
    return "S";
}

bool Savanna::isAnimalAllowed(AnimalType animal) const {
    if (!animals_.empty() && animals_[0] == nullptr) {
        return false;
    }
    // Only lions and giraffes allowed
    if (animal != AnimalType::Lion && animal != AnimalType::Giraffe) {
        return false;
    }

    // Check if enclosure is empty or contains same type
    if (animals_.empty()) {
        return true;
    }

    AnimalType existingType = animals_[0]->getType();
    return animal == existingType;
}

int Savanna::calculateRating(const Zoo& zoo) const {
    int rating = 0;
    int lionCount = 0;
    int giraffeCount = 0;
    int capacity = width_ * height_;

    // Base points for each field
    rating += 2 * capacity;

    // Count animals and add their points
    for (const Animal* animal : animals_) {
        switch (animal->getType()) {
            case AnimalType::Lion:
                lionCount++;
                break;
            case AnimalType::Giraffe:
                giraffeCount++;
                rating += 3;
                break;
            default:
                break;
        }
    }

    // Calculate lion points (with penalty if too many)
    int lionPoints = (lionCount > capacity / 2) ? 2 : 4;
    rating += lionCount * lionPoints;

    // Check if enclosure is larger than half of zoo
    int zooArea = zoo.getWidth() * zoo.getHeight();
    if (capacity > zooArea / 2) {
        rating *= 2;
    }

    return rating;
}