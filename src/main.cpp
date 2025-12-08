#include "functions.h"

int main(){
    string choose_log;
    while(1){//system loop
        Welcome();
        std::getline(cin, choose_log);    
        cout << endl;
    if(choose_log == "1"){  
        LoginUser();
    } 
    else if(choose_log == "2"){
        LoginClerk();
    }
    else if(choose_log == "3"){
       CreateUser();
    }
    else{
        cout << "Wrong Input!\n";
        choose_log = "";
    }   
    }
        return 0;
}

//This is a machine at the postal office, make it behave like one
    /*
loop1{
    
Customer register loop{
    1. make login
    1.1 Check login doesn't exist
    1.2 add login to vector
    2. create password
    3. Return to Choose screen
}
    
Login loop{
    Clerk login loop{
        1. Input parcel parameters
        2. calculate price
        3. make Tracking code
        4. print postage label
        5. print receipt
        6. logout
    }
        
    Customer login loop{
        1. Input login
        1.1 loop through array
        1.2 check login exists
        1.3 through back to choose or proceed
    2. Input password
        2.1 Check password at the same index
    3. enter as user
    4.check package status 
    }
}
}
    */
