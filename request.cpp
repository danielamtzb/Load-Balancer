
#define REQUEST_CPP

#include <string>

/**
 * @brief Represents a request with source IP, destination IP, and time to process.
 */
struct request{

    std::string ipIn;   ///< Source IP address.
    std::string ipOut;  ///< Destination IP address.
    int timeToProcess;  ///< Time required to process the request.
};