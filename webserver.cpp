
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <string>

/**
 * @brief Represents a web server that processes requests.
 */
class webserver{

  private:
    request req;  ///< The request currently being processed by the server.
    int rinTime;  ///< The time when the request entered the server.

  public:

    /**
    * @brief Constructor for the webserver class.
    */
    webserver(): rinTime(0) {}

    /**
     * @brief Adds a request to the server.
     * @param r The request to be added.
     * @param currTime The current simulation time.
     */
    void addRequest(request r, int currTime){
      req = r;
      rinTime = currTime;
    }

    /**
     * @brief Gets the request currently being processed by the server.
     * @return The current request.
     */
    request getReq(){ return req; }

    /**
     * @brief Gets the time when the current request entered the server.
     * @return The time of entry.
     */
    int getRinTime(){ return rinTime; }

    /**
     * @brief Checks if the current request has finished processing.
     * @param currTime The current simulation time.
     * @return True if the request has finished processing, false otherwise.
     */
    bool isRequestFinish(int currTime){
      if(currTime > (rinTime + req.timeToProcess)){ return true; }
      else{ return false; }
    }

};
