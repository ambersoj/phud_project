#ifndef PACKETINFO_HPP
#define PACKETINFO_HPP

#include <string>

struct PacketInfo {
    int size = 0;
    std::string src_ip;
    std::string dst_ip;
};

#endif // PACKETINFO_HPP
