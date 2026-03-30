//---------------------------------------------------------------------------------------------------------------------
//
// The Zoo class represents the main zoo management system, handling enclosures,
// finances, and user commands. It serves as the central controller for zoo operations.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef ZOO_HPP
#define ZOO_HPP

#include <string>
#include <vector>
#include "Shop.hpp"
#include "Enclosure.hpp"
#include "Command.hpp"

class Zoo {
private:
    std::string name_;                     // Name of the zoo
    Shop& shop_;                           // Reference to the animal shop
    int money_;                            // Current available funds
    int width_;                            // Zoo map width
    int height_;                           // Zoo map height
    bool map_active_;                      // Flag for map display state
    std::vector<std::vector<Enclosure*>> enclosures_;  // 2D grid of enclosures
    int empty_Enclosures_ = 0;             // Count of empty enclosures

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Zoo with specified parameters.
    //
    // @param name   : Name of the zoo
    // @param shop   : Reference to the animal shop
    // @param money  : Initial funds
    // @param width  : Map width dimension
    // @param height : Map height dimension
    //-----------------------------------------------------------------------------------------------------------------
    Zoo(std::string name, Shop& shop, int money, int width, int height);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Copy constructor (deleted to prevent object copying).
    //-----------------------------------------------------------------------------------------------------------------
    Zoo(const Zoo&) = delete;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Destructor that cleans up all enclosures.
    //-----------------------------------------------------------------------------------------------------------------
    ~Zoo();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes a user command and executes the appropriate action.
    //
    // @param command : The Command object to process
    //-----------------------------------------------------------------------------------------------------------------
    void processCommand(const Command& command);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the zoo's name.
    //
    // @return Zoo name as string
    //-----------------------------------------------------------------------------------------------------------------
    std::string getName() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the current available funds.
    //
    // @return Current money amount
    //-----------------------------------------------------------------------------------------------------------------
    int getMoney() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the zoo map width.
    //
    // @return Map width dimension
    //-----------------------------------------------------------------------------------------------------------------
    int getWidth() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the zoo map height.
    //
    // @return Map height dimension
    //-----------------------------------------------------------------------------------------------------------------
    int getHeight() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if the map is currently being displayed.
    //
    // @return true if map is active, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isMapActive() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if an enclosure can be built at specified location.
    //
    // @param x      : X coordinate position
    // @param y      : Y coordinate position
    // @param width  : Enclosure width
    // @param height : Enclosure height
    // @return true if construction is possible, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool canBuildEnclosure(int x, int y, int width, int height) const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Adds a new enclosure to the zoo.
    //
    // @param enclosure : Pointer to Enclosure to add
    //-----------------------------------------------------------------------------------------------------------------
    void buildEnclosure(Enclosure* enclosure);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Counts neighboring forest enclosures for a given enclosure.
    //
    // @param enclosure : Reference to enclosure to check
    // @return Number of adjacent forest enclosures
    //-----------------------------------------------------------------------------------------------------------------
    int countNeighboringForests(const Enclosure& enclosure) const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if an enclosure is on the zoo's edge.
    //
    // @param enclosure : Reference to enclosure to check
    // @return true if on edge, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isEnclosureOnEdge(const Enclosure& enclosure) const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Prints the current zoo map to standard output.
    //-----------------------------------------------------------------------------------------------------------------
    void printMap() const;
    
private:
    //-----------------------------------------------------------------------------------------------------------------
    // Prints the zoo's welcome message.
    //-----------------------------------------------------------------------------------------------------------------
    void printWelcomeMessage() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the SHOP command (displays available animals).
    //-----------------------------------------------------------------------------------------------------------------
    void processShopCommand();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the INFO command (displays enclosure information).
    //
    // @param params : Command parameters
    //-----------------------------------------------------------------------------------------------------------------
    void processInfoCommand(const std::vector<std::string>& params);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the MAP command (toggles map display).
    //-----------------------------------------------------------------------------------------------------------------
    void processMapCommand();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the BUILD command (constructs new enclosure).
    //
    // @param params : Command parameters
    //-----------------------------------------------------------------------------------------------------------------
    void processBuildCommand(const std::vector<std::string>& params);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the BUY command (purchases animal).
    //
    // @param params : Command parameters
    //-----------------------------------------------------------------------------------------------------------------
    void processBuyCommand(const std::vector<std::string>& params);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Processes the RATE command (calculates enclosure ratings).
    //-----------------------------------------------------------------------------------------------------------------
    void processRateCommand();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Clears all enclosures from the zoo.
    //-----------------------------------------------------------------------------------------------------------------
    void clearEnclosures();
};

#endif // ZOO_HPP