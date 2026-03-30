#include "Gorilla.hpp"
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <cmath>   // For std::abs and std::floor

// Constructor implementation
Gorilla::Gorilla(std::string name, int age, float weight)
    : Animal(std::move(name), age), weight_(weight) {}

// Overridden methods
AnimalType Gorilla::getType() const {
    return AnimalType::Gorilla;
}

std::string Gorilla::getDisplayString() const {
    return "Gorilla";
}

void Gorilla::printInformation() const {
    std::cout << "Gorilla \"" << name_ << "\" of age " << age_ 
              << ": Weight is " << std::fixed << std::setprecision(2)
              << weight_ << " kg!\n";
}

int Gorilla::getPrice() const {
    return static_cast<int>(2000 - std::abs(150 - weight_));
}

// Getter implementation
float Gorilla::getWeight() const {
    return weight_;
}