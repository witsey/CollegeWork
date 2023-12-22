#include <iostream>
using namespace std;

// Customers Data

int const MAXIMUM_CUSTOMERS_NUMBER = 100;

int customers_IDs[ MAXIMUM_CUSTOMERS_NUMBER ]                      { 1 , 2 , 3 };
long long int customers_phone_numbers[ MAXIMUM_CUSTOMERS_NUMBER ]  { 20123456789 , 20123456788 , 20123456787 };
int customers_wallets[ MAXIMUM_CUSTOMERS_NUMBER  ]                 { 1000 , 2000 , 500 };
int customers_points[ MAXIMUM_CUSTOMERS_NUMBER  ]                  { 0 , 0 , 0 };

int customers_current_number = 3;

// Items Data

int const MAXIMUM_ITEMS_NUMBER = 100;

int items_IDs[ MAXIMUM_ITEMS_NUMBER ]       { 1 , 2 , 3 , 4 , 5 };
string items_names[ MAXIMUM_ITEMS_NUMBER ]  { "cappuccino" , "espresso" , "Turkish coffee" , "lemon" , "orange" };
int items_prices[ MAXIMUM_ITEMS_NUMBER ]    { 30 , 50 , 50 , 25 , 25 };

int items_current_number = 5;

// Functions Prototypes: 

void add_customer();
void add_item();
void print_customers();
void print_items( bool ask );
void make_order();
void print_highest_customer();
void sort_customers();
void back_to_main();

// Program


int main() {

    int choice;
    
    cout << "Menu: " << endl
         << "\n 1.Add a customer \t2.Add a menu item \n 3.Print all customers \t4.Print all items \n 5.Make an order \t6.Redeem an item "
         << endl
         << "\n 7.Show the customer with the highest points \n\n 8.Sort customers based on earned points \n\n 9.Exit Program \n\nPlease choose an option from the menu by entering its number: ";
    
    cin >> choice;

    switch (choice) {

    case 1: {

        add_customer();

    } break;

    case 2: {

        add_item();

    } break;

    case 3: {

        print_customers();

    } break;

    case 4: {

        print_items(1);

    } break;

    case 5: {

        make_order();

    } break;

    case 6: {

        cout << "";

    } break;

    case 7: {

        print_highest_customer();

    } break;

    case 8: {

        sort_customers();

    } break;

    case 9: {
        
        cout << "\n\nThank you! We hope to see you soon.";

    } break;

    default: {

    }
    }
}


