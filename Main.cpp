#include <SFML/Network.hpp>
#include <iostream>
#include <string>

static bool port_is_open(const std::string &address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

int main()
{
    std::string address; 
    int port;
    
    std::cout << "Enter the IPv4 address: \n"; // Get the IPv4 address.
    std::getline(std::cin, address); 

    std::cout << "Enter the port at the address: \n"; // Get the port.
    std::cin >> port;
    
    std::cout << "Scanning " << port << " at " << address << ": "; // Scan it and return Open or Closed.

    if (port_is_open(address, 80))
        std::cout << "OPEN" << std::endl;
    else
        std::cout << "CLOSED" << std::endl;
    return 0;
}