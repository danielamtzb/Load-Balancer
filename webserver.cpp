
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <string>

class webserver{

  private:
    request req;
    int rinTime;

  public:

    //Constructor
    webserver(): rinTime(0) {}

    //Adding a request to your server
    void addRequest(request r, int currTime){
      req = r;
      rinTime = currTime;
    }

    //Getter functions
    request getReq(){ return req; }
    int getRinTime(){ return rinTime; }

    bool isRequestFinish(int currTime){
      if(currTime > (rinTime + req.timeToProcess)){ return true; }
      else{ return false; }
    }

};