void add_customer() {

    bool again;

    do {

        cout << "\nTo add a customer please enter the following:";

        cout << "\nCustomer's ID: ";
        cin >> customers_IDs[ customers_current_number ];

        cout << "\nCustomer's Phone Number: ";
        cin >> customers_phone_numbers[ customers_current_number ];

        cout << "\nCustomer's Wallet: ";
        cin >> customers_wallets[ customers_current_number ];

        cout << "\nCustomer's Points: ";
        cin >> customers_points[ customers_current_number ];

        customers_current_number++;

        cout << "\n\nWould you like to add another customer ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while ( again && customers_current_number < MAXIMUM_CUSTOMERS_NUMBER );

    back_to_main();

}


void add_item() {

    bool again;

    cout << "To add an item please enter the following" << endl;

    do {

    
        cout << "Item's name: ";
        cin >> items_names [ items_current_number ];

        cout << "\nItem's ID: ";
        cin >> items_IDs [ items_current_number ];

        cout << "\nItem's price: ";
        cin >> items_prices [ items_current_number ];

        cout << "\nWould you like to add another item? ( 1 for yes, 0 for no ): ";
        cin >> again;

        items_current_number++;

    } while ( again && items_current_number < MAXIMUM_ITEMS_NUMBER );

    back_to_main();
}


void print_customers() {
    
    for (int i = 0; i < customers_current_number; i++) {

        cout << "\nCustomer " << i + 1 << ": " << endl;
        cout << "ID: " << customers_IDs[i] << endl;
        cout << "Phone Number: " << customers_phone_numbers[i] << endl;
        cout << "Wallet: " << customers_wallets[i] << endl;
        cout << "Points: " << customers_points[i] << endl;
    }

    back_to_main();
}


void print_items( bool ask ) {
    
    for (int i = 0; i < items_current_number; i++) {

        cout << "\n" << items_names[i] << ": " << endl;
        cout << "ID: " << items_IDs[i] << endl;
        cout << "Price: " << items_prices[i] << endl;
    }

    if (ask) {

        back_to_main();
    }
}


void make_order() {

    int buyer_id;
    int order;
    int points;
    int orders_counter = 0;
    int balance;
    bool reorder;
    bool proceed;
    bool new_order;

    cout << "\n\nTo make an order, Please input your ID first: ";

    cin >> buyer_id;

    cout << "Items Menu: " << endl;
    print_items(0);

    do {

        int total = 0;

        do {

            cout << "\nPlease choose what you would like to order by entering its ID: ";
            cin >> order;

            orders_counter++;

            for (int i = 0; i < items_current_number; i++) {

                if (order == items_IDs[i]) {

                    total += items_prices[i];
                }
            }

            cout << "\n\nDo you want to order another item? ( 1 for yes, 0 for no): ";
            cin >> reorder;

            if (reorder) {

                cout << "Type the item ID to order it: ";
            }

        } while (reorder);

        cout << "\n\nYour total is: " << total << "$ " << endl;

        cout << "Do you want to proceed or cancel the order? ( 1 for yes, 0 to cancel the order ): ";
        cin >> proceed;

        if (proceed) {

            for (int k = 0; k < customers_current_number; k++) {

                if (buyer_id == customers_IDs[k]) {

                    if (customers_wallets[k] >= total) {

                        customers_wallets[k] -= total;
                        balance = customers_wallets[k];

                        points = (total / 4);
                        customers_points[k] += points;

                        cout << "\n-$" << total << " from your wallet, your current balance is: " << balance << "$" << endl;
                        cout << "\nAnd you've gained " << points << " point(s)!" << endl;

                        break;
                    }

                    else {

                        cout << "\nSorry, You Don't have enough money to order this item." << endl;
                    }
                }
            }
        }

        cout << "Would you like to make another order? ( 1 for yes, 0 for no): ";
        cin >> new_order;

    } while ( new_order );

    back_to_main();
}


void print_highest_customer() {

    int highest_customer_id;
    int highest_points = 0;
    int equal_customers_counter = 0;
    bool equal = 0;
    
    // int equal_customers_IDs [ MAXIMUM_CUSTOMERS_NUMBER ] {};
  //  int k = 0;

    // Comparing points 

    for (int i = 0; i < customers_current_number; i++) {

        if ( customers_points[i] > highest_points ) {

            highest_customer_id = customers_IDs[i];
            highest_points = customers_points[i];

        }
    }

    // In case more than are eqaul in the highest points

    for ( int j = 0; j < customers_current_number; j++ ) {

        if ( customers_points[ j ] != highest_points ) {

            continue;
        }

        else {
            
            equal_customers_counter++;    
        }
    }

    if ( equal_customers_counter >= 2 ) { equal = true; }

    if (!equal) {

        cout << "\n\nThe customer with the highest points is Customer " << highest_customer_id << endl;
        cout << "With " << highest_points << " point(s)" << endl;
    }
    else {

        cout << "\n\nMore than one customer are equal in points which are: " << highest_points << " Point(s) ";
        
    }

    back_to_main();
  
}


void sort_customers() {

    int sorted_customers_points[customers_current_number];
    int sorted_customers_IDs[customers_current_number];

    // Initialising new arrays for the sorted descending  list

    for (int i = 0; i < customers_current_number; i++) {

        sorted_customers_points[i] = customers_points[i];
        sorted_customers_IDs[i] = customers_IDs[i];
    }

    // Sorting the arrays

    for (int i = 0; i < customers_current_number; i++) {

        for (int j = 0; j < customers_current_number - i; j++) {

            if ( sorted_customers_points[ j ]  < sorted_customers_points[ j + 1 ] ) {

                swap( sorted_customers_points[j], sorted_customers_points[ j + 1 ] );
                swap( sorted_customers_IDs[j], sorted_customers_IDs[ j + 1 ] );
            }
        }
    }

    // Printing the arrays

    for (int k = 0; k < customers_current_number; k++) {

        cout << "\n\n#" << k + 1 << " || Customer " << sorted_customers_IDs[k] << " Has " << sorted_customers_points[k] << " Point(s)" << endl;
    }

    back_to_main();
}


void back_to_main() {

    bool back;

    cout << "\n\nWould you like to get back to the main menu? ( 1 for yes, 0 for no ): ";
    cin >> back;

    if (back) {

        cout << "\n\n<< Back to Menu >>" << endl
             << endl;
        main();
    }
}
