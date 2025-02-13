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

### **Implementation: `IPCInterface.h`**
```cpp
#ifndef IPC_INTERFACE_H
#define IPC_INTERFACE_H

#include <string>

class IPCInterface {
public:
    virtual ~IPCInterface() = default;
    virtual void sendMessage(const std::string& message) = 0;
    virtual std::string receiveMessage() = 0;
};

#endif // IPC_INTERFACE_H
```

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

### **Implementation: `UnixSocketIPC.h`**
```cpp
#ifndef UNIX_SOCKET_IPC_H
#define UNIX_SOCKET_IPC_H

#include "IPCInterface.h"
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

class UnixSocketIPC : public IPCInterface {
private:
    int socket_fd;
    struct sockaddr_un address;
    std::string socket_path = "/tmp/unix_socket_ipc";
public:
    UnixSocketIPC();
    ~UnixSocketIPC();
    void sendMessage(const std::string& message) override;
    std::string receiveMessage() override;
};

#endif // UNIX_SOCKET_IPC_H
```

---

### **Implementation: `UnixSocketIPC.cpp`**
```cpp
#include "UnixSocketIPC.h"
#include <iostream>
#include <cstring>

UnixSocketIPC::UnixSocketIPC() {
    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return;
    }
    memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, socket_path.c_str(), sizeof(address.sun_path) - 1);

    if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Error connecting to socket" << std::endl;
        close(socket_fd);
    }
}

UnixSocketIPC::~UnixSocketIPC() {
    close(socket_fd);
}

void UnixSocketIPC::sendMessage(const std::string& message) {
    send(socket_fd, message.c_str(), message.size(), 0);
}

std::string UnixSocketIPC::receiveMessage() {
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    recv(socket_fd, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}
```

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

