#include <string>
#include <vector>
using namespace std;

class genTrackingNum{//class to generate tracking number
    vector<string> NumberDatabase;
    void genNumber(int n, bool parcel){//input which parcel it is since start of the program
        srand(n+1); //use parcel index as seed
        int seed = rand(); //generate seed for tracking number
        string number; 
        
        if(parcel){
            number = (char)(65+rand()%26);//if parcel first letter is Uppercase
        }
        else{
            number = (char)(97+rand()%26);//if letter first char is lowercase
        }
        number = number + (char)(48+rand()%10);
        for(int i=0; i<4;i++){
            srand(seed+101*i);
            int num = rand()%36;
            if(num < 10){
                char let = num;
            }
            else{
                number = number + (char)(55+num);
            } 
        }
        NumberDatabase[n] = number;         
    }
    
};