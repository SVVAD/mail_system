#ifndef PARCELS_H
#define PARCELS_H

#include <string>
using namespace std;

class item {
    private:
    int ID;
    double size[3];
    double weight;
    string postcode; //6 charachter post code
    string contents;
    TrackingNum trackingNumber;

    public:
    // setters    
    void setPostcode(string pc) {
        postcode = pc;
    }
    void setTrackingNumber(TrackingNum tn){
       trackingNumber = tn;
    }
    void setContents(string c){
        contents = c; 
    }
    void setSize(double x, double y, double z) {
        size[0] = x; size[1] = y; size[2] = z;
    }   
    
    // getters
    int getID() {return ID;}
    double getWeight(){return weight;}
    double* getSize() { return size; }
    string getPostcode() { return postcode; }
    string getContents() { return contents; }
    TrackingNum getTrackingNumber() { return trackingNumber; }
};

class parcel : public item {
private:
    string destination;
    string status;

public:

    void setDestination(string d) { destination = d; }
    void setStatus(string s) { status = s; }

    string getDestination() { return destination; }
    string getStatus() { return status; }

    void updateStatus(string newStatus){
        status = newStatus;
    }
};
#endif
