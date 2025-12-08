#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>

#include "people.h"
#include "parcels.h"
#include "track.h"
#include "receipt.h"

using namespace std;

string dummy;

vector<customer> customers_db;
vector<clerk>    clerks_db;
vector<parcel>   parcels_db;

void InitDummy() {
    customer c1; c1.setName("svvad"); c1.setPassword("1234"); c1.setEmail("s@mail.com");
    customer c2; c2.setName("b");     c2.setPassword("8008"); c2.setEmail("b@mail.com");
    customer c3; c3.setName("Sam");   c3.setPassword("12");   c3.setEmail("sam@mail.com");
    customers_db.push_back(c1);
    customers_db.push_back(c2);
    customers_db.push_back(c3);

    clerk k1; k1.setName("12345678"); k1.setPassword("1234");
    clerk k2; k2.setName("87654321"); k2.setPassword("4321");
    clerk k3; k3.setName("SKOTT");    k3.setPassword("1111");
    clerks_db.push_back(k1);
    clerks_db.push_back(k2);
    clerks_db.push_back(k3);

    parcel p1;
    p1.setPostcode("KT13AA"); p1.setContents("Laptop"); p1.setSize(20, 30, 10); p1.setTrackingNumber("A0HSAS"); p1.setStatus("Received");
    parcel p2;
    p2.setPostcode("KT11BB"); p2.setContents("Docs");   p2.setSize(10, 5, 3);   p2.setTrackingNumber("W0A76Y"); p2.setStatus("On the way");
    parcels_db.push_back(p1);
    parcels_db.push_back(p2);

    cout << "Dummy test data loaded.\n";
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

void LoginUser(){
    string login;
    string password;
    bool log_loop = 1;
    while(log_loop){//login loop
        int index = 0;
        cout << "Type 'exit' if you want to stop login process.\n";
        cout << "Please enter your username below: ";
        std::getline(cin, login);
        cout << endl;

        for (int i=0; i < customers_db.size(); i++){//verify username exists
            if(login == "exit"){
                log_loop=0;
                break;
            }
            else if(login == customers_db[i].getName()){
                index = i;
                break;
            }
            else{
                index=i+1;
                continue;}
        }

        if(index < customers_db.size() && log_loop){
            cout << "Please enter your password below: ";
            std::getline(cin, password);
            cout << endl;
            if(password == customers_db[index].getPassword()){ //password database
                cout << "User successfully logged in!\n";
                customer* logged = &customers_db[index];
                while(1){//logged loop
                    string user_choice;
                    cout << "Welcome " << login << "!\n";
                    cout << "\n------------------------------------" << endl;
                    cout << "1. Track your parcel\n";
                    cout << "2. Print your receipt\n";
                    cout << "3. Exit\n";
                    cout << "\n------------------------------------" << endl;
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
                            
                            if(track_log == "exit"){
                                cout << "Exiting...\n";
                                break;
                            }

                            else if(track_log.size() != 6){
                                cout << "Tracking number is wrong!\n\n";                                
                            }
                            else{
                                for (int i=0; i< parcels_db.size(); i++){    
                                    if(track_log==parcels_db[i].getTrackingNumberString()){
                                        index = i;
                                        break;
                                    }
                                    else{
                                        index = i+1;
                                    }
                                }
                                if(index < parcels_db.size()){
                                    cout << "Your tracking number is " << track_log << endl;
                                    //decode ID(same for parcel and receipts)
                                    if(user_choice == "1"){
                                        cout << "Here is you parcel status:\n";
                                        //print parcel status(from class parcel)
                                        logged->trackParcel(track_log, parcels_db);
                                        break;
                                    }
                                    else if(user_choice == "2"){
                                        cout << "Here is you receipt:\n";
                                        //print receipt (same ID as parcel)
                                        Receipt R(parcels_db[index], 8.99);
                                        R.setETA("3 days");
                                        R.printReceipt();
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
            
        else{ cout << "Username doen't exist!\n\n";
        }
    }
}

void LoginClerk(){
    string clerk_login;
    string clerk_password;
    bool clerk_loop = 1;
    while(clerk_loop){//login loop
        cout << "Type 'exit' if you want to stop login process.\n";
        cout << "Please enter your ID below: ";
        std::getline(cin, clerk_login);
        cout << endl;
        int index=0;
        for (int i=0; i < clerks_db.size(); i++){//verify username exists
            if(clerk_login == "exit"){
                clerk_loop = 0;
                break;
            }
            else if(clerk_login == clerks_db[i].getName()){
                index = i;
                break;
            }
            else{
                index=i+1;
                continue;}
        }

        if(index < clerks_db.size() && clerk_loop){
            cout << "Please enter your password below: ";
            std::getline(cin, clerk_password);
            cout << endl;
            if(clerk_password == clerks_db[index].getPassword()){ //password database
                cout << "User successfully logged in!\n";
                clerk* logged = &clerks_db[index];
                string user_choice;
                while(1){//logged loop
                    cout << "\nWelcome " << clerk_login << "!\n";
                    cout << "------------------------------------" << endl;
                    cout << "1. Send the parcel\n";
                    cout << "2. Track the parcels\n";
                    cout << "3. Change the status of the parcel\n";
                    cout << "4. Exit\n";
                    cout << "\n------------------------------------" << endl;
                    cout << "Input: ";
                    std::getline(cin, user_choice);    
                    cout << endl;

                    if(user_choice == "1"){
                        string input;
                        cout << "Input parcel's details:";
                        cout << "\nInput weight of the pracel: ";
                        std::getline(cin, input);
                        //setWeight(std::stod(input));
                        double w = std::stod(input);

                        cout << "\nInput destination of the pracel: ";
                        std::getline(cin, input);
                        string dest = input;
                        //setPostcode(input);

                        cout << "\nInput contents of the pracel: ";
                        std::getline(cin, input);
                        string cont = input;
                        //setContents(input);

                        cout << "\nInput volume of the pracel: ";
                        std::getline(cin, input);
                        //setSize(inputstd::stod(input));
                        double vol = std::stod(input);
                        double sx = vol, sy = 1, sz = 1; // упрощённо, объём разбиваем как угодно

                        //Use dummy member of class parcel to parcel_database.push_back(dummy) this way storing class data 
                        parcel p = logged->sendParcel(dest, w, sx, sy, sz, cont, (int)parcels_db.size());
                        parcels_db.push_back(p);
                    }

                    else if(user_choice == "2" || user_choice == "3"){
                        string track_log;
                        while(1){//Track loop
                            cout <<"Please input Tracking Number: ";
                            std::getline(cin, track_log);
                            cout << endl;
                            index = 0;
                            
                            if(track_log == "exit"){
                                cout << "Exiting...\n";
                                break;
                            }

                            else if(track_log.size() != 6){
                                cout << "Tracking number is wrong!\n\n";                                
                            }
                            else{
                                for (int i=0; i< parcels_db.size(); i++){    
                                    if(track_log==parcels_db[i].getTrackingNumberString()){
                                        index = i;
                                        break;
                                    }
                                    else{
                                        index = i+1;
                                    }
                                }
                                if(index < parcels_db.size()){
                                    cout << "Your tracking number is " << track_log << endl;
                                    //decode ID(same for parcel and receipts)
                                    if(user_choice == "2"){
                                        cout << "Here is you parcel status:\n";
                                        //print parcel status(from class parcel)
                                        cout << "Status: " << parcels_db[index].getStatus() << endl;
                                        break;
                                    }

                                    else if(user_choice == "3"){
                                        string choice;
                                        while(1){
                                            cout << "The parcel currently " << parcels_db[index].getStatus() << endl; //change choice to current status of the parcel
                                            cout << "Choose to what status you want to change this parcel: \n";
                                            cout << "1. Received\n";
                                            cout << "2. Shipped\n";
                                            cout << "3. In Transit\n";
                                            cout << "4. Delivered\n";
                                            
                                            cout << "Input: ";
                                            std::getline(cin, choice);
                                            if(choice == "1"){
                                                /*setStatus == "Received"*/
                                                logged->changeStatus(track_log, parcels_db, "Received");
                                                cout << "Set status to Received\n";
                                                break;
                                            }
                                            else if(choice == "2"){
                                                /*setStatus == "Shipped"*/
                                                logged->changeStatus(track_log, parcels_db, "Shipped");
                                                cout << "Set status to Shipped\n";
                                                break;
                                            }
                                            else if(choice == "3"){
                                                /*setStatus == "In Transit"*/
                                                logged->changeStatus(track_log, parcels_db, "In Transit");
                                                cout << "Set status to In Transit\n";
                                                break;
                                            }
                                            else if(choice == "4"){
                                                /*setStatus == "Delivered"*/
                                                logged->changeStatus(track_log, parcels_db, "Delivered");
                                                cout << "Set status to Delivered\n";
                                                break;
                                            }
                                            else {
                                                cout << "Invalid Input\n";
                                            }
                                        }
                                        break;
                                    }                               
                                }
                                else{
                                    cout << "Tracking number is wrong or doesn't exist!\n\n";
                                }
                            }
                        }
                    }                  
                    else if(user_choice == "4"){
                        cout << "Exiting system...\n";
                        clerk_loop = 0;
                        break;
                    }
                    else{
                        cout << "Wrong input. Try again.\n";
                    }
                }
            }
            else {
                cout << "Wrong password!\n";
            }
        }
        else if(!clerk_loop){
            cout << "Login process stopped...\n\n";
        }
        else{ cout << "ID doen't exist!\n\n";
        }
    }
}

void CreateUser(){
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
            for (int i=0; i < customers_db.size(); i++){//verify username exists
                if(create_login == customers_db[i].getName()){
                    cout << "Username already exists, try loggin in.\n";
                    loop_create=0;
                    break;
                }                
            }
            if(loop_create){
                cout << "Username added.\n";
                //username_database.push_back(create_login);
                //password_database.push_back("0");

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
                customer nc;
                nc.setName(create_login);
                nc.setPassword(create_password);
                customers_db.push_back(nc);
                //password_database[username_database.size()-1] = create_password;
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

#endif
