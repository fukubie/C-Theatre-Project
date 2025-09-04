#ifndef COMMON_H // If not Defined (incase included multiple times)
#define COMMON_H // Define

#include <iostream> // For input and output
#include <iomanip> // For formatting
#include <string> // For strings
#include <random> // For random numbers
#include <limits> // For max and min
#include <fstream> // For editing files

// Remove the need to type std:: before certain statements
using namespace std;

// Constants
const double SALES_TAX = 0.07; // Sales tax
const int WIDTH = 25;          // Width of menu
const int MAX_SEATS = 30;      // Maximum seats
const int ROWS = 3;            // Number of rows
const int COLUMNS = 10;        // Number of columns
const int MAX_MOVIES = 5;      // Maximum movies
const int MAX_TICKETS = 100;   // Maximum tickets
const int MAX_CONCESSIONS = 100; // Maximum concession items

// Structure for movie ticket
struct Ticket {
    string movieName;
    char ageCategory;
    int quantity;
    double pricePerTicket;
    int seats[MAX_SEATS][2]; // Store row and column
};

// Structure for concession item
struct ConcessionItem {
    string name;
    int quantity;
    double price;
};

// Global arrays
extern Ticket allTickets[MAX_TICKETS];
extern ConcessionItem allConcessions[MAX_CONCESSIONS];
extern int numTickets;
extern int numConcessions;

// Global variables
extern double runningTotal;
extern double salesTax, totalWithTax;
extern double ticketPrice;
extern int qty;
extern char age;

// Random number gen
extern random_device rd;
extern mt19937 gen;
extern uniform_int_distribution<> dist;


// Array for movie tickets
extern int movtix[MAX_MOVIES];

// Array of movies
extern string mov[MAX_MOVIES] = { "Avatar", "The Smurfs", "Sahara", "Titanic", "The Matrix" };

// Array of seats
extern bool movs[MAX_MOVIES][ROWS][COLUMNS];

// Display Selected Items and Running Total
void displaySelectedItems(double rt) {
    salesTax = rt * SALES_TAX;
    totalWithTax = rt + salesTax;
    cout << fixed << setprecision(2);
    cout << "\nRunning Total: $" << rt << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total with Tax: $" << totalWithTax << endl;
}

// Get Sub-menu Selection
int getSubMenuSelection() {
    int selection;
    cout << "\nEnter selection: ";
    cin >> selection;

    // Input checker
    while (cin.fail() || selection < 0) { // Check for non-number inputs
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cin >> selection;
    }
    return selection;
}
// Get Quantity
int getQuantity() {
    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;

    // Input checker
    while (cin.fail() || quantity <= 0) { // Check for non-number inputs
        cout << "Invalid input. Please enter a number: ";
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cin >> quantity;
    }
    return quantity;
}

#endif // If not previously defined