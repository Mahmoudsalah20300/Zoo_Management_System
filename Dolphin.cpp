#include "Dolphin.hpp"
#include <iostream>

// Constructor implementation
Dolphin::Dolphin(std::string name, int age, int fish_eaten_per_day)
    : Animal(std::move(name), age), fish_eaten_per_day_(fish_eaten_per_day) {}

// Overridden methods
AnimalType Dolphin::getType() const {
    return AnimalType::Dolphin;
}

std::string Dolphin::getDisplayString() const {
    return "Dolphin";
}

void Dolphin::printInformation() const {
    std::cout << "Dolphin \"" << name_ << "\" of age " << age_ 
              << ": " << fish_eaten_per_day_ << " fish eaten per day!\n";
}

int Dolphin::getPrice() const {
    return 10000 - fish_eaten_per_day_ * 10;
}

// Getter implementation
int Dolphin::getFishEatenPerDay() const {
    return fish_eaten_per_day_;
}