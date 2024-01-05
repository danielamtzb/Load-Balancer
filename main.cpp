#include <iostream>

#include "loadbalancer.h"

using namespace std;

/**
 * @brief The main function to run the load balancing simulation.
 * @return 0 if the program executed successfully.
 */
int main() {
    int numServers, clockCyles;

    cout << "Enter the number of servers: ";
    cin >> numServers;

    cout << "Enter the clock cycles (in seconds): ";
    cin >> clockCyles;

    // Create an instance of the load balancer
    loadbalancer lb(numServers, clockCyles);
    // Run the load balancing simulation
    lb.runSimulation();

    return 0;
}