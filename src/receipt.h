#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <string>
#include "print.h"
#include "receipt.h"
using namespace std;

class Receipt : public print, public item {
    private:
    double Paid;
    string ETA;
    string timestamp;

    public:
    Receipt(double price){
        Paid = price;
    }
    void printReceipt(){
        cout<< space << postOffice << endl;
        //cout << SetWidth(36, "CLERK:", ClerkName)<<endl;
        cout << SetWidth(36, "POST OFFICE:", "EGHAM, Church Road 67")<<endl;
        cout << GetTime();
        cout << space << MiddleStr(36, "RECEIPT") << space;
        
        cout << SetWidth(36, "RECEIPT:", to_string(getID())) << endl;
        //cout << SetWidth(36, "SENDER:", SenderName) << endl;
        //cout << SetWidth(36, "RECEIVER:", getReceiverName()) << endl;
        cout << SetWidth(36, "WEIGHT:", DoubleToStr(getWeight()) + " kg") << endl; 
        cout << SetWidth(37, "TOTAL PAID £:", DoubleToStr(Paid)) << endl;
        cout << SetWidth(36, "TRACKING:", getTrackingNumber());
        cout << SetWidth(36, "ETA:", ETA);
        cout <<space << "         ***THANK YOU!!!***         " << space;
    }
};
#endif