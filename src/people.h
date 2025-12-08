#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

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
        TrackingNum trackNum(ind);
        
        newParcel.setPostcode(postC);
        newParcel.setContents(contents);
        newParcel.setSize(sX, sY, sZ);
        newParcel.setTrackingNumber( trackNum.genTrack(ind));
        return newParcel;
    }
};



#endif
