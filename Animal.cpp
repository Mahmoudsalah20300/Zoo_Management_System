#include "Animal.hpp"
#include <iostream>

// Constructor implementation
Animal::Animal(std::string name, int age) 
    : name_(std::move(name)), age_(age) {}

// Getter implementations
std::string Animal::getName() const {
    return name_;
}

int Animal::getAge() const {
    return age_;
}