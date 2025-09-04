#ifndef CONCESSIONS_H // If not Defined
#define CONCESSIONS_H // Define

#include "Common.h" // Include the declarations header

// Concessions Menu
void concMenu() {
    // Clear screen
    system("cls");
    // Instructor Ilkenhons' custom customer greeting
    cout << "Welcome to AAAI-MAXXX Theatre System concessions.\n"
        << endl;

    cout << "   |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "   | 1 - Combos ................ |" << endl;
    cout << "   | 2 - Beverages ............. |" << endl;
    cout << "   | 3 - Popcorn ............... |" << endl;
    cout << "   | 0 - End Selection ......... |" << endl;
    cout << "   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;

    // Prompt customer for selection
    cout << "\nWhat can I get for you? ";
}

// Combos Sub-menu
void Combos() {
    // Clear screen
    system("cls");
    // Combos display menu
    cout << "   |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;
    cout << "   | 1 - Lg.Popcorn + Lg.Drink + Candy ...... $22.97 |" << endl;
    cout << "   | 2 - Sliders + Curly Fries + Lg.Drink ... $23.47 |" << endl;
    cout << "   | 3 - 2 Hot Dogs + Lg.Drink .............. $21.47 |" << endl;
    cout << "   | 4 - Movie Nachos + Lg.Drink + Candy .... $20.97 |" << endl;
    cout << "   | 5 - Lg. Popcorn + 2 Lg.Drinks .......... $24.97 |" << endl;
    cout << "   | 6 - Kids Pack .......................... $8.49  |" << endl;
    cout << "   | 7 - Snack Pack Combo ................... $35.95 |" << endl;
    cout << "   | 0 - End Selection .......................total  |" << endl;
    cout << "   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;

    // Prompt customer for selection
    cout << "\nPlease select a Combo: ";

    int comboSelection = getSubMenuSelection();
    if (comboSelection == 0)
        return; // End Combo selection

    double comboPrices[] = { 22.97, 23.47, 21.47, 20.97, 24.97, 8.49, 35.95 };
    if (comboSelection >= 1 && comboSelection <= 7) {
        int comboQuantity = getQuantity();
        runningTotal += comboPrices[comboSelection - 1] * comboQuantity;
        cout << "Added Combo #" << comboSelection << " x" << comboQuantity << " to the order." << endl;

        // Store the combo purchase
        allConcessions[numConcessions].name = "Combo #" + to_string(comboSelection);
        allConcessions[numConcessions].quantity = comboQuantity;
        allConcessions[numConcessions].price = comboPrices[comboSelection - 1];
        numConcessions++;
        system("cls");
    }
}

// Beverages Sub-menu
void Beverages() {
    // Clear screen
    system("cls");
    // Beverages display menu
    cout << "   |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- |" << endl;
    cout << "   | 1 - Coca-Cola .......... $6.99 |" << endl;
    cout << "   | 2 - ICEE ............... $7.49 |" << endl;
    cout << "   | 3 - Bottled water....... $5.49 |" << endl;
    cout << "   | 4 - Coffee.............. $4.49 |" << endl;
    cout << "   | 5 - Raw Milk .......... $15.99 |" << endl;
    cout << "   | 0 - End Selection .......total |" << endl;
    cout << "   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* |" << endl;

    // Prompt customer for selection
    cout << "\nPlease select a Beverage: ";
    int beverageSelection = getSubMenuSelection();
    if (beverageSelection == 0)
        return; // End Beverage selection

    double beveragePrices[] = { 6.99, 7.49, 5.49, 4.49, 15.99 };
    if (beverageSelection >= 1 && beverageSelection <= 5) {
        int beverageQuantity = getQuantity();
        runningTotal += beveragePrices[beverageSelection - 1] * beverageQuantity;
        cout << "Added Beverage #" << beverageSelection << " x" << beverageQuantity << " to the order." << endl;

        // Store the beverage purchase
        allConcessions[numConcessions].name = "Beverage #" + to_string(beverageSelection);
        allConcessions[numConcessions].quantity = beverageQuantity;
        allConcessions[numConcessions].price = beveragePrices[beverageSelection - 1];
        numConcessions++;
    }
}

// Popcorn Sub-menu
void Popcorn() {
    // Clear screen
    system("cls");
    // Popcorn display menu
    cout << "   |-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
    cout << "   | 1 - Lg. Popcorn ..........$11.49 |" << endl;
    cout << "   | 2 - Mid. Popcorn .........$9.99  |" << endl;
    cout << "   | 3 - Sm. Popcorn ..........$8.99  |" << endl;
    cout << "   | 4 - Butter ...............$1.99  |" << endl;
    cout << "   | 0 - End Selection ........ total |" << endl;
    cout << "   |*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-|" << endl;

    // Prompt customer for selection
    cout << "\nPlease select a Popcorn option: ";

    int popcornSelection = getSubMenuSelection();
    if (popcornSelection == 0)
        return; // End Popcorn selection

    double popcornPrices[] = { 11.49, 9.99, 8.99, 1.99 };
    if (popcornSelection >= 1 && popcornSelection <= 4) {
        int popcornQuantity = getQuantity();
        runningTotal += popcornPrices[popcornSelection - 1] * popcornQuantity;
        cout << "Added Popcorn #" << popcornSelection << " x" << popcornQuantity << " to the order." << endl;

        // Store the popcorn purchase
        allConcessions[numConcessions].name = "Popcorn #" + to_string(popcornSelection);
        allConcessions[numConcessions].quantity = popcornQuantity;
        allConcessions[numConcessions].price = popcornPrices[popcornSelection - 1];
        numConcessions++;
    }
}

#endif // If not previously defined