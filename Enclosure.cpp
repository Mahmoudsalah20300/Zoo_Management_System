#include "Enclosure.hpp"
#include "Animal.hpp"
#include <algorithm>

// Constructor implementation
Enclosure::Enclosure(int base_column, int base_row, int width, int height)
    : base_column_(base_column), base_row_(base_row), 
      width_(width), height_(height) {}

// Field string representation
std::string Enclosure::getFieldString(int column, int row) const {
    // 1. Calculate position within enclosure
    int rel_col = column - base_column_;
    int rel_row = row - base_row_;
    
    // 2. Validate bounds (critical fix)
    if (rel_col < 0 || rel_col >= width_ || 
        rel_row < 0 || rel_row >= height_) {
        return "   "; // Return empty field for invalid positions
    }

    // 3. Get animal display using existing methods
    int animal_index = rel_row * width_ + rel_col;
    if (animal_index >= 0 && animal_index < static_cast<int>(animals_.size())) {
        // 4. SAFE ACCESS: Check animal exists and has valid display string
        if (animals_[animal_index] != nullptr) {
            std::string animal_code = animals_[animal_index]->getDisplayString();
            
            // 5. Ensure we have at least 2 characters for the animal code
            if (animal_code.length() >= 2) {
                return std::string(1, getDisplayString()[0]) // Enclosure type
                     + animal_code.substr(0, 2);             // First 2 chars of animal code
            }
            return std::string(1, getDisplayString()[0]) + "  "; // Fallback for short codes
        }
    }
    
    // 6. Empty field with enclosure type
    return std::string(1, getDisplayString()[0]) + "  ";
}

// Check if enclosure has room for more animals
bool Enclosure::hasRoom() const {
    return animals_.size() < static_cast<size_t>(width_ * height_);
}

// Add animal to enclosure
void Enclosure::addAnimal(Animal* animal) {
    
    if (hasRoom()) {
        animals_.push_back(animal);
    }
}

// Getters
int Enclosure::getBaseColumn() const { return base_column_; }
int Enclosure::getBaseRow() const { return base_row_; }
int Enclosure::getWidth() const { return width_; }
int Enclosure::getHeight() const { return height_; }
const std::vector<Animal*>& Enclosure::getAnimals() const { return animals_;}

// Position check
bool Enclosure::containsPosition(int column, int row) const {
    return column >= base_column_ && column < base_column_ + width_ &&
           row >= base_row_ && row < base_row_ + height_;
}
