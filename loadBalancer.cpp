
#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

int loadBalancer::getTime(){ return time; }
void loadBalancer::incrTime(){ time++; }

void loadBalancer::addRequest(request req){ 
    reqQueue.enqueue(req);
    incrTime();
}

request loadBalancer::getRequest(){
    incrTime();
    if(!reqQueue.isEmpty()){
        request req = reqQueue.dequeue();
        return req;
    }
}

bool loadBalancer::isReqQueueEmpty(){
    return reqQueue.isEmpty();
}