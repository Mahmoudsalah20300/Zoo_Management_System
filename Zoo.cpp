#include "Zoo.hpp"
#include "Enclosure.hpp"
#include "Animal.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Savanna.hpp"
#include "Aquarium.hpp"
#include "Forest.hpp"
#include "Utils.hpp"

// Constructor
Zoo::Zoo(std::string name, Shop& shop, int money, int width, int height)
    : name_(std::move(name)), shop_(shop), money_(money), 
      width_(width), height_(height), map_active_(true) {
    // Initialize empty enclosure map
    enclosures_.resize(height, std::vector<Enclosure*>(width, nullptr));
    printWelcomeMessage();
    printMap();
}

// Destructor
Zoo::~Zoo() {
    clearEnclosures();
}

// Command processing
void Zoo::processCommand(const Command& command) {
    try {
        switch (command.getType()) {
            case CommandType::SHOP:
                processShopCommand();
                break;
            case CommandType::INFO:
                processInfoCommand(command.getParameters());
                break;
            case CommandType::MAP:
                processMapCommand();
                break;
            case CommandType::BUILD:
                processBuildCommand(command.getParameters());
                break;
            case CommandType::BUY:
                processBuyCommand(command.getParameters());
                break;
            case CommandType::RATE:
                processRateCommand();
                break;
            case CommandType::QUIT:
                break;
            default:
                //std::cout << "[ERROR] Entered command not found!\n";
        }
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
       
}

// Getters
std::string Zoo::getName() const { return name_; }
int Zoo::getMoney() const { return money_; }
int Zoo::getWidth() const { return width_; }
int Zoo::getHeight() const { return height_; }
bool Zoo::isMapActive() const { return map_active_; }

// Enclosure management
bool Zoo::canBuildEnclosure(int x, int y, int width, int height) const {
    // 1. Validate grid boundaries
    if (x < 0 || y < 0 || 
        x >= width_ || y >= height_ ||
        (x + width) > width_ || (y + height) > height_) {
        return false;
    }

    // 2. Check each potential grid cell
    for (int row = y; row < y + height; ++row) {
        for (int col = x; col < x + width; ++col) {
            // 2a. Check if cell is already occupied
            if (enclosures_[row][col] != nullptr) {
                // 2b. Special case: Same enclosure expanding
                Enclosure* existing = enclosures_[row][col];
                if (existing->getBaseColumn() == x && 
                    existing->getBaseRow() == y &&
                    existing->getWidth() == width &&
                    existing->getHeight() == height) {
                    continue; // Same enclosure, not considered overlap
                }
                return false;
            }
        }
    }
    return true;
}

void Zoo::buildEnclosure(Enclosure* enclosure) {
    
    int x = enclosure->getBaseColumn();
    int y = enclosure->getBaseRow();
    int width = enclosure->getWidth();
    int height = enclosure->getHeight();
    
    for (int i = y; i < y + height; ++i) {
        for (int j = x; j < x + width; ++j) {
            enclosures_[i][j] = enclosure;
        }
    }
}



bool Zoo::isEnclosureOnEdge(const Enclosure& enclosure) const {
    return (enclosure.getBaseColumn() == 0 ||
            enclosure.getBaseRow() == 0 ||
            enclosure.getBaseColumn() + enclosure.getWidth() >= width_ ||
            enclosure.getBaseRow() + enclosure.getHeight() >= height_);
}

void Zoo::printMap() const {
    std::cout << "\n";
    
    // Print column indices
    std::cout << "    ";
    for (int col = 1; col <= width_; ++col) {
        if(col == width_)
        {
            std::cout << col << "  ";
        }
        else{
            std::cout << col << "   ";
        }
    }
    std::cout << "\n";
    
    // Top border
    std::cout << "  +";
    for (int col = 0; col < width_; ++col) {
        std::cout << "---+";
    }
    std::cout << "\n";
    
    for (int row = 0; row < height_; ++row) {
        // Row number
        std::cout << row + 1 << " |";
        
        // Fields in row
        for (int col = 0; col < width_; ++col) {
            Enclosure* enclosure = enclosures_[row][col];
            std::string field = "   "; // Default empty field
            
            if (enclosure != nullptr) {
                field = enclosure->getFieldString(col, row);
                
            }
            
            std::cout << field;
            
            // Right border or space between same enclosure fields
            if (col == width_ - 1 || 
                (enclosure != enclosures_[row][col + 1])) {
                std::cout << "|";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
        
        // Bottom border or middle separator
        std::cout << "  +";
        for (int col = 0; col < width_; ++col) {
            Enclosure* current = enclosures_[row][col];
            Enclosure* below = (row < height_ - 1) ? enclosures_[row + 1][col] : nullptr;
            
            if (row == height_ - 1 || 
                (current != below)) {
                std::cout << "---+";
            } else {
                std::cout << "   +";
            }
        }
        std::cout << "\n";
    }
}

int Zoo::countNeighboringForests(const Enclosure& enclosure) const {
    std::vector<Enclosure*> neighbors;
    int x = enclosure.getBaseColumn();
    int y = enclosure.getBaseRow();
    int w = enclosure.getWidth();
    int h = enclosure.getHeight();
    
    // Check all 8 possible neighboring positions
    for (int dy = -1; dy <= h; ++dy) {
        for (int dx = -1; dx <= w; ++dx) {
            int nx = x + dx;
            int ny = y + dy;
            
            // Skip positions outside zoo bounds
            if (nx < 0 || ny < 0 || nx >= width_ || ny >= height_) {
                continue;
            }
            
            // Skip positions that are part of the enclosure itself
            if (dx >= 0 && dx < w && dy >= 0 && dy < h) {
                continue;
            }
            
            Enclosure* neighbor = enclosures_[ny][nx];
            if (neighbor != nullptr && 
                neighbor != &enclosure &&
                neighbor->getType() == EnclosureType::Forest &&
                std::find(neighbors.begin(), neighbors.end(), neighbor) == neighbors.end()) {
                neighbors.push_back(neighbor);
            }
        }
    }
    
    return neighbors.size();
}

// Private helper methods
void Zoo::printWelcomeMessage() const {
    std::cout << "\nWelcome to your Zoo \"" << name_ << "\"!\n"
              << "This zoo has a size of " << width_ << " x " << height_ << "!\n";
}


void Zoo::clearEnclosures() {
    std::vector<Enclosure*> unique_enclosures;
    
    // Find all unique enclosures
    for (const auto& row : enclosures_) {
        for (const auto& enclosure : row) {
            if (enclosure != nullptr && 
                std::find(unique_enclosures.begin(), unique_enclosures.end(), enclosure) == unique_enclosures.end()) {
                unique_enclosures.push_back(enclosure);
            }
        }
    }
    
    // Delete each unique enclosure
    for (auto& enclosure : unique_enclosures) {
        delete enclosure;
    }
    
    // Clear the enclosure grid
    for (auto& row : enclosures_) {
        for (auto& enclosure : row) {
            enclosure = nullptr;
        }
    }
}

// Command processing helpers
void Zoo::processShopCommand() {
    shop_.printInfo();
}


void Zoo::processInfoCommand(const std::vector<std::string>& params) {
    if (params.empty()) {
        // General zoo info
        int empty_fields = 0;
        int empty_enclosures = 0;
        int animal_count = 0;
        std::vector<Enclosure*> unique_enclosures;
        
        // Count statistics
        for (const auto& row : enclosures_) {
            for (const auto& enclosure : row) {
                if (enclosure == nullptr) {
                    empty_fields++;
                } else {
                    // Check if we've seen this enclosure before
                    if (std::find(unique_enclosures.begin(), unique_enclosures.end(), enclosure) == unique_enclosures.end()) {
                        unique_enclosures.push_back(enclosure);
                        // Count animals only once per enclosure
                        animal_count += enclosure->getAnimals().size();
                        if (enclosure->getAnimals().empty()) {
                            empty_enclosures++;
                        }
                    }
                }
            }
        }

        std::cout << "Zoo Name: " << name_ << "\n"
                  << "Money: " << money_ << " coin(s)\n"
                  << "Number of Animals: " << animal_count << "\n"
                  << "Empty fields: " << empty_fields << "\n"
                  << "Empty enclosures: " << empty_enclosures << "\n";
    } 
    else if (params.size() == 2) {
        // Specific enclosure info
        try {
            int col = std::stoi(params[0]) - 1;  // Convert to 0-based index
            int row = std::stoi(params[1]) - 1;
            
            // Validate position
            if (row < 0 || row >= height_ || col < 0 || col >= width_) {
                std::cout << "[ERROR] Invalid field position!\n";
               
                return;
            }
            
            Enclosure* enclosure = enclosures_[row][col];
            if (enclosure == nullptr) {
                std::cout << "[ERROR] Field is not part of an enclosure!\n";
                return;
            }
            
            // Print enclosure info
            std::cout << "Enclosure: ";
            switch (enclosure->getType()) {
                case EnclosureType::Savanna: std::cout << "Savanna"; break;
                case EnclosureType::Forest: std::cout << "Forest"; break;
                case EnclosureType::Aquarium: std::cout << "Aquarium"; break;
            }
            std::cout << "\n";
            
            // Print animal list if any
            const auto& animals = enclosure->getAnimals();
                std::cout << "List of inhabitants:\n";
                for (const Animal* animal : animals) {
                    std::cout << "- ";
                    animal->printInformation();
                }
        } 
        catch (...) {
            std::cout << "[ERROR] Invalid field position!\n";
            
        }
    } 
    else {
        std::cout << "[ERROR] Wrong number of parameters for this command!\n";
    }
}

void Zoo::processMapCommand() {
    
    if(map_active_)
    {
        map_active_ = false;
    }
    else{
        map_active_ = true;
    }

    if (map_active_) {
        printMap();
    }
}

void Zoo::processBuildCommand(const std::vector<std::string>& params) {
    if (params.size() != 5) {
        std::cout << "[ERROR] Wrong number of parameters for this command!\n";
        return;
    }

    try {
        std::string type = params[0];
        int col, row, width, height;

        // Validate all numeric parameters first
        if (!Utils::decimalStringToInt(params[1], col) || 
            !Utils::decimalStringToInt(params[2], row) ||
            !Utils::decimalStringToInt(params[3], width) || 
            !Utils::decimalStringToInt(params[4], height)) {
            std::cout << "[ERROR] No enclosure with given type!\n";
            return;
        }

        // Convert to 0-based indices
        col--;
        row--;

        // Validate parameters
        if (width <= 0 || height <= 0) {
            std::cout << "[ERROR] Invalid width or height!\n";
            return;
        }

        

        // Calculate cost and create enclosure
        int cost = 0;
        Enclosure* new_enclosure = nullptr;
        
           
        if (type == "savanna" || type == "Savanna") {
            

            if (row < 0 || row >= height_ || col < 0 || col >= width_) {
            std::cout << "[ERROR] Invalid field position!\n";
            return;
            }
            
            cost = width * height * 1000;
            if (money_ < cost) {
                delete new_enclosure;
                std::cout << "[ERROR] There is not enough money!\n";
                return;
            }
            new_enclosure = new Savanna(col, row, width, height);
            if (!canBuildEnclosure(col, row, width, height)) {
                delete new_enclosure;
                std::cout << "[ERROR] Enclosure does not fit!\n";
                return;
            }
        } 
        else if (type == "forest" || type == "Forest") {
             
            if (row < 0 || row >= height_ || col < 0 || col >= width_) {
                std::cout << "[ERROR] Invalid field position!\n";
                return;
            }
            cost = width * height * 3000;
            if (money_ < cost) {
                delete new_enclosure;
                std::cout << "[ERROR] There is not enough money!\n";
                return;
            }
            new_enclosure = new Forest(col, row, width, height);
            if (!canBuildEnclosure(col, row, width, height)) {
                delete new_enclosure;
                std::cout << "[ERROR] Enclosure does not fit!\n";
                return;
            }
        } 
        else if (type == "aquarium" || type == "Aquarium") {
             

            if (row < 0 || row >= height_ || col < 0 || col >= width_) {
                std::cout << "[ERROR] Invalid field position!\n";
                return;
            }
            cost = width * height * 10000;
            if (money_ < cost) {
                delete new_enclosure;
                std::cout << "[ERROR] There is not enough money!\n";
                return;
            }
            new_enclosure = new Aquarium(col, row, width, height);
            if (!canBuildEnclosure(col, row, width, height)) {
                delete new_enclosure;
                std::cout << "[ERROR] Enclosure does not fit!\n";
                return;
            }
        } 
        else {
            std::cout << "[ERROR] No enclosure with given type!\n";
            return;
        }

        
               
        // Build the enclosure
        money_ -= cost;
        buildEnclosure(new_enclosure);
        empty_Enclosures_ += 1;
        if(map_active_)
        {
            printMap();
        }
        
    } catch (...) {
        std::cout << "[ERROR] Invalid parameters!\n";
    }
}

void Zoo::processBuyCommand(const std::vector<std::string>& params) {
    if (params.size() != 3) {
        std::cout << "[ERROR] Wrong number of parameters for this command!\n";
        return;
    }
    
    try {
        std::string animal_name = params[0];
        int col, row;

        // 1. First validate numeric parameters
        if (!Utils::decimalStringToInt(params[1], col) || 
            !Utils::decimalStringToInt(params[2], row)) {
            std::cout << "[ERROR] Invalid field position!\n";
            return;
        }

        // Convert to 0-based
        col--;
        row--;


        // Validate position
        if (row < 0 || row >= height_ || col < 0 || col >= width_) {  
            std::cout << "[ERROR] Invalid field position!\n";
            return;
        }
        
        // Find animal in shop
        Animal* animal = shop_.getAnimal(animal_name);
        if (animal == nullptr) {
            std::cout << "[ERROR] No animal with given name in the shop!\n";
            return;
        }

        // Check enclosure exists
        Enclosure* enclosure = enclosures_[row][col];
        if (enclosure == nullptr) {
            std::cout << "[ERROR] Field is not part of an enclosure!\n";
            return;
        }

        
        
        // Validate purchase
        if (money_ < animal->getPrice()) {
            std::cout << "[ERROR] There is not enough money!\n";
            return;
        }

        if (!enclosure->hasRoom()) {
            std::cout << "[ERROR] There is not enough space in this enclosure!\n";
            return;
        }
        
        if (!enclosure->isAnimalAllowed(animal->getType())) {
            std::cout << "[ERROR] This animal is not allowed here!\n";
            return;
        }

        
        
        // Complete purchase
        money_ -= animal->getPrice();
        
        enclosure->addAnimal(animal);
        empty_Enclosures_ -= 1;
        shop_.buy(animal);
        if(map_active_)
        {
            printMap();
        }
        
    } catch (...) {
        std::cout << "[ERROR] Invalid parameters!\n";
    }
}

void Zoo::processRateCommand() {
    std::cout << "Individual ratings of enclosures:\n";
    
    int total_rating = 0;
    std::vector<Enclosure*> unique_enclosures;
    
    // Collect unique enclosures
    for (const auto& row : enclosures_) {
        for (const auto& enclosure : row) {
            if (enclosure && 
                std::find(unique_enclosures.begin(), unique_enclosures.end(), enclosure) == unique_enclosures.end()) {
                unique_enclosures.push_back(enclosure);
            }
        }
    }
    
    // Sort enclosures by position (top-left to bottom-right)
    std::sort(unique_enclosures.begin(), unique_enclosures.end(),
        [](const Enclosure* a, const Enclosure* b) {
            if (a->getBaseRow() != b->getBaseRow()) {
                return a->getBaseRow() < b->getBaseRow();
            }
            return a->getBaseColumn() < b->getBaseColumn();
        });
    
    // Calculate and print ratings
    for (const auto& enclosure : unique_enclosures) {
        int rating = enclosure->calculateRating(*this);
        total_rating += rating;
        
        std::cout << "- ";
        switch (enclosure->getType()) {
            case EnclosureType::Savanna: std::cout << "Savanna"; break;
            case EnclosureType::Forest: std::cout << "Forest"; break;
            case EnclosureType::Aquarium: std::cout << "Aquarium"; break;
        }
        std::cout << " (" << enclosure->getBaseColumn() + 1 << "/" 
                  << enclosure->getBaseRow() + 1 << "): " << rating << "\n";
    }
    
    std::cout << "Your zoo has an overall rating of " << total_rating << "!\n";
    if (map_active_)
    {
        printMap();
    }
}