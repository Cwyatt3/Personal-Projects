#include <SFML/Network.hpp>
#include <iostream>
#include <string>

static bool port_is_open(const std::string &address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

int main()
{
    std::string address,
                choice;

    int port;
    
    
    std::cout << "Would you like to scan a specific port or all available (answer with specific or all)? \n";
    std::getline(std::cin, choice);
    
    if (choice == "specific") {

        std::cout << "Enter the IPv4 address: \n"; // Get the IPv4 address.
        std::getline(std::cin, address);

        std::cout << "Enter the port at the address: \n"; // Get the port.
        std::cin >> port;

        std::cout << "Scanning " << port << " at " << address << ": "; // Scan it with TCP protocol, and return Open or Closed.

        if (port_is_open(address, port))
            std::cout << "OPEN" << std::endl;
        else
            std::cout << "CLOSED" << std::endl;
    }
    else if (choice == "all") {
        
        std::cout << "Enter the IPv4 address: \n";
        std::getline(std::cin, address);

        for (long count = 0; count <= 65535; count++) { // Scans every possible IPv4 using TCP protocol.

            if (port_is_open(address, count))
                std::cout << "Port " << count << ": OPEN" << std::endl;
            else
                std::cout << "Port " << count << ": CLOSED" << std::endl;

        }

    }

    return 0;
}
