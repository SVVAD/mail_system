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
    
};

#endif