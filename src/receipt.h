#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <string>
#include "print.h"
#include "parcels.h"
using namespace std;

class Receipt : public print {
private:
    parcel& linkedParcel;   // reference
    double Paid;
    string ETA;
    string timestamp;

public:
    Receipt(parcel& p, double price)
    : linkedParcel(p)
    {
        Paid = price;
        timestamp = GetTime();
    }

    void setETA(string eta){
        ETA = eta;
    }

    void printReceipt(){

        cout << space << postOffice << endl;
        cout << SetWidth(36, "POST OFFICE:", "EGHAM, Church Road 67")<<endl;
        cout << timestamp;

        cout << space << MiddleStr(36, "RECEIPT") << space;

        cout << SetWidth(36, "RECEIPT:", to_string(getID())) << endl; 
        cout << SetWidth(36, "DEST:", linkedParcel.getDestination()) << endl;
        cout << SetWidth(36, "WEIGHT:", DoubleToStr(linkedParcel.getWeight()) + " kg") << endl;
        cout << SetWidth(37, "TOTAL PAID £:", DoubleToStr(Paid)) << endl;
        cout << SetWidth(36, "TRACKING:", linkedParcel.getTrackingNumber()) << endl; 
        cout << SetWidth(36, "ETA:", ETA);
        cout <<space << "         ***THANK YOU!!!***         " << space;
    }
};

#endif
