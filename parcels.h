#include <string>
using namespace std;

class item {
private:
    bool type; //if parcel or a letter
    char postcode[6]; //6 charachter post code
    int deliveryClass; // class pf the deliver
    char trackingNumber[6];
public:
    // setters
    void setType(bool t) { type = t; }

    void setPostcode(char* pc) {
        for (int i = 0; i < 6; i++) {
            postcode[i] = pc[i];
        }
    }

    void setDeliveryClass(int dc) { deliveryClass = dc; }

    void setTrackingNumber(char* tn) {
        for (int i = 0; i < 6; i++) {
            trackingNumber[i] = tn[i];
        }
    }

    // getters
    bool getType() { return type; }

    char* getPostcode() { return postcode; }

    int getDeliveryClass() { return deliveryClass; }

    char* getTrackingNumber() { return trackingNumber; }
};


class parcel : public item {
private:
    int weight; //weight in gramms, round up to nearest gram
    double size[3];
    string contents;
public:
    // setters
    void setWeight(int w) { weight = w; }

    void setSize(double x, double y, double z) {
        size[0] = x; size[1] = y; size[2] = z;
    }

    void setContents(string c) { contents = c; }

    // getters
    int getWeight() { return weight; }

    double* getSize() { return size; }

    string getContents() { return contents; }
};
