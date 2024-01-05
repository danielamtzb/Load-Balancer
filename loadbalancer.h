#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "request.cpp"

#include "requestQueue.cpp"
#include "webserver.cpp"
#include <vector>


class loadbalancer{
  private:
    int time;
    int clockCycles;
    requestQueue reqQueue;
    std::vector<webserver> webServers;

  public:
    //Constructor
    loadbalancer(int numServers, int clockCycles);

    int getTime();
    void incrTime();

    void generateFullQueue(int numServers);
    void addNewRequest();

    request getRequest();
    bool isReqQueueEmpty();

    void runSimulation();
    void printSimulation();
};

#endif