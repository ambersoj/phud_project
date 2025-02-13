#include "CommandManager.h"
#include <iostream>

void CommandManager::loadCommandsFromDirectory(const std::string& directory) {
    std::cout << "Loading commands from: " << directory << std::endl;
}

void CommandManager::executeCommand(const std::string& command, const std::vector<std::string>& args) {
    std::cout << "Executing command: " << command << std::endl;
}
