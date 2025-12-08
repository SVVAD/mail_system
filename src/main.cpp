#include <iostream>
#include <string>
#include <vector>
using namespace std;
string dummy;
vector<string> username_database = {"svvad", "b", "Sam"}; //replace with class
vector<string> password_database = {"1234", "8008", "12"}; //replace with class
vector<string> trackingNum_database = {"A0HSAS", "W0A76Y"}; //replace with class

void Welcome();

int main(){
    string choose_log;
    while(1){//system loop
        Welcome();
        std::getline(cin, choose_log);    
        cout << endl;
    if(choose_log == "1"){  
        string login;
        string password;
        bool log_loop = 1;
        while(log_loop){//login loop
            int index = 0;
            cout << "Type 'exit' if you want to stop login process.\n";
            cout << "Please enter your username below: ";
            std::getline(cin, login);
            cout << endl;

            for (int i=0; i < username_database.size(); i++){//verify username exists
                if(login == "exit"){
                    log_loop=0;
                    break;
                }
                else if(login == username_database[i]){
                    break;
                }
                else{
                    index=i+1;
                    continue;}
            }

            if(index < password_database.size()){
                cout << "Please enter your password below: ";
                std::getline(cin, password);
                cout << endl;
                    if(password == password_database[index]){ //password database
                        cout << "User successfully logged in!\n";
                    while(1){//logged loop
                        string user_choice;
                        cout << "Welcome " << login << "!\n";
                        cout << "1. Track your parcel\n";
                        cout << "2. Print your receipt\n";
                        cout << "3. Exit\n";
                        cout << "Input: ";
                        std::getline(cin, user_choice);    
                        cout << endl;

                        if(user_choice == "1" || user_choice == "2"){
                            string track_log;

                            while(1){//Track loop
                                cout <<"Please input Tracking Number: ";
                                std::getline(cin, track_log);
                                cout << endl;
                                index = 0;
                                if(track_log.size() != 6){
                                    cout << "Tracking number is wrong!\n\n";                                
                                }

                                else{
                                    for (int i=0; i< trackingNum_database.size(); i++){    
                                        if(track_log==trackingNum_database[i]){
                                            break;
                                        }
                                        else{
                                            index = i+1;
                                        }
                                    }
                                    if(index < password_database.size()){
                                        cout << "Your tracking number is " << track_log << endl;
                                        //decode ID(same for parcel and receipts)
                                        if(user_choice == "1"){
                                            cout << "Here is you parcel status:\n";
                                            //print parcel status(from class parcel)
                                            break;
                                        }
                                        else if(user_choice == "2"){
                                            cout << "Here is you receipt:\n";
                                            //print receipt (same ID as parcel)
                                            break;
                                        }
                                    }
                                    
                                    else{
                                    cout << "Tracking number is wrong or doesn't exist!\n\n";
                                    }
                                }
                            }        
                        }
                        else if(user_choice == "3"){
                            log_loop=0;
                            break;
                        }
                        else {
                            cout << "Wrong Input!\n\n";
                        }
                    }
                    }
                    
                    else {
                        cout << "Wrong password!\n";
                    }
            }

            else if(!log_loop){
                cout << "Login process stopped...\n\n";
            }
            
            else{
                cout << "Username doen't exist!\n\n";
            }
        }
    } 


    else if(choose_log == "2"){
        string create;
        cout << "Worker login\n";    //
    }
    
    else if(choose_log == "3"){
        string create_login;
        string create_password;
        bool loop_create = 1; 
        while(loop_create){
            cout << "Type 'exit' if you want to stop creation process.\n";
            cout << "Write you login of choice (max 16 symbols)\n";
            cout << "Input: ";
            std::getline(cin, create_login);
            cout << endl;
            if(create_login == "exit"){
                cout << "\nExiting Creation menu...\n";
                break;
            }
            else if(create_login.size()<=16){
                for (int i=0; i < username_database.size(); i++){//verify username exists
                    if(create_login == username_database[i]){
                        cout << "Username already exists, try loggin in.\n";
                        loop_create=0;
                        break;
                    }                
                }
                if(loop_create){
                    cout << "Username added.\n";
                    username_database.push_back(create_login);
                    password_database.push_back("0");

                    //;
                while(1){
                    cout << "Write your password of choice (max 24 symbols)\n";
                    cout << "Input: ";
                    std::getline(cin, create_password);
                    cout << endl;
                    if(create_password.size() < 25){
                        break;
                    }
                    else{
                        cout << "Unaccepatble password. Try again.\n";
                    }                    
                }
                    password_database[username_database.size()-1] = create_password;
                    loop_create=0;
                    break;
                }
            }
            else{
                cout << "Login is Unacceptable!!!\n";
                cout << "Try again.\n";
            }
        }
    }

    else{
        cout << "Wrong Input!\n";
        choose_log = "";
    }
   
    }
        return 0;
}

void Welcome(){
    cout << "\n------------------------------------" << endl;
    cout << "Welcome to the Post Office System" << endl;
    cout << "1. Login into existing account" << endl;
    cout << "2. Worker login" << endl;
    cout << "3. Create User Account" << endl;
    cout << "------------------------------------" << endl;
    cout << "Input: ";
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
