#include "Forest.hpp"
#include "Zoo.hpp"

// Constructor implementation
Forest::Forest(int base_column, int base_row, int width, int height)
    : Enclosure(base_column, base_row, width, height) {}

// Overridden methods
EnclosureType Forest::getType() const {
    return EnclosureType::Forest;
}

std::string Forest::getDisplayString() const {
    return "F";
}

bool Forest::isAnimalAllowed(AnimalType animal) const {
    return animal == AnimalType::Gorilla;
}

int Forest::calculateRating(const Zoo& zoo) const {
    int rating = 0;
    int gorillaCount = 0;

    // Base points for each field
    rating += 1 * (width_ * height_);

    // Count gorillas and add their points
    for (const Animal* animal : animals_) {
        if (animal->getType() == AnimalType::Gorilla) {
            gorillaCount++;
            rating += 2;
        }
    }

    // Check if bordering zoo edge
    if (zoo.isEnclosureOnEdge(*this)) {
        rating *= 2;
    }

    return rating;
}