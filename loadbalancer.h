#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request.cpp"
#include "requestQueue.cpp"
#include "webserver.cpp"
#include <vector>

/**
 * @brief Represents a load balancer for web requests.
 */
class loadbalancer{
  private:
    int time; ///< Current simulation time.
    int clockCycles; ///< Total simulation time in clock cycles.
    int maxRequests; ///< Maximum number of requests in the system.
    requestQueue reqQueue; ///< Queue of incoming requests.
    std::vector<webserver> webServers; ///< Vector of web servers.

  public:
    /**
     * @brief Constructor for the load balancer.
     * @param numServers The number of web servers in the system.
     * @param clockCycles The total simulation time in clock cycles.
     */
    loadbalancer(int numServers, int clockCycles);

    /**
     * @brief Gets the current simulation time.
     * @return The current simulation time.
     */
    int getTime();

    /**
     * @brief Increments the simulation time.
     */
    void incrTime();

    /**
     * @brief Generates a full queue of requests.
     * @param numServers The number of web servers.
     */
    void generateFullQueue(int numServers);

    /**
     * @brief Adds a new request to the system at random times.
     */
    void addNewRequest();

    /**
     * @brief Gets the next request from the queue.
     * @return The next request.
     */
    request getRequest();

    /**
     * @brief Checks if the request queue is empty.
     * @return True if the request queue is empty, false otherwise.
     */
    bool isReqQueueEmpty();

    /**
     * @brief Runs the load balancing simulation until the queue is empty or the time limit is reached.
     */
    void runSimulation();

    /**
     * @brief Prints the current simulation state.
     */
    void printSimulation();
};

#endif
