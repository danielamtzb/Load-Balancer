#define REQUESTQUEUE_CPP

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>
#include <iostream>

/**
 * @brief Represents a queue of requests.
 */
class requestQueue{
  private:
    std::queue<request> q;  ///< The underlying queue data structure.
    int sizeQueue;  ///< The size of the queue.

  public:

    /**
     * @brief Enqueues a request into the queue.
     * @param req The request to be enqueued.
     */
    void enqueue(const request& req){ 
      q.push(req); 
      sizeQueue++;
    }

    /**
     * @brief Dequeues a request from the queue.
     * @return The front request in the queue.
     */
    request dequeue() {
      request front = q.front();
      q.pop();
      sizeQueue--;
      return front;
    }

    /**
     * @brief Gets the size of the queue.
     * @return The size of the queue.
     */
    int getQueueSize(){ return sizeQueue; }

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const { 
      if(q.empty()){
        std::cout << "The Queue is empty\n";
        return true;
      } else{ return false; }
    }

};