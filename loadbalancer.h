#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#ifndef REQUESTQUEUE_CPP
#include "requestQueue.cpp"
#endif


class loadBalancer{

  private:
    int time;
    requestQueue reqQueue;

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