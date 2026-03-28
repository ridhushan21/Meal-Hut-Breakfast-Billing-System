#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
// Structure to store each menu item
struct MenuItem {
    int itemNo;
    string name;
    double price;
};

// Function to load menu items6
void loadMenu(MenuItem menu[], int &itemCount) {
    menu[0] = {111, "Plain Egg", 1.45};
    menu[1] = {112, "Bacon and Egg", 2.45};
    menu[2] = {113, "Muffin", 0.99};
    menu[3] = {114, "French Toast", 1.99};
    menu[4] = {115, "Fruit Basket", 2.49};
    menu[5] = {116, "Cereal", 0.69};
    menu[6] = {117, "Coffee", 0.50};
    menu[7] = {118, "Tea", 0.75};
    itemCount = 8;
}

// Function to display the menu
void showMenu(const MenuItem menu[], int itemCount) {
    cout << "Menu:" << endl;
    cout << "Item No   Item Name         Price" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << menu[i].itemNo << "   " << menu[i].name << "   $" << menu[i].price << endl;
    }
}

// Function to calculate and print the bill
void printBill(const MenuItem menu[], int itemCount, int selectedItems[], int quantities[], int count) {
    double totalAmount = 0.0;

    cout << "******** Your Bill ********" << endl;
    for (int i = 0; i < count; i++) {
        int itemNo = selectedItems[i];
        int qty = quantities[i];
        for (int j = 0; j < itemCount; j++) {
            if (menu[j].itemNo == itemNo) {
                double itemCost = menu[j].price * qty;
                totalAmount += itemCost;
                cout << menu[j].itemNo << "   " << menu[j].name << "   $" 
                     << menu[j].price << " x " << qty << " = $" << itemCost << endl;
                break;
            }
        }
    }

    double tax = totalAmount * 0.05;
    double finalAmount = totalAmount + tax;

    cout << "----------------------------" << endl;
    cout << "Subtotal: $" << totalAmount << endl;
    cout << "Tax (5%): $" << tax << endl;
    cout << "Total:    $" << finalAmount << endl;
}

// Main function
int main() {
    MenuItem menu[8];
    int itemCount = 0;

    loadMenu(menu, itemCount);

    int selectedItems[10];
    int quantities[10];
    int orderCount = 0;

    cout << "******** Welcome to Meal Hut *********" << endl;
    cout << "Breakfast Billing System" << endl;

    while (true) {
        showMenu(menu, itemCount);

        cout << "Enter the item number you want to order (0 to finish): ";
        int itemNo;
        cin >> itemNo;

        if (itemNo == 0) {
            break;
        }

        bool isValidItem = false;
        for (int i = 0; i < itemCount; i++) {
            if (menu[i].itemNo == itemNo) {
                isValidItem = true;
                break;
            }
        }

        if (!isValidItem) {
            cout << "Invalid item number. Please try again." << endl;
            continue;
        }

        cout << "Enter quantity: ";
        int qty;
        cin >> qty;

        if (qty <= 0) {
            cout << "Quantity must be greater than 0. Please try again." << endl;
            continue;
        }

        selectedItems[orderCount] = itemNo;
        quantities[orderCount] = qty;
        orderCount++;
    }

    printBill(menu, itemCount, selectedItems, quantities, orderCount);

    return 0;
}
