//
//  TicketManager.cpp
//  champlain

#include <iostream>
#include <fstream>
#include <string>
#include "TicketManager.hpp"

// CONSTRUCTOR:
// takes input and ouput file strings
// sets the internal SeatPrices and SeatAvailability arrays from file contents

TicketManager::TicketManager(string inputFile, string outputFile)
{
	//First input and read the SeatPrices into an array
	double price;

	ifstream pricefile(inputFile);
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
			}
		}
		seatfile.close(); //close file
	}
	else cout << "Unable to open file" << endl;
}

void TicketManager::printSeats()
{
    // Print Columns/Seat #s
    int seatNum = 1;
    cout << "\t\t";
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
	int salesTotal = 0;
    int currentSeatNum = startSeatNum;
    bool isAvailable = true;
    string willPurchase;

	if(startSeatNum + numOfSeats <= 30) {
		for(int i = 1; i <= numOfSeats; i++ ) {
	        // Need -1 here because seat cols and rows start at 1, array starts at 0
			SeatStructure currentSeat = SeatAvailability[desiredRow-1][currentSeatNum-1];
	        cout << "SEAT " << currentSeatNum << "| Available: " << (currentSeat.isAvailable ? "Yes" : "No") << ", ";
	        cout << "Price: $" << currentSeat.price << endl;
	        currentSeatNum++;

	        // Update total
	        salesTotal += currentSeat.price;

	        // Set availability on order
	        if(!currentSeat.isAvailable)
	            isAvailable = false;
		}

	    if(!isAvailable) {
	        cout << endl;
	        cout << "These seats are not available. Please try a different combination." << endl;
	    } else {
	        cout << "These seats are available. The total will be: $" << salesTotal << endl;
	        cout << "Would you like to purchase? (y or n): ";
	        cin >> willPurchase;
	        if(willPurchase.find("y") != string::npos) {
	            ticketPurchase(numOfSeats, desiredRow, startSeatNum);
	        } else {
	            cout << "Thank you for your interest." << endl;
	        }

	    }
	} else {
		cout << "There aren't enough seats in the row to fulfill your request from that starting seat.";
	}
}

void TicketManager::ticketPurchase(int numOfSeats, int desiredRow, int startSeatNum) {
    cout << "Purchase tickets..." << endl;
}
