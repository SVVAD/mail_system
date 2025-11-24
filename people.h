#include <string>
using namespace std;

class person {
private:
    string name;
    string surname;
public:
//setters
void setName(string Name) { name = Name; }
void setSurname(string Surname) { surname = Surname; }
//getters
string returnName() { return name }
string returnSurname() { return surname }
};

class customer : public person {
};

class clerk : public person {
};

