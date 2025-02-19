#ifndef NET_HPP
#define NET_HPP

#include <string>
#include "PacketInfo.hpp"

class Net {
public:
    Net() = default;
    ~Net() = default;

    void initialize(const std::string& interface);
    PacketInfo capturePacket();  // ✅ Ensure this is declared

private:
    std::string netInterface;
};

#endif // NET_HPP
