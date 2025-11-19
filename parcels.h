#include <string>
using namespace std;

class item{
    bool type; //if parcel or a letter
    char postcode[6]; //6 charachter post code
    int deliveryClass; // class pf the deliver
    char trackingNumber[6];
};

class parcel : item {
    int weight; //weight in gramms, round up to nearest gram
    double size[3];
    string contents;
}; 
