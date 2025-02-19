#ifndef NET_HPP
#define NET_HPP

#include "PacketInfo.hpp"
#include <string>

class Net {
public:
    Net() = default;
    ~Net() = default;

    void initialize(const std::string& interface);
    PacketInfo capturePacket();

private:
    std::string netInterface;
};

#endif // NET_HPP
