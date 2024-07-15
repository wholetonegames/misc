#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // Initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    // Get the local hostname
    char hostname[256];
    result = gethostname(hostname, sizeof(hostname));
    if (result == SOCKET_ERROR)
    {
        std::cerr << "gethostname failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Get the host information
    struct hostent *host = gethostbyname(hostname);
    if (host == nullptr)
    {
        std::cerr << "gethostbyname failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Print the IP addresses
    for (int i = 0; host->h_addr_list[i] != nullptr; i++)
    {
        std::cout << "i: " << i << std::endl;
        struct in_addr addr;
        memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
        std::cout << "IP Address: " << inet_ntoa(addr) << std::endl;
    }

    // Cleanup
    WSACleanup();

    return 0;
}
