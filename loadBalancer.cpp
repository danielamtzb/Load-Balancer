
#include "loadbalancer.h"
#include <iostream>
#include <iomanip>

/**  Added comment
 * @brief Constructor for the LoadBalancer class.
 * @param numServers Number of servers in the load balancer.
 * @param clockCycles Number of clock cycles for the simulation.
 */
loadbalancer::loadbalancer(int numServers, int clockCycles): time(0), clockCycles(clockCycles), maxRequests(numServers * 20) {
    webServers.resize(numServers);
    generateFullQueue(maxRequests);  
}

/**
 * @brief Generates a full queue of requests with random IP addresses and processing times.
 * @param maxRequests Maximum number of requests to generate.
 */
void loadbalancer::generateFullQueue(int maxRequests){
    for(int i = 0; i < maxRequests; ++i){
        request newRequest{
            "192.168." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256),
            "203.0.113." + std::to_string(rand() % 256),
            rand() % 10 + 1
        };
        reqQueue.enqueue(newRequest);
    }
}

/**
 * @brief Adds a new request to the queue based on random conditions.
 */
void loadbalancer::addNewRequest() {
    int qSize = reqQueue.getQueueSize();
    int numServers = webServers.size();

    if (qSize >= maxRequests){
        maxRequests += 20;
        webServers.resize(numServers + 1);
    }else if(qSize < (numServers * 15)){
        maxRequests -= 20;
        webServers.resize(numServers - 1);
    }
    while((rand() % 5 == 0) || (rand() % 4 == 0)){
        request newRequest{
            "192.168." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256),
            "203.0.113." + std::to_string(rand() % 256),
            rand() % 10 + 1
        };
        reqQueue.enqueue(newRequest);
        std::cout << "New request added to the queue.\n";
    }
}

/**
 * @brief Gets the current simulation time.
 * @return Current simulation time.
 */
int loadbalancer::getTime(){ return time; }

/**
 * @brief Increments the simulation time.
 */
void loadbalancer::incrTime(){ time++; }

/**
 * @brief Gets a request from the queue.
 * @return Request object.
 */
request loadbalancer::getRequest(){
    request req{ "", "", 0 };
    if(!reqQueue.isEmpty()){
        req = reqQueue.dequeue();
        return req;
    } 
    return req;
}

/**
 * @brief Checks if the request queue is empty.
 * @return True if the queue is empty, false otherwise.
 */
bool loadbalancer::isReqQueueEmpty(){
    return reqQueue.isEmpty();
}

/**
 * @brief Runs the simulation loop until the request queue is empty or the specified clock cycles are reached.
 */
void loadbalancer::runSimulation() {
    while(!reqQueue.isEmpty() && time < clockCycles){
        incrTime();
        addNewRequest();
        for(auto& server : webServers){
            //Add request if server is empty
            if(server.getRinTime() == 0){
                request currRequest = reqQueue.dequeue();
                server.addRequest(currRequest, time);
            }else if(server.isRequestFinish(time)){     //Add request if the server is finished
                request currRequest = reqQueue.dequeue();
                server.addRequest(currRequest, time);
            }
        }
        if(time % 50 == 0 || time == 1 || time == clockCycles){
            printSimulation();
        }
    }
}

/**
 * @brief Prints the current simulation status, including server information.
 */
void loadbalancer::printSimulation(){
    std::cout << "+--------------------------------------------------------------------------+\n";
    std::cout << "|                             Current Time: " << std::setw(5) << this->time << std::setw(28) << " |\n";
    std::cout << "|                          Requests on Queue: " << std::setw(5) << this->reqQueue.getQueueSize() << std::setw(26) << " |\n";
    std::cout << "|   Server ipIN    |   Server ipOut   | Time it finishes | Time to Process |\n";
    std::cout << "+--------------------------------------------------------------------------+\n";

    for(auto& server : webServers){
        int serverTime = server.getRinTime() + server.getReq().timeToProcess;
        std::cout << "| " << std::setw(16) << server.getReq().ipIn
                  << " | " << std::setw(16) << server.getReq().ipOut
                  << " | " << std::setw(8) << serverTime << std::setw(11)
                  << " | " << std::setw(8) << server.getReq().timeToProcess << std::setw(10) << " |\n";
    }
    std::cout << "+--------------------------------------------------------------------------+\n";
}