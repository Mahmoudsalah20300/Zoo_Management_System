#include "Lion.hpp"
#include <iostream>

// Constructor implementation
Lion::Lion(std::string name, int age, int mane_length)
    : Animal(std::move(name), age), mane_length_(mane_length) {}

// Overridden methods
AnimalType Lion::getType() const {
    return AnimalType::Lion;
}

std::string Lion::getDisplayString() const {
    return "Lion";
}

void Lion::printInformation() const {
    std::cout << "Lion \"" << name_ << "\" of age " << age_ 
              << ": Mane length is " << mane_length_ << " cm!\n";
}

int Lion::getPrice() const {
    return 5000 + mane_length_ * 100;
}

// Getter implementation
int Lion::getManeLength() const {
    return mane_length_;
}