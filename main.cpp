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

int main(int argc, const char * argv[]) {

    //Do stuff
    
    return 0;
}

