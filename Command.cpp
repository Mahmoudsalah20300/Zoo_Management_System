#include "Command.hpp"
#include <algorithm>

// Constructor from input vector
Command::Command(std::vector<std::string>& input) {
    if (input.empty()) {
        type_ = CommandType::INVALID;
        return;
    }

    // Convert first parameter to lowercase for case-insensitive comparison
    std::string cmd = input[0];
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    // Determine command type
    if (cmd == "shop") {
        type_ = CommandType::SHOP;
    } else if (cmd == "info") {
        type_ = CommandType::INFO;
    } else if (cmd == "map") {
        type_ = CommandType::MAP;
    } else if (cmd == "build") {
        type_ = CommandType::BUILD;
    } else if (cmd == "buy") {
        type_ = CommandType::BUY;
    } else if (cmd == "quit") {
        type_ = CommandType::QUIT;
    } else if (cmd == "rate") {
        type_ = CommandType::RATE;
    } else {
        type_ = CommandType::INVALID;
    }

    // Store remaining parameters (if any)
    if (input.size() > 1) {
        parameters_.assign(input.begin() + 1, input.end());
    }
}

// Constructor from CommandType
Command::Command(CommandType type) : type_(type) {}

// Methods
bool Command::isQuit() const {
    return type_ == CommandType::QUIT;
}

CommandType Command::getType() const {
    return type_;
}

std::vector<std::string>& Command::getParameters() {
    return parameters_;
}

const std::vector<std::string>& Command::getParameters() const {
    return parameters_;
}

void Command::setType(CommandType type) {
    type_ = type;
}