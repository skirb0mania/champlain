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
};

static const int ROW_NUM = 15;
static const int COL_NUM = 30;

class TicketManager
{
	public:
	    TicketManager(string inputFile, string outputFile);
	    void printSeats();

    private:
		
    	double SeatPrices[ROW_NUM];
    	SeatStructure SeatAvailability[ROW_NUM][COL_NUM];
};

#endif /* TicketManager_hpp */
