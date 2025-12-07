#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Recipient {
    private:
    string username;
    string password;
    public:
    // Constructor to create a new user object
    Recipient(string u, string p) {
        username = u;
        password = p;
    }
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
};

void postal_worker_login();                                 // Handles the staff login
void recipient_register(vector<Recipient>& users);          // Handles creating a new account
void recipient_login(vector<Recipient>& users);             // Handles user login


void Start () {
    vector<Recipient> user_database;
    // Main Menu Loop
    bool system_running = true;
    while (system_running) {
        
        cout << "\n------------------------------------" << endl;
        cout << "Welcome to the Post Office System" << endl;
        cout << "1. Postal Worker Login" << endl;
        cout << "2. Create Recipient Account" << endl;
        cout << "3. Recipient Login" << endl;
        cout << "4. Exit System" << endl;
        cout << "------------------------------------" << endl;
        
        // Asking user for choice
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        
        switch(choice){
            case 1:
            postal_worker_login();
            break;
            
            case 2:
            recipient_register(user_database);
            break;
            
            case 3:
            recipient_login(user_database);
            break;
            
            case 4:
            cout << "Shutting down system..." << endl;
            system_running = false;
            break;
            
            default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
}

// function for Postal Worker Login
void postal_worker_login() {
    string input_user, input_pass;
    
    cout << "\n--- POSTAL WORKER LOGIN ---" << endl;
    cout << "Enter Staff Username: ";
    cin >> input_user;
    cout << "Enter Staff Password: ";
    cin >> input_pass;
    
    // Hardcoded credentials as requested
    // Username: postie2025, Password: postie100
    if (input_user == "postie2025" && input_pass == "postie100") {
        cout << "Login Successful. Welcome, Postal Operator." << endl;
        cout << "* Accessing Admin Panel *" << endl;
        // Additional operator logic would go here
    }
    else {
        cout << "Access Denied. Incorrect Credentials." << endl;
    }
}

// function for Registering a Recipient
void recipient_register(vector<Recipient>& users) {
    string new_user, new_pass;
    
    cout << "\n--- CREATE RECIPIENT ACCOUNT ---" << endl;
    cout << "Enter a new Username: ";
    cin >> new_user;
    cout << "Enter a new Password: ";
    cin >> new_pass;
    
    // Creating object and adding to vector
    Recipient newUser(new_user, new_pass);
    users.push_back(newUser);
    
    cout << "Account created successfully for " << new_user << endl;
}

// function for Recipient Login
void recipient_login(vector<Recipient>& users) {
    string input_user, input_pass;
    bool login_success = false;
    
    cout << "\n--- RECIPIENT LOGIN ---" << endl;
    cout << "Enter Username: ";
    cin >> input_user;
    cout << "Enter Password: ";
    cin >> input_pass;
    
    // Loop through the vector of objects to find a match
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == input_user && users[i].getPassword() == input_pass) {
            login_success = true;
            break;
        }
    }
    
    if (login_success) {
        cout << "Login Successful. Welcome " << input_user << "." << endl;
        cout << "You can now track your parcels." << endl;
    }
    else {
        cout << "Login Failed. Invalid Username or Password." << endl;
    }
}

#endif