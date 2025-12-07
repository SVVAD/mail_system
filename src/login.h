#include <iostream>
#include "people.h"

using namespace std;

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
void recipient_register(vector<customer>& users) {
    string new_user, new_pass;
    
    cout << "\n--- CREATE RECIPIENT ACCOUNT ---" << endl;
    cout << "Enter a new Username: ";
    cin >> new_user;
    cout << "Enter a new Password: ";
    cin >> new_pass;
    
    // Creating object and adding to vector
    customer newUser(new_user, new_pass);
    users.push_back(newUser);
    
    cout << "Account created successfully for " << new_user << endl;
}

// function for Recipient Login
void recipient_login(vector<customer& users) {
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
