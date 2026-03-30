//---------------------------------------------------------------------------------------------------------------------
//
// The Command class represents a user command in the zoo management system.
// It stores the command type and associated parameters for processing.
//
// Author: Ali Mahmoud
// ID: 12347028
//---------------------------------------------------------------------------------------------------------------------

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>
#include <string>

enum class CommandType {
    SHOP,
    INFO,
    MAP,
    BUILD,
    BUY,
    QUIT,
    RATE,
    INVALID,
    WRONG_PARAM
};

class Command {
private:
    CommandType type_;
    std::vector<std::string> parameters_;

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Command object from a vector of input strings.
    //
    // @param input : Vector of strings containing the command and parameters
    //-----------------------------------------------------------------------------------------------------------------
    Command(std::vector<std::string>& input);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Constructs a Command object with a specific type and empty parameters.
    //
    // @param type : The CommandType to assign to this command
    //-----------------------------------------------------------------------------------------------------------------
    Command(CommandType type);
    
    //-----------------------------------------------------------------------------------------------------------------
    // Default copy constructor.
    //-----------------------------------------------------------------------------------------------------------------
    Command(const Command&) = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Default destructor.
    //-----------------------------------------------------------------------------------------------------------------
    ~Command() = default;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Checks if this is a QUIT command.
    //
    // @return true if command type is QUIT, false otherwise
    //-----------------------------------------------------------------------------------------------------------------
    bool isQuit() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets the type of this command.
    //
    // @return The CommandType of this command
    //-----------------------------------------------------------------------------------------------------------------
    CommandType getType() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets a modifiable reference to the command parameters.
    //
    // @return Reference to the vector of parameters
    //-----------------------------------------------------------------------------------------------------------------
    std::vector<std::string>& getParameters();
    
    //-----------------------------------------------------------------------------------------------------------------
    // Gets a const reference to the command parameters.
    //
    // @return Const reference to the vector of parameters
    //-----------------------------------------------------------------------------------------------------------------
    const std::vector<std::string>& getParameters() const;
    
    //-----------------------------------------------------------------------------------------------------------------
    // Sets the type of this command.
    //
    // @param type : The CommandType to set
    //-----------------------------------------------------------------------------------------------------------------
    void setType(CommandType type);
};

#endif // COMMAND_HPP