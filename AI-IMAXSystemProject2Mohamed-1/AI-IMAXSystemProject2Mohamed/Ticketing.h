#ifndef TICKETING_H // If not Defined
#define TICKETING_H // Define

#include "Common.h" // Include the declarations header

// Remove the need to type std:: before certain statements
using namespace std;

char age;

// Function to display tickets
void displayTickets(int sel, char age, int qty, double price) {
    cout << "\nTickets for " << mov[sel] << ":" << endl;
    cout << "Age Category: " << (age == 'a' ? "Adult" : (age == 'c' ? "Child" : "Senior")) << endl;
    cout << "Quantity: " << qty << endl;
    cout << "Price per Ticket: $" << fixed << setprecision(2) << price << endl;
    cout << "Total Cost: $" << fixed << setprecision(2) << price * qty << endl;
}

// Function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to display seating chart
void displaySeatingChart(int sel) {
    system("cls");
    cout << "\nSeating Chart for " << mov[sel] << ":\n\n";
    cout << "     "; // Spacing

    // Print column headers (1, 2, 3, etc)
    for (int col = 0; col < COLUMNS; col++) {
        cout << setw(3) << col + 1 << "  "; // Spacing between numbers
    }
    cout << endl;

    // Top border of the table
    cout << "   " << "*"; // Top-left corner
    for (int col = 0; col < COLUMNS - 1; col++) {
        cout << setw(4) << "-" << "*"; // dash and * 
    }
    cout << setw(4) << "-" << "*" << endl; // Last dash and top-right corner

    // Print rows with seat labels (A, B, C)
    for (int row = 0; row < ROWS; row++) {
        cout << " " << char(row + 'A') << " " << "|"; // Row label and |
        for (int col = 0; col < COLUMNS; col++) {
            // Print 'X' for reserved and 'O' for open seats
            cout << setw(3) << (movs[sel][row][col] ? "X" : "O") << " " << "|";
        }
        cout << endl;

        // Separator line between rows
        if (row < ROWS - 1) {
            cout << "   " << "*"; // Left-side junction
            for (int col = 0; col < COLUMNS - 1; col++) {
                cout << setw(4) << "-" << "*"; // - and *
            }
            cout << setw(4) << "-" << "*" << endl; // Last - and right-side *
        }
    }

    // Bottom border of the table
    cout << "   " << "*"; // Bottom-left corner
    for (int col = 0; col < COLUMNS - 1; col++) {
        cout << setw(4) << "-" << "*"; // - and *
    }
    cout << setw(4) << "-" << "*" << endl; // Last - and bottom-right corner

    cout << endl;
}

// Function to sell ticket
void sellTicket(int sel, int qty, int reservedSeats[][2]) {
    int sold = 0;

    // Loop for seat selection
    while (sold < qty) {
        char rowChar;
        int row, col;

        // Display the seating chart
        system("cls");
        displaySeatingChart(sel);

        // Ask the user to select a seat
        cout << "Select a seat (e.g., A1, B3): ";
        cin >> rowChar >> col;

        // Convert row character to row index
        row = rowChar - 'A';

        // Seat selection checker
        if (row >= 0 && row < ROWS && col >= 1 && col <= COLUMNS) {
            if (!movs[sel][row][col - 1]) { // If the seat is not reserved
                movs[sel][row][col - 1] = true; // Reserve the seat
                reservedSeats[sold][0] = row; // Store row of reserved seat
                reservedSeats[sold][1] = col - 1; // Store column of reserved seat
                sold++; // Add to Tickets sold
                cout << "Seat " << rowChar << col << " reserved successfully.\n";
            }
            else {
                cout << "Seat " << rowChar << col << " is already reserved. Please choose another seat.\n";
            }
        }
        else {
            cout << "Invalid seat selection. Please select a seat within the range (e.g., A1, B3).\n";
        }
    }

    // Update the number of tickets available
    movtix[sel] -= qty;
}

