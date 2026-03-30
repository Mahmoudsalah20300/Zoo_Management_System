#include "Shop.hpp"
#include "Animal.hpp"
#include "Lion.hpp"
#include "Giraffe.hpp"
#include "Gorilla.hpp"
#include "Dolphin.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

// Constructor
Shop::Shop() : name_("") {}

// Destructor
Shop::~Shop() {
    for (Animal* animal : available_animals_) {
        delete animal;
    }
    available_animals_.clear();
}

// Config file loading
bool Shop::tryLoadConfig(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    // Check magic number
    std::string magic;
    if (!std::getline(file, magic) || magic != "OOP") {
        return false;
    }

    // Read shop name
    if (!std::getline(file, name_)) {
        return false;
    }

    // Read animals
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, type;
        int age;
        float traitValue;

        if (!std::getline(iss, name, ';') ||
            !std::getline(iss, type, ';') ||
            !(iss >> age) ||
            !(iss.ignore() && (iss >> traitValue))) {
            continue; // Skip malformed lines
        }

        // Create appropriate animal
        Animal* animal = nullptr;
        if (type == "Lion") {
            animal = new Lion(name, age, static_cast<int>(traitValue));
        } else if (type == "Giraffe") {
            animal = new Giraffe(name, age, traitValue);
        } else if (type == "Gorilla") {
            animal = new Gorilla(name, age, traitValue);
        } else if (type == "Dolphin") {
            animal = new Dolphin(name, age, static_cast<int>(traitValue));
        }

        if (animal) {
            available_animals_.push_back(animal);
        }
    }

    return true;
}

int Shop::getShopAnimalNumber() {
    return available_animals_.size();
}

// Animal management
void Shop::buy(Animal* animal) {
    auto it = std::find(available_animals_.begin(), available_animals_.end(), animal);
    if (it != available_animals_.end()) {
        available_animals_.erase(it);
    }
}

Animal* Shop::getAnimal(const std::string& name) {
    auto it = std::find_if(available_animals_.begin(), available_animals_.end(),
        [&name](const Animal* a) {
            std::string animalName = a->getName();
            std::transform(animalName.begin(), animalName.end(), animalName.begin(), ::tolower);
            std::string searchName = name;
            std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
            return animalName == searchName;
        });

    return (it != available_animals_.end()) ? *it : nullptr;
}

// Information printing
void Shop::printInfo() const {
    std::cout << "Welcome to the \"" << name_ << "\"!\n\n"
              << "The following are our prices for the given enclosure types per field:\n"
              << "- Savanna:   1000 coins\n"
              << "- Forest:    3000 coins\n"
              << "- Aquarium: 10000 coins\n\n"
              << "We have the following animals for sale:\n";

    if (available_animals_.empty()) {
        //std::cout << "\n";
    }else{          
        for (const auto& animal : available_animals_) {
            std::cout << "- " << animal->getDisplayString() << " \"" << animal->getName()
                  << "\": " << animal->getPrice() << " coins\n";
    }
}

    
}

// Getters
const std::string& Shop::getName() const {
    return name_;
}

const std::vector<Animal*>& Shop::getAnimals() const {
    return available_animals_;
}