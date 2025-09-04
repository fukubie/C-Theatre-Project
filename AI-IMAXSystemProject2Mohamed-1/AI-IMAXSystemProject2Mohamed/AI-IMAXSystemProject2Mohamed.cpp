#include "Ticketing.h" // Include the ticketing header
#include "Concessions.h" // Include the concessions header
#include "Common.h" // Include the declarations header

// Remove the need to type std:: before certain statements
using namespace std;

// Variables
double runningTotal = 0.0;
int numConcessions = 0;
Ticket allTickets[MAX_TICKETS];
ConcessionItem allConcessions[MAX_CONCESSIONS];
double salesTax;
double totalWithTax;
double ticketPrice;
int qty;

// Define movs
bool movs[MAX_MOVIES][ROWS][COLUMNS] = { false };

// Define movtix
int movtix[MAX_MOVIES] = { 0 };

// Define random_device and generator
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0, MAX_SEATS - 1);

// Variables
int numTickets = 0;
int getSubMenuSelection();
int getQuantity();


int main() {
    bool running = true;
    bool more = true;
    runningTotal = 0.0;
    ticketMenu(more);

    while (running) {
        // Call the concessions menu function
        concMenu();

        // Get sub-menu selection
        int subMenuSelection = getSubMenuSelection();

        if (subMenuSelection == 0) {
            running = false;
            cout << "Thank you for visiting AAAI-MAXXX Theatre. Enjoy your movie!" << endl;
            displaySelectedItems(runningTotal);
        }
        else if (subMenuSelection == 1) {
            Combos();
        }
        else if (subMenuSelection == 2) {
            Beverages();
        }
        else if (subMenuSelection == 3) {
            Popcorn();
        }

        // Display Running Total
        displaySelectedItems(runningTotal);
    }

    // Display the final receipt and print it
    system("cls");
    displayFinalReceipt();
    printFinalReceipt();

    return 0;
}
