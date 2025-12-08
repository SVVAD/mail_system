#ifndef TRACK_H
#define TRACK_H
#include "print.h"
#include <string>
using namespace std;

class TrackingNum{//class to generate tracking number  
    private:
    string trackingNumber;
    string creationDate;
    public:
    TrackingNum() {}
    TrackingNum(int index){
        trackingNumber = genTrack(index);
        //creationDate = GetTime();
    }
    void SetTrackNum(string TN)
    {
        trackingNumber = TN;
    }
    char numToChar(int number){
        int ascii;
        if(0<= number && number < 10){
            ascii = number + 48;
        }
        else if(10<= number && number < 36){ 
            ascii = number + 55;
        }
        else{ascii = 43;}
        return char(ascii);
    }
    string GetStringTrackNum()
    {
        return trackingNumber;
    }
    string genTrack(int index){
        string number = "543210";
        int char1 = rand()%26 + 10;
        int char2 = rand()%36;  
        int key = char1*char2*(char1+char2);
        int message;   
        message = key + index;
        
        number[5] = numToChar(char2);
        number[4] = numToChar(message%36);
        message /= 36;
        
        number[3] = numToChar(message%36);
        message /= 36;
        
        number[2] = numToChar(message%36);
        message /= 36;
        
        number[1] = numToChar(message%36); 
        number[0] = numToChar(char1);
        return number;
    }  
    
    int charToNum(char input){
        int ascii = int(input);
        int number;
        
        if(48<= ascii && ascii < 58){
            number = int(ascii) - 48;
        }
        else if(65<= ascii && ascii < 91){ 
            number = ascii - 55;
        }
        else{number = 0;}
        return number;
    }
    
    int ReadTrack(string Track){
        int char1 = charToNum(Track[0]);
        int char2 = charToNum(Track[5]);
        int key = char1*char2*(char1+char2);
        int index = 0;
        
        index += charToNum(Track[4]);
        index += 36*charToNum(Track[3]);
        index += 1296*charToNum(Track[2]);
        index += 46656*charToNum(Track[1]);
        index -= key;
        return index;
    }
};

#endif