// Ticketing Menu
void ticketMenu(bool& more) {
    // Open seats
    for (int i = 0; i < MAX_MOVIES; i++) {
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLUMNS; k++) {
                movs[i][j][k] = false;
            }
        }
    }

    // Make movie tickets have random values
    for (int i = 0; i < MAX_MOVIES; i++) {
        int reservedSeats = dist(gen) % (ROWS * COLUMNS); // Random number generator
        int count = 0;

        // First randomly reserve seats
        while (count < reservedSeats) {
            int row = dist(gen) % ROWS;
            int col = dist(gen) % COLUMNS;

            if (!movs[i][row][col]) {
                movs[i][row][col] = true;
                count++;
            }
        }

        // Count remaining seats and set as available tickets
        int availableSeats = 0;
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLUMNS; col++) {
                if (!movs[i][row][col]) {
                    availableSeats++;
                }
            }
        }
        movtix[i] = availableSeats;
    }

    int sel;
    while (more) {
        // Clear screen
        system("cls");

        // Ticketing menu
        cout << "Welcome to AAAI-MAXXX Theatre System ticketing.\n"
            << endl;

        cout << "   |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*|" << endl;
        cout << "   | 1 -  |" << setw(WIDTH) << mov[0] << "...Sfi/Act..." << movtix[0] << ".........PG |" << endl;
        cout << "   | 2 -  |" << setw(WIDTH) << mov[1] << "...Fam/Com..." << movtix[1] << ".........PG |" << endl;
        cout << "   | 3 -  |" << setw(WIDTH) << mov[2] << "...Adv/Act..." << movtix[2] << ".........PG |" << endl;
        cout << "   | 4 -  |" << setw(WIDTH) << mov[3] << "...Rom/Adv..." << movtix[3] << ".........PG |" << endl;
        cout << "   | 5 -  |" << setw(WIDTH) << mov[4] << "...Act/Sfi..." << movtix[4] << "..........R |" << endl;
        cout << "   |                                                           |" << endl;
        cout << "   |        (A)dult - $20 | (C)hild - $10 | (S)enior - $5      |" << endl;
        cout << "   |                                                           |" << endl;
        cout << "   | 0 - End Selection ......................................  |" << endl;
        cout << "   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*--*-*|" << endl;

        // Ask customer which movie to watch
        cout << "Which movie would you like to see? ";
        cout << "\nEnter selection: ";
        cin >> sel;

        // Adjust index
        sel -= 1;

        // Check selection and quantity
        if (sel > -1 && sel < MAX_MOVIES) {
            // Display the seating chart for the selected movie
            displaySeatingChart(sel);

            // Ask user for tickets
            cout << endl
                << "How many tickets do you want for " << mov[sel] << "? \n";
            cout << "\nEnter quantity: ";
            cin >> qty;

            if (qty <= movtix[sel]) {
                // Check for age
                cout << endl
                    << "Enter (A)dult, (C)hild, or (S)enior: ";
                cin >> age;
                age = tolower(age);
                clearInputBuffer();

                // Validate age input
                if (age != 'a' && age != 'c' && age != 's') {
                    cout << "Invalid age category. Please enter A, C, or S.\n";
                    continue;
                }

                // Calculate ticket price
                if (age == 'a')
                    ticketPrice = 20.0;
                else if (age == 'c')
                    ticketPrice = 10.0;
                else if (age == 's')
                    ticketPrice = 5.0;

                // Display ticket details
                displayTickets(sel, age, qty, ticketPrice);
                runningTotal += ticketPrice * qty;

                // Reserve seats
                int reservedSeats[MAX_SEATS][2]; // Fixed-size array for reserved seats
                sellTicket(sel, qty, reservedSeats);

                // Create a Ticket object and store the purchase
                allTickets[numTickets].movieName = mov[sel];
                allTickets[numTickets].ageCategory = age;
                allTickets[numTickets].quantity = qty;
                allTickets[numTickets].pricePerTicket = ticketPrice;
                for (int i = 0; i < qty; i++) {
                    allTickets[numTickets].seats[i][0] = reservedSeats[i][0];
                    allTickets[numTickets].seats[i][1] = reservedSeats[i][1];
                }
                numTickets++;

                // Display updated seating chart
                displaySeatingChart(sel);

                // Display the running total
                displaySelectedItems(runningTotal);
            }
            else {
                cout << "Not enough tickets available for " << mov[sel] << ". Available tickets: " << movtix[sel] << endl;
            }
        }

        // Ask user if they want to select more tickets
        cout << "Do you want to select more tickets? (y/n): ";
        char choice;
        cin >> choice;
        more = (choice == 'y' || choice == 'Y');
    }
}

