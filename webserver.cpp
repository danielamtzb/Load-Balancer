
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <string>

class webserver{

  private:
    request req;
    int rinTime;
    std::string serverName;

  public:

    //Constructor
    webserver(): rinTime(0), serverName("") {}
    webserver(std::string n): rinTime(0), serverName(n) {}

    //Adding a request to your server
    void addRequest(request r, int currTime){
      req = r;
      rinTime = currTime;
    }

    //Getter functions
    request getRequest(){ return req; }
    std::string getName(){ return serverName; }

    bool isRequestFinish(int currTime){
      if(currTime > (rinTime + req.timeToProcess)){ return true; }
      else{ return false; }
    }

};
