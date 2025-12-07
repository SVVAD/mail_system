#include "login.h"
#include "parcels.h"
#include "people.h"
#include "receipt.h"
#include "track.h"
#include <vector>

vector<string> NumberDatabase;
vector<person> user_database;

int main(){
    
bool system_running = true;
    while (system_running) {
        
        
        
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