// Function to display final receipt
void displayFinalReceipt() {
    cout << "\n======= FINAL RECEIPT =======" << endl;
    cout << fixed << setprecision(2);

    // Display Tickets
    if (numTickets > 0) {
        cout << "\n--- TICKETS ---\n";
        for (int i = 0; i < numTickets; i++) {
            cout << "Movie: " << allTickets[i].movieName << endl;
            cout << "Age Category: " << (allTickets[i].ageCategory == 'a' ? "Adult" : (allTickets[i].ageCategory == 'c' ? "Child" : "Senior")) << endl;
            cout << "Quantity: " << allTickets[i].quantity << endl;
            cout << "Price per Ticket: $" << allTickets[i].pricePerTicket << endl;
            cout << "Seats: ";
            for (int j = 0; j < allTickets[i].quantity; j++) {
                cout << char(allTickets[i].seats[j][0] + 'A') << allTickets[i].seats[j][1] + 1 << " ";
            }
            cout << "\nSubtotal: $" << allTickets[i].quantity * allTickets[i].pricePerTicket << endl;
        }
    }

    // Display Concessions
    if (numConcessions > 0) {
        cout << "\n--- CONCESSIONS ---\n";
        for (int i = 0; i < numConcessions; i++) {
            cout << allConcessions[i].name << " x" << allConcessions[i].quantity << " @ $" << allConcessions[i].price << " each\n";
            cout << "Subtotal: $" << allConcessions[i].quantity * allConcessions[i].price << endl;
        }
    }

    // Display Total
    salesTax = runningTotal * SALES_TAX;
    totalWithTax = runningTotal + salesTax;
    cout << "\n-----------------------------" << endl;
    cout << "Running Total: $" << runningTotal << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total with Tax: $" << totalWithTax << endl;
    cout << "=============================" << endl;
}

// Function to print tickets
void printFinalReceipt() {
    ofstream ticketFile("final_tickets.txt");
    if (ticketFile.is_open()) {
        ticketFile << "======= YOUR TICKETS =======" << endl;
        for (int i = 0; i < numTickets; i++) {
            ticketFile << "\n-----------------------------" << endl;
            ticketFile << "Movie: " << allTickets[i].movieName << endl;
            ticketFile << "Age Category: " << (allTickets[i].ageCategory == 'a' ? "Adult" : (allTickets[i].ageCategory == 'c' ? "Child" : "Senior")) << endl;
            ticketFile << "Quantity: " << allTickets[i].quantity << endl;
            ticketFile << "Price per Ticket: $" << fixed << setprecision(2) << allTickets[i].pricePerTicket << endl;
            ticketFile << "Total Cost: $" << fixed << setprecision(2) << allTickets[i].pricePerTicket * allTickets[i].quantity << endl;
            ticketFile << "Seats: ";
            for (int j = 0; j < allTickets[i].quantity; j++) {
                ticketFile << char(allTickets[i].seats[j][0] + 'A') << allTickets[i].seats[j][1] + 1 << " ";
            }
            ticketFile << endl;
            ticketFile << "-----------------------------" << endl;
        }
        ticketFile << "=============================" << endl;
        ticketFile.close();
        cout << "\nYour tickets have been printed to final_tickets.txt" << endl;
    }
    else {
        cout << "Error: Unable to print tickets." << endl;
    }
}

// Function to set movie tickets
void setMovieTickets() {
    for (int i = 0; i < MAX_MOVIES; i++) {
        int availableSeats = 0;
        // Count available open seats
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLUMNS; col++) {
                if (!movs[i][row][col]) {
                    availableSeats++;
                }
            }
        }
        // Set available tickets
        movtix[i] = availableSeats;
    }
}



#endif // If not previously defined