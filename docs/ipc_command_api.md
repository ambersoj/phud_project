# IPC & Command Execution Libraries - API Specification

## Overview
This document defines the API specifications for the IPC Selection & Configuration Library and the Command Execution Library. It includes descriptions of classes, methods, and their expected behaviors.

---

## 1️⃣ IPC Library API Specification

### **Class: `IPCManager`**
#### **Description:**
Handles the selection, configuration, and communication of various IPC mechanisms.

#### **Methods:**
```cpp
void setIPCType(IPCType type);
```
- **Description:** Selects the IPC mechanism.
- **Parameters:**
  - `IPCType type` - The IPC mechanism (e.g., `SHARED_MEMORY`, `SOCKETS`).
- **Returns:** `void`

```cpp
void sendMessage(const std::string& message);
```
- **Description:** Sends a message using the selected IPC method.
- **Parameters:**
  - `message` - The message to send.
- **Returns:** `void`

```cpp
std::string receiveMessage();
```
- **Description:** Receives a message using the active IPC method.
- **Returns:** `std::string` - The received message.

---

### **Class: `IPCFactory`**
#### **Description:**
Factory class responsible for instantiating the appropriate IPC communication object.

#### **Methods:**
```cpp
static std::unique_ptr<IPCInterface> createIPC(IPCType type);
```
- **Description:** Creates an IPC instance based on the selected type.
- **Parameters:**
  - `IPCType type` - The IPC mechanism (e.g., `SOCKETS`, `SHARED_MEMORY`).
- **Returns:** A unique pointer to an `IPCInterface` instance.

---

### **Interface: `IPCInterface`**
#### **Description:**
Defines a generic interface for all IPC mechanisms.

#### **Methods:**
```cpp
virtual void sendMessage(const std::string& message) = 0;
```
- **Description:** Sends a message over the IPC method.
- **Returns:** `void`

```cpp
virtual std::string receiveMessage() = 0;
```
- **Description:** Receives a message over the IPC method.
- **Returns:** `std::string`

---

### **Class: `UnixSocketIPC` (First IPC Implementation)**
#### **Description:**
Implements IPC using UNIX domain sockets.

#### **Methods:**
```cpp
void sendMessage(const std::string& message) override;
```
- **Description:** Sends a message via a UNIX domain socket.
- **Returns:** `void`

```cpp
std::string receiveMessage() override;
```
- **Description:** Receives a message via a UNIX domain socket.
- **Returns:** `std::string`

---

### **Implementation: `IPCManager.h`**
```cpp
#ifndef IPC_MANAGER_H
#define IPC_MANAGER_H

#include <memory>
#include "IPCInterface.h"

class IPCManager {
private:
    std::unique_ptr<IPCInterface> ipc;
public:
    void setIPCType(IPCType type);
    void sendMessage(const std::string& message);
    std::string receiveMessage();
};

#endif // IPC_MANAGER_H
```

---

### **Implementation: `IPCManager.cpp`**
```cpp
#include "IPCManager.h"
#include "UnixSocketIPC.h"

void IPCManager::setIPCType(IPCType type) {
    if (type == IPCType::SOCKETS) {
        ipc = std::make_unique<UnixSocketIPC>();
    }
}

void IPCManager::sendMessage(const std::string& message) {
    if (ipc) {
        ipc->sendMessage(message);
    }
}

std::string IPCManager::receiveMessage() {
    if (ipc) {
        return ipc->receiveMessage();
    }
    return "";
}
```

---

## 2️⃣ Command Execution Library API Specification

### **Class: `CommandManager`**
#### **Description:**
Handles dynamic loading and execution of user-defined commands.

#### **Methods:**
```cpp
void loadCommandsFromDirectory(const std::string& directory);
```
- **Description:** Loads `.so` command plugins from a specified directory.
- **Parameters:**
  - `directory` - Path to the directory containing command plugins.
- **Returns:** `void`

```cpp
void executeCommand(const std::string& command, const std::vector<std::string>& args);
```
- **Description:** Executes a user-defined command by dynamically loading the corresponding `.so` file.
- **Parameters:**
  - `command` - The name of the command.
  - `args` - A vector of command arguments.
- **Returns:** `void`

---

