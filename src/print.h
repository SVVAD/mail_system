#ifndef PRINT_H
#define PRINT_H

#include <ctime>
#include <sstream>
using namespace std;

class print{
    public:
    const string space = "\n------------------------------------\n";
    const string postOffice =  "      ***RHUL POSTAL OFFICE***      ";
    const string tyvm =  "         ***THANK YOU!!!***         ";

    string GetTime(){
        time_t timestamp;
        time(&timestamp);
        char output[16];
        strftime(output, 16, "%T", localtime(&timestamp));
        return output;
    }

    string GetDate(){
        time_t timestamp;
        time(&timestamp);
        char output[16];
        strftime(output, 16, "%d/%m/%y", localtime(&timestamp));
        return output;
    }

    string SetWidth(int totalWidth, string one, string two){
        int spaces;
        string msg;
        spaces = totalWidth - one.size() - two.size();
        if (spaces < 0) spaces = 0;
        msg = one + string(spaces, ' ') + two;
        return msg;
    }
    string MiddleStr(int totalWidth, string middle){ //method to display string in the middle of the receipt
        int spc;
        string msg;
        spc = (totalWidth - middle.size())/2;
        if (spc < 0) spc = 0;
        msg = string(spc, ' ') + middle + string(spc, ' ');
        return msg;
    }
    string DoubleToStr(double dabl){
        ostringstream str;
        str << dabl;
        return str.str();
    }
};
    
#endif