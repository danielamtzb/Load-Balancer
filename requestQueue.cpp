
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class requestQueue{
  private:
    std::queue<request> q;

  public:

    void enqueue(const request& req){ q.push(req); }

    request dequeue() {
      request front = q.front();
      q.pop();
      return front;
    }

    bool isEmpty() const { return q.empty(); }

};