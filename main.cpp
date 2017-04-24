//
//  main.cpp
//  GroupProject - SDEV-240-81
//
//

#include <iostream>
#include "TicketManager.hpp"

using namespace std;

//
// Constants
//
static const string INPUT_FILE = "SeatPrices.dat";
static const string OUTPUT_FILE = "SeatAvailability.dat";
TicketManager tm = TicketManager(INPUT_FILE, OUTPUT_FILE);

//
// Function Prototypes
//
int displayMenu();
void executeSelection(int selection);
int checkMainInput(int input);
void initiateTicketRequest();

//
// Main Function
//
int main(int argc, const char * argv[]) {

    cout << "\nWelcome to Ticket Manager v0.0" << endl;
    cout << "==============================" << endl;

    // In reality, we'll probably call this in a loop
    // so the user can perform multiple operations
    int selection,
        validSelection;
    
    while(validSelection != 4) {
        selection = displayMenu();
        // changed this for now, checkMainInput() had an infinite loop on invalid inputs
        // although it does the same for string inputs here
        validSelection = selection;
        executeSelection(validSelection);
    }
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
            cout << "You selected Display Seating Chart" << endl << endl;
            tm.printSeats();
            cout << endl;
            break;
        case 2:
            cout << "You selected Request Tickets" << endl << endl;
            initiateTicketRequest();
            break;
        case 3:
            cout << "You selected Sales Report" << endl;
            tm.salesReport();
            break;
        case 4:
            cout << "Have a Nice Day\n" << endl;
            break;
        default:
            cout << "Invalid Selection" << endl;
    }
}

int checkMainInput(int input) {
    int in = input;
    while (in < 1 || in > 4) {
        cout << "Invalid Input.  Enter an integer between 1 and 4, inclusive: ";
        cin >> in;
    }

    return in;
}

void initiateTicketRequest() {
    // How many seats?
    int numOfSeats;
    cout << "How many seats would you like: ";
    cin >> numOfSeats;
    
    // Row Number
    int rowNumber;
    cout << "What row would you like: ";
    cin >> rowNumber;
    
    // Starting Seat
    int startingSeat;
    cout << "Which seat would you like to start in: ";
    cin >> startingSeat;
    
    // Request Tickets
    tm.ticketRequest(numOfSeats, rowNumber, startingSeat);
}
