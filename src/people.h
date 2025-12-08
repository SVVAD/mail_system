#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
using namespace std;
#include "parcels.h"
#include "track.h"

class person {
    private:
    string name;
    string surname;
    string password;
    public:
    //setters
    void setName(string Name) { name = Name; }
    void setSurname(string Surname) { surname = Surname; }
    void setPassword(string Password) { password = Password; }
    //getters
    string getName() { return name; }
    string getSurname() { return surname; }
    string getPassword() { return password; }
     void trackParcel(string trackNum, vector<parcel>& storage) {
        bool found = false;
        for (int i = 0; i < storage.size(); i++) {
            parcel& p = storage[i];
            if (p.getTrackingNumberString() == trackNum) {
                cout << "\n--- Parcel Info ---\n";
                cout << "Tracking Number:    " << p.getTrackingNumberString() << endl;
                cout << "Destination: " << p.getPostcode() << endl;
                cout << "Contents:    " << p.getContents() << endl;
                cout << "Weight:      " << p.getWeight() << endl;
                cout << "Status:      " << p.getStatus() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Parcel with that tracking number not found.\n";
        }
    }
};

class customer : public person {
    private:
    string email;

    public:
    void setEmail(string Email) { email = Email; }
    string getEmail() { return email; }
   
};

class clerk : public person {
private:
    string clerkID;

public:
    void setID(string id) { clerkID = id; }
    string getID() { return clerkID; }

    parcel sendParcel(string postC, double weight, double sX, double sY, double sZ, string contents, int ind)
    {
        parcel newParcel;
        TrackingNum trackNum;

        newParcel.setPostcode(postC);
        newParcel.setContents(contents);
        newParcel.setSize(sX, sY, sZ);
        newParcel.setTrackingNumber(trackNum.genTrack(ind));
        newParcel.setStatus("Received");
        return newParcel;
    }
    void changeStatus(string trackNum, vector<parcel>& storage, string newStatus) {
        for (int i = 0; i < storage.size(); i++) {
            if (storage[i].getTrackingNumberString() == trackNum) {
                cout << "Status changed to " << newStatus << " for " << trackNum << endl;
                storage[i].setStatus(newStatus);
                return;
            }
        }
        cout << "Tracking not found\n";
}};



#endif


