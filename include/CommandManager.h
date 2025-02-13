#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <string>
#include <vector>

class CommandManager {
public:
    void loadCommandsFromDirectory(const std::string& directory);
    void executeCommand(const std::string& command, const std::vector<std::string>& args);
};

#endif // COMMAND_MANAGER_H