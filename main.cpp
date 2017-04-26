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
static const string INPUT_FILE = "files/SeatPrices.dat";
static const string OUTPUT_FILE = "files/SeatAvailability.dat";
TicketManager tm = TicketManager(INPUT_FILE, OUTPUT_FILE);

//
// Function Prototypes
//
void displayMenu();
void executeSelection(int selection);
int checkMainInput(int input);
void initiateTicketRequest();
int getUserInputNumber(string, string);

//
// Main Function
//
int main(int argc, const char * argv[]) {
    int validSelection;
    
    cout << "\nWelcome to Ticket Manager v0.0" << endl;
    cout << "==============================" << endl;
    
    displayMenu();
    
    while(true) {
        validSelection = getUserInputNumber("\nEnter the Number of Your Choice: ", "Invalid Input.");
        executeSelection(validSelection);
        if(validSelection == 4) {
            break;
        } else {
            displayMenu();
        }
    }
    
    return 0;
}

//
// Function Definitions
//
void displayMenu() {

    cout << "\nSelect From the Following Menu Items:" << endl;
    cout << "1. Display Seating Chart" << endl;
    cout << "2. Request Tickets" << endl;
    cout << "3. Print Sales Report" << endl;
    cout << "4. Exit" << endl;
    
}

void executeSelection(int selection) {
    switch(selection) {
        case 1:
            cout << endl;
            tm.printSeats();
            cout << endl;
            break;
        case 2:
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

int getUserInputNumber(string userQuestion, string errorMsg) {
    int n;
    while(true) {
        cout << userQuestion;
        if (cin >> n) {
            break;
        } else {
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
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
