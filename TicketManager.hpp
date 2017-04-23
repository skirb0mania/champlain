//
//  TicketManager.hpp
//  champlain
//
//  Created by Jon Lynch on 4/22/17.
//  Copyright © 2017 Jon Lynch. All rights reserved.
//

#ifndef TicketManager_hpp
#define TicketManager_hpp

//#include <stdio.h>

#include <string>
using namespace std;

// SeatStructure to hold price and availability of seat ticket
struct SeatStructure {
    double price;
    bool isAvailable;
    int row;
    int col;
};

static const int ROW_NUM = 15;
static const int COL_NUM = 30;

class TicketManager
{
public:
    TicketManager(string inputFile, string outputFile);
    ~TicketManager();
    void printSeats();
    void ticketRequest(int numOfSeats, int desiredRow, int startSeatNum);
    
    
    
private:
    SeatStructure SeatAvailability[ROW_NUM][COL_NUM];
    string outputFile;
    double SeatPrices[ROW_NUM];
    void ticketPurchase(SeatStructure seatArray[], int size);
    void setOutputFile(string s) { outputFile = s; };
    void populateRowPrices(string s);
    void populateSeatAvailability(string s);
};

#endif /* TicketManager_hpp */
