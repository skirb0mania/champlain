//
//  main.cpp
//  GroupProject - SDEV-240-81
//
//

#include <iostream>

using namespace std;

class SeatStructure {

private:
    
    bool available;
    double price;
public:
    
    // Accessors (getters)
    
    double getPrice() { return price; }
    bool isAvailable() { return available; }
    
    // Mutators (setters)
    
    void setPrice(double p) { price = p; }
    void setAvailable(bool a) { available = a; }
    
};

//
// Function Prototypes
//
int displayMenu();
void executeSelection(int selection);

//
// Main Function
//
int main(int argc, const char * argv[]) {

    cout << "\nWelcome to Ticket Manager v0.0" << endl;
    cout << "==============================" << endl;
   
    // In reality, we'll probably call this in a loop
    // so the user can perform multiple operations  
    int selection = displayMenu();
    executeSelection(selection); 

    return 0;
}

//
// Function Definitions
//
int displayMenu() {

    int selection;

    cout << "\nSelect From the Following Menu Items:" << endl;
    cout << "1. Display Seating Chart" << endl;
    cout << "2. Request Tickets" << endl;
    cout << "3. Print Sales Report" << endl;
    cout << "4. Exit" << endl;
    cout << "\nEnter the Number of Your Choice: ";

    cin >> selection;
    return selection;
}

void executeSelection(int selection) {
    switch(selection) {
        case 1:
            cout << "You selected Display Seating Chart" << endl;
            break;
        case 2:
            cout << "You selected Request Tickets" << endl;
            break;
        case 3:
            cout << "You selected Sales Report" << endl;
            break;
        case 4:
            cout << "Have a Nice Day\n" << endl;
            break;
        default:
            cout << "Invalid Selection" << endl;
    } 
}
