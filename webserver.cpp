
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webserver{

  private:
    request req;
    int rinTime;
    char serverName;

  public:

    //Constructor
    webserver(): rinTime(0), serverName(' ') {}
    webserver(char n): rinTime(0), serverName(n) {}

    //Adding a request to your server
    void addRequest(request r, int currTime){
      req = r;
      rinTime = currTime;
    }

    //Getter functions
    request getRequest(){ return req; }
    char getName(){ return serverName; }

    bool isRequestFinish(int currTime){
      if(currTime > (rinTime + req.timeToProcess)){ return true; }
      else{ return false; }
    }

};
