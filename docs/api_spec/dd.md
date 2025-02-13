# IPC Library API Specification

## Overview
The IPC Library provides a flexible, runtime-configurable interface for inter-process communication.

## Class: IPCManager
### Description
Handles the selection and configuration of IPC mechanisms.

### Methods
#### `void setIPCType(IPCType type)`
- **Description:** Selects the IPC mechanism to use.
- **Parameters:**  
  - `IPCType type` - The IPC mechanism (e.g., `SHARED_MEMORY`, `SOCKETS`).
- **Returns:** `void`

#### `void sendMessage(const std::string& message)`
- **Description:** Sends a message using the active IPC method.
- **Parameters:**  
  - `message` - The message to send.
- **Returns:** `void`
