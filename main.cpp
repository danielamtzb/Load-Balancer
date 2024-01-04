#include <iostream>
#include "loadbalancer.h"

using namespace std;

int main() {
    int numServers, simulationTime;

    cout << "Enter the number of servers: ";
    cin >> numServers;

    cout << "Enter the clock cycles (in seconds): ";
    cin >> simulationTime;

    loadBalancer loadBalancer(numServers, simulationTime);
    loadBalancer.runSimulation();
}