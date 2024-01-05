#include <iostream>

#include "loadbalancer.h"

using namespace std;

int main() {
    int numServers, clockCyles;

    cout << "Enter the number of servers: ";
    cin >> numServers;

    cout << "Enter the clock cycles (in seconds): ";
    cin >> clockCyles;


    loadbalancer lb(numServers, clockCyles);
    lb.runSimulation();

    return 0;
}