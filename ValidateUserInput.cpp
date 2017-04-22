// Joseph Dyke
// Build and test function to validate user input

#include <iostream>
using namespace std;

// Function prototype check user input
int CheckMainInput(int, int);

//main function 
int main()
{
	int choice;
	int min = 1, //minimum acceptable user input
		max = 4; //max acceptable user input
	 //create a demo menu
	cout << "Main Menu:\n"
		<< "1. Display seating chart\n"
		<< "2. Request tickets\n"
		<< "3. Print sales report\n"
		<< "4. Exit\n";

	choice = CheckMainInput(min, max);

	cout << "\n You have selected: " << choice << endl;

	return 0;
}

//*      CheckMainInput Function     *
//This function validates that a users input
//is between min and max. If the value is not
//the function asks the user to enter another value
//it returns the validated user input
int CheckMainInput(int min, int max)
{
	int input;

	// Get and validate the input
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Enter an integer between " << min << " and " << max << ": ";
		cin >> input;
	}
	return input;
}
