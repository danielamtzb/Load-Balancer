#define REQUESTQUEUE_CPP

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>
#include <iostream>

class requestQueue{
  private:
    std::queue<request> q;
    int sizeQueue;

  public:

    void enqueue(const request& req){ 
      q.push(req); 
      sizeQueue++;
    }

    request dequeue() {
      request front = q.front();
      q.pop();
      sizeQueue--;
      return front;
    }

    int getQueueSize(){ return sizeQueue; }

    bool isEmpty() const { 
      if(q.empty()){
        std::cout << "The Queue is empty\n";
        return true;
      } else{ return false; }
    }

};