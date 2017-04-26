//
//  TicketManager.cpp
//  champlain

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "TicketManager.hpp"

// CONSTRUCTOR:
// takes input and ouput file strings
// sets the internal SeatPrices and SeatAvailability arrays from file contents

TicketManager::TicketManager(string inputFile, string outputFile)
{
    // Set outputfile to passed string
    setOutputFile(outputFile);
    
    // Populate the row prices
    populateRowPrices(inputFile);
    
    // Populate the seating availability chart/array
    populateSeatAvailability(outputFile);
}

void TicketManager::printSeats()
{
    // Print Columns/Seat #s
    int seatNum = 1;
    cout << "\t";
    for (int col = 0; col < COL_NUM; col++) {
        seatNum = seatNum < 10 ? seatNum : seatNum = 0;
        cout << seatNum;
        seatNum++;
    }
    cout << endl;
    
    // Print Rows
    for (int row = 0; row < ROW_NUM; row++)
    {
        cout << "Row " << row+1 << "\t";
        for (int col = 0; col < COL_NUM; col++)
        {
            string seatIcon = SeatAvailability[row][col].isAvailable ? "#" : "*";
            cout << seatIcon;
        }
        cout << endl;
    }
}

void TicketManager::ticketRequest(int numOfSeats, int desiredRow, int startSeatNum) {
    double salesTotal = 0.0;
    int currentSeatNum = startSeatNum;
    bool isAvailable = true;
    string willPurchase;
    SeatStructure seatArray[numOfSeats];
    
    // Make sure there's enough seats for this order on this row starting with the desired seat #
    if(startSeatNum + numOfSeats <= COL_NUM) {
        for(int i = 1; i <= numOfSeats; i++ ) {
            // Need -1 here because seat cols and rows start at 1, array starts at 0
            SeatStructure currentSeat = SeatAvailability[desiredRow-1][currentSeatNum-1];
            
            // Update seat array to pass to purchase method
            seatArray[i-1] = currentSeat;
            
            // Update total
            salesTotal += currentSeat.price;
            
            // update seat num
            currentSeatNum++;
            
            // Set availability on order (if one seat is unavailable, whole order is void)
            if(!currentSeat.isAvailable) {
                isAvailable = false;
                break;
            }
            
        }
        
        // If seat(s) are unavailable, notify user
        if(!isAvailable) {
            cout << endl;
            cout << "These seats are not available. Please try a different combination." << endl;
        }
        // If seats are available confirm order
        else {
            cout << endl;
            cout << "These seats are available. The total will be: $" << salesTotal << endl;
            cout << "Would you like to purchase? (y or n): ";
            cin >> willPurchase;
            if(willPurchase.find("y") != string::npos) {
                ticketPurchase(seatArray, numOfSeats);
            } else {
                cout << "Thank you for your interest." << endl;
            }
        }
    } else {
        cout << "There aren't enough seats in the row to fulfill your request from that starting seat.";
    }
}

void TicketManager::ticketPurchase(SeatStructure seatArray[], int size) {
    double inputMoney;
    double total = 0.0;
    
    // Set the total for purchase
    for(int i = 0; i < size; i++) {
        total += seatArray[i].price;
    }
    
    // Get the input for money
    cout << "Please enter money in dollars: ";
    cin >> inputMoney;
    
    // Output for user
    if(inputMoney < total) {
        cout << endl;
        cout << "That is not sufficient to purchase these tickets." << endl;
    } else {
        cout << endl;
        cout << "Sold. Here are your tickets: " << endl;
        // Print each ticket
        for(int i = 0; i < size; i++) {
            // Get row and seat from selected ticket
            int row = seatArray[i].row;
            int col = seatArray[i].col;
            
            // Update ticket as sold
            SeatAvailability[row][col].isAvailable = false;
            
            // Present ticket to user
            cout << "TICKET | row: "<< row + 1 << " seat: " << col + 1 << " price: $";
            cout << SeatAvailability[row][col].price << endl;
        }
    }
}

void TicketManager::populateRowPrices(string s)
{
    //First input and read the SeatPrices into an array
    double price;
    
    ifstream pricefile(s);
    if (pricefile.is_open())
    {
        for (int row = 0; row < ROW_NUM; row++) //loop over every row in .dat file
        {
            pricefile >> price;
            SeatPrices[row] = price; //Rememeber arrays start at 0!
        }
        pricefile.close(); //close file
    }
    else cout << "Unable to open file" << endl;
}

void TicketManager::populateSeatAvailability(string s)
{
    //Now read and input the SeatAvailability into an array of SeatStructures
    string line;
    bool seatavailable;
    ifstream seatfile(outputFile);
    if (seatfile.is_open())
    {
        for (int row = 0; row < ROW_NUM; row++) //loop over every line in .dat file
        {
            seatfile >> line;
            for (int col = 0; col < COL_NUM; col++) //loop over every character in line string
            {
                if (line[col] == '*') //if the character is * make seatavailable false
                    seatavailable = false;
                else
                    seatavailable = true; //otherwise make true
                
                SeatAvailability[row][col].isAvailable = seatavailable;
                SeatAvailability[row][col].price = SeatPrices[row];
                SeatAvailability[row][col].row = row;
                SeatAvailability[row][col].col = col;
            }
        }
        seatfile.close(); //close file
    }
    else cout << "Unable to open file" << endl;
}

void TicketManager::salesReport()
{
    int totalSold = 0;
    int totalSales = 0;
    int totalAvailable = 0;
    
    // Get sold seats, total available and total sales
    for (int row = 0; row < ROW_NUM; row++)
    {
        for (int col = 0; col < COL_NUM; col++)
        {
            if(!SeatAvailability[row][col].isAvailable) {
                totalSold++;
                totalSales += SeatAvailability[row][col].price;
            } else {
                totalAvailable++;
            }
        }
    }
    
    cout << endl << REPORT_HEADER;
    cout << left << setw(25) << "Total Sold: " << setw(10) << totalSold << endl;
    cout << left << setw(25) << "Total Available: " << setw(10) << totalAvailable << endl;
    cout << left << setw(25) << "Money Collected: " << setw(0) << "$" << setw(10) << totalSales << endl;
    
}

TicketManager::~TicketManager()
{
    // Destructor: write contents of array to output file
    ofstream seatfile(outputFile);
    if (seatfile.is_open())
    {
        for (int row = 0; row < ROW_NUM; row++)
        {
            string line;
            for (int col = 0; col < COL_NUM; col++)
            {
                line += SeatAvailability[row][col].isAvailable ? "#" : "*";
            }
            seatfile << line << "\n";
        }
        seatfile.close();
    }
    else cout << "Unable to open file" << endl;
}
