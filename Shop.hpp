//---------------------------------------------------------------------------------------------------------------------
//
// The Shop class manages the zoo's animal shop, handling animal purchases and inventory.
// It loads available animals from configuration files and provides purchase functionality.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef SHOP_HPP
#define SHOP_HPP

#include <string>
#include <vector>
#include "Animal.hpp"

class Shop {
private:
    std::string name_;                  // Name of the shop
    std::vector<Animal*> available_animals_;  // List of available animals for purchase

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a new Shop with empty inventory.
    //-----------------------------------------------------------------------------------------------------------------
    Shop();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Shop(const Shop&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Destructor that cleans up all animal objects in the shop.
    //-----------------------------------------------------------------------------------------------------------------
    ~Shop();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Attempts to load shop configuration from specified file path.
    //
    // @param path : Path to configuration file
    // @return true if loading succeeded, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool tryLoadConfig(const std::string& path);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Adds an animal to the shop's available inventory (purchase from supplier).
    //
    // @param animal : Pointer to Animal to add to inventory
    //-----------------------------------------------------------------------------------------------------------------
    void buy(Animal* animal);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Retrieves an animal from the shop by name.
    //
    // @param name : Name of animal to find
    // @return Pointer to Animal if found, nullptr otherwise
    //-----------------------------------------------------------------------------------------------------------------
    Animal* getAnimal(const std::string& name);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints shop information including available animals to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printInfo() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the shop's name.
    //
    // @return const reference to shop name string
    //-----------------------------------------------------------------------------------------------------------------
    const std::string& getName() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets all animals available in the shop.
    //
    // @return const reference to vector of Animal pointers
    //-----------------------------------------------------------------------------------------------------------------
    const std::vector<Animal*>& getAnimals() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the count of animals available in the shop.
    //
    // @return Number of available animals
    //-----------------------------------------------------------------------------------------------------------------
    int getShopAnimalNumber();
};

#endif // SHOP_HPP