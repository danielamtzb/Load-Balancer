#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include "requestqueue.h"

class loadBalancer{

  private:
    int time;
    queue <request> reqQueue;

  public:
    //Constructor
    loadBalancer(): time(0) {}

    int getTime();
    void incrTime();

    void addRequest(request req);
    request getRequest();
    bool isReqQueueEmpty();
};

#include "loadbalancer.cpp"