#include "Giraffe.hpp"
#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision
#include <cmath>    // For std::floor

// Constructor implementation
Giraffe::Giraffe(std::string name, int age, float neck_height)
    : Animal(std::move(name), age), neck_height_(neck_height) {}

// Overridden methods
AnimalType Giraffe::getType() const {
    return AnimalType::Giraffe;
}

std::string Giraffe::getDisplayString() const {
    return "Giraffe";
}

void Giraffe::printInformation() const {
    std::cout << "Giraffe \"" << name_ << "\" of age " << age_ 
              << ": Neck height is " << std::fixed << std::setprecision(2)
              << neck_height_ << " m!\n";
}

int Giraffe::getPrice() const {
    return static_cast<int>(4000 + std::floor(neck_height_ * 1000));
}

// Getter implementation
float Giraffe::getNeckHeight() const {
    return neck_height_;
}