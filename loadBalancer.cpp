
#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

#include <iostream>

loadbalancer::loadbalancer(int numServers, int clockCycles): time(1), clockCycles(clockCycles) {
    webServers.resize(numServers);
    generateFullQueue(numServers);
}

void loadbalancer::generateFullQueue(int numServers){
    int size = numServers * 20;
    for(int i = 0; i < size; ++i){
        request newRequest{
            "192.168." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256),
            "203.0.113." + std::to_string(rand() % 256),
            rand() % 10 + 1
        };
        reqQueue.enqueue(newRequest);
    }
}

void loadbalancer::addNewRequest() {
    if(rand() % 5 == 0){
        request newRequest{
            "192.168." + std::to_string(rand() % 256) + "." + std::to_string(rand() % 256),
            "203.0.113." + std::to_string(rand() % 256),
            rand() % 10 + 1
        };
        reqQueue.enqueue(newRequest);
        std::cout << "New request added to the queue.\n";
    }
}

int loadbalancer::getTime(){ return time; }
void loadbalancer::incrTime(){ time++; }

request loadbalancer::getRequest(){
    request req{ "", "", 0 };
    if(!reqQueue.isEmpty()){
        req = reqQueue.dequeue();
        return req;
    } 
    return req;
}

bool loadbalancer::isReqQueueEmpty(){
    return reqQueue.isEmpty();
}


void loadbalancer::runSimulation() {
    while(!reqQueue.isEmpty() && time <= clockCycles){
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
        incrTime();
    }
    printSimulation();
}

void loadbalancer::printSimulation(){
    std::cout << "+--------------------------------------------------------+\n";
    std::cout << "                 Current Time: " << this->time << std::endl;
    std::cout << "|   Server ipIN    |   Server ipOut   | Time it finishes |\n";
    std::cout << "+--------------------------------------------------------+\n";

    for(auto& server : webServers){
        std::cout << "| " << server.getReq().ipIn << " | "
                << server.getReq().ipOut << " | " << server.getReq().timeToProcess << " |\n";
    }
    std::cout << "+--------------------------------------------------------+\n";
}