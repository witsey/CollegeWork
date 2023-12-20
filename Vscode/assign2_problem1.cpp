#include <iostream>
using namespace std;

// Customers Data

int* customers_IDs;
long long int* customers_phone_numbers;
int* customers_wallets;
int* customers_points;
int customers_number;

// Items Data

int* items_IDs;
string* items_names;
int* items_prices;
int items_number;

// Functions Prototypes: 

void initialize_data();
void add_customer();
void add_item();
void print_customers();
void print_items( bool ask );
void make_order();
void print_highest_customer();
void sort_customers();
void back_to_main();
void clean_memory();

// Data first time initializing check

bool first_time = true;

// Program

void initialize_data() {

    if ( first_time ) {

        // Initialize Customer's data

        customers_number = 3;
        customers_IDs = new int[customers_number]                     { 1 , 2 , 3 };
        customers_phone_numbers = new long long int[customers_number] { 20123456789 , 20123456788 , 20123456787 };
        customers_wallets = new int[customers_number]                 { 1000 , 2000 , 500 };
        customers_points = new int[customers_number]                  { 15 , 15 , 15 };

        // Initialize Item's data

        items_number = 5;
        items_IDs = new int[items_number]      { 1 , 2 , 3 , 4 , 5 };
        items_names = new string[items_number] { "cappuccino" , "espresso" , "Turkish coffee" , "lemon" , "orange" };
        items_prices = new int[items_number]   { 50 , 50 , 50 , 25 , 25 }; 
    }

    first_time = false;
}

int main() {
    
    initialize_data();

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

        clean_memory();
        cout << "\n\nThank you! We hope to see you soon.";

    } break;

    default: {

        clean_memory();
    }
    }
}

void add_customer() {

    bool again;

    do {

        cout << "\nTo add a customer please enter the following:";

        cout << "\nCustomer's ID: ";
        cin >> customers_IDs[customers_number];

        cout << "\nCustomer's Phone Number: ";
        cin >> customers_phone_numbers[customers_number];

        cout << "\nCustomer's Wallet: ";
        cin >> customers_wallets[customers_number];

        cout << "\nCustomer's Points: ";
        cin >> customers_points[customers_number];

        customers_number++;

        cout << "\n\nWould you like to add another customer ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while (again);

    back_to_main();
}

void add_item() {

    bool again;

    cout << "To add an item please enter the following" << endl;

    do {

        items_number++; 

        string* new_items_names = new string[items_number];
        
        for (int i = 0; i < items_number - 1; i++) {
                
        new_items_names[i] = items_names[i];

        }
        
        delete[] items_names;
        items_names = new_items_names;
        
        cout << "Item's name: ";
        cin >> items_names[items_number - 1];

        cout << "\nItem's ID: ";
        cin >> items_IDs[items_number - 1];

        cout << "\nItem's price: ";
        cin >> items_prices[items_number - 1];

        cout << "\nWould you like to add another item? ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while (again);

    back_to_main();
}

void print_customers() {
    
    for (int i = 0; i < customers_number; i++) {

        cout << "\nCustomer " << i + 1 << ": " << endl;
        cout << "ID: " << customers_IDs[i] << endl;
        cout << "Phone Number: " << customers_phone_numbers[i] << endl;
        cout << "Wallet: " << customers_wallets[i] << endl;
        cout << "Points: " << customers_points[i] << endl;
    }

    back_to_main();
}

void print_items( bool ask ) {
    
    for (int i = 0; i < items_number; i++) {

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

            for (int i = 0; i < items_number; i++) {

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

            for (int k = 0; k < customers_number; k++) {

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

    } while (new_order);

    back_to_main();
}

void print_highest_customer() {

    int highest_customer_id;
    int highest_points = 0;
    bool equal = 0;

    // Comparing points 

    for (int i = 0; i < customers_number; i++) {

        if (customers_points[i] > highest_points) {

            highest_customer_id = customers_IDs[i];
            highest_points = customers_points[i];
        }
    }

    // In case they are equal

    for (int i = 0; i < customers_number; i++) {

        for (int j = 0; j < customers_number - i; i++) {

            if (customers_points[j] == customers_points[j + 1]) {

                equal = 1;
            }

            else {
                equal = 0;
            }
        }
    }

    if (!equal) {

        cout << "\n\nThe customer with the highest points is Customer " << highest_customer_id << endl;
        cout << "With " << highest_points << " point(s)" << endl;
    }
    else {

        highest_points = customers_points[0];
        cout << "\n\nAll customers are equal in points which is: " << highest_points << " Point(s)";
    }

    back_to_main();
}

void sort_customers() {

    int sorted_customers_points[customers_number];
    int sorted_customers_IDs[customers_number];

    // Initialising new arrays for the sorted descending  list

    for (int i = 0; i < customers_number; i++) {

        sorted_customers_points[i] = customers_points[i];
        sorted_customers_IDs[i] = customers_IDs[i];
    }

    // Sorting the arrays

    for (int i = 0; i < customers_number; i++) {

        for (int j = 0; j < customers_number - i; j++) {

            if (sorted_customers_points[j] < sorted_customers_points[j + 1]) {

                swap(sorted_customers_points[j], sorted_customers_points[j + 1]);
                swap(sorted_customers_IDs[j], sorted_customers_IDs[j + 1]);
            }
        }
    }

    // Printing the arrays

    for (int k = 0; k < customers_number; k++) {

        cout << "\n\n" << k + 1 << ".Customer " << sorted_customers_IDs[k] << " Has " << sorted_customers_points[k] << " Point(s)" << endl;
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

void clean_memory() {

    delete[] customers_IDs;
    delete[] customers_phone_numbers;
    delete[] customers_wallets;
    delete[] customers_points;
    delete[] items_IDs;
    delete[] items_names;
    delete[] items_prices;
}
