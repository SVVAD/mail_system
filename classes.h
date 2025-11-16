#include <string>

class item{
    bool type; //if parcel or a letter
    char postcode[6]; //6 charachter post code
    int deliveryClass; // class pf the delivery
};

class parcel : item {
    int weight; //weight in gramms, round up to nearest gram
    double size[3];
    std::string contents;
};