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

    void setPostcode(const char* pc) {
        strncpy(postcode, pc, 6);
        postcode[5] = '\0';
    }

    void setDeliveryClass(int dc) { deliveryClass = dc; }

    void setTrackingNumber(const char* tn) {
        strncpy(trackingNumber, tn, 7);
        trackingNumber[6] = '\0';
    }

    // getters
    bool getType() const { return type; }

    const char* getPostcode() const { return postcode; }

    int getDeliveryClass() const { return deliveryClass; }

    const char* getTrackingNumber() const { return trackingNumber; }
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

    void setContents(const string& c) { contents = c; }

    // getters
    int getWeight() const { return weight; }

    const double* getSize() const { return size; }

    const string& getContents() const { return contents; }
};
