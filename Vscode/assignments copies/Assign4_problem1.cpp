// Assignment 4 Problem 1

#include <iostream>
using namespace std;
// Customers Data


struct Customer 
{

    int id;
    long long int phone_number;
    float wallet;
    float points;

};

int const MAXIMUM_CUSTOMERS_NUMBER = 100;
int customers_current_number ;

Customer customer_one =   { 1 , 20123456789 , 1000 , 0 };
Customer customer_two =   { 2 , 20123456788 , 2000 , 0 };
Customer customer_three = { 3 , 20123456787 , 500 ,  0 };

int* customers_IDs;
long long int* customers_phone_numbers;
float* customers_wallets;
float* customers_points;


// Items Data

struct Item
{

    int id;
    string name;
    float price;

};

int const MAXIMUM_ITEMS_NUMBER = 100;
int items_current_number;

Item cappuccino =     { 1 , "Cappuccino" , 30 };
Item espresso =       { 2 , "Espresso" , 50 };
Item turkish_coffee = { 3 , "Turkish coffee" , 50 };
Item lemon =          { 4 , "Lemon" , 25 };
Item orange =         { 5 , "Orange" , 25 };

int* items_IDs;
string* items_names;
float* items_prices;


// Functions Prototypes: 

void initialize_data();
void add_customer();
void add_item();
void print_customers();
void print_items( bool ask );
void make_order();
void redeem_item();
void show_customer_data();
void print_highest_customer();
void sort_customers();
void back_to_main();
void clean_memory();

// Program

bool first_time = true;

void initialize_data() {

    if ( first_time ) {

        // Initialize customers data

        customers_current_number = 3;

        customers_IDs = new int [ MAXIMUM_CUSTOMERS_NUMBER ]                     { customer_one.id , customer_two.id , customer_three.id };
        customers_phone_numbers = new long long int [ MAXIMUM_CUSTOMERS_NUMBER ] { customer_one.phone_number , customer_two.phone_number , customer_three.phone_number };
        customers_wallets = new float [ MAXIMUM_CUSTOMERS_NUMBER ]               { customer_one.wallet , customer_two.wallet , customer_three.wallet };
        customers_points = new float[ MAXIMUM_CUSTOMERS_NUMBER ]                 { customer_one.points , customer_two.points , customer_three.points };

        // Initialize items data

        items_current_number = 5;

        items_IDs = new int [ MAXIMUM_CUSTOMERS_NUMBER ]      { cappuccino.id , espresso.id , turkish_coffee.id , lemon.id , orange.id };
        items_names = new string [ MAXIMUM_ITEMS_NUMBER ]     { cappuccino.name , espresso.name , turkish_coffee.name , lemon.name , orange.name };
        items_prices = new float [ MAXIMUM_ITEMS_NUMBER ]     { cappuccino.price , espresso.price , turkish_coffee.price , lemon.price , orange.price };


    }

    first_time = false;

}


int main() {

    initialize_data();
    
    int choice;
    
    cout << "Menu: " << endl
         << "\n 1.Add a customer \t2.Add a menu item \n 3.Print all customers \t4.Print all items \n 5.Make an order \t6.Redeem an item "
         << endl
         << "\n 7.Show specific customer data \n\n 8.Show the customer with the highest points \n\n 9.Sort customers based on earned points \n\n 10.Exit Program \n\nPlease choose an option from the menu by entering its number: ";
    
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

        redeem_item();

    } break;

    case 7: {

        show_customer_data();

    } break;

    case 8: {

        print_highest_customer();

    } break;

    case 9: {
        
        sort_customers();

    } break;

    case 10: {

        cout << "\n\nThank you, We hope to see you soon!";
        clean_memory();
    }
    break;

    default: {

        cout << "Invalid Choice";
        clean_memory();

    }
    }

}


void add_customer() {

    bool again;

    do {

        int* new_customers_ids = new int [ customers_current_number + 1 ];
        long long int* new_customers_phones = new long long int [ customers_current_number + 1 ];
        float* new_customers_wallets = new float [ customers_current_number + 1 ];
        float* new_customers_points = new float [ customers_current_number + 1 ];

        for ( int i; i < customers_current_number; i++ ) {

            new_customers_ids[i] = customers_IDs[i];
            new_customers_phones[i] = customers_phone_numbers[i];
            new_customers_wallets[i] = customers_wallets[i];
            new_customers_points[i] = customers_points[i];

        } 


        cout << "\nTo add a customer please enter the following:";

        cout << "\nCustomer's ID: ";
        cin >> new_customers_ids[ customers_current_number ];

        cout << "\nCustomer's Phone Number: ";
        cin >> new_customers_phones[ customers_current_number ];

        cout << "\nCustomer's Wallet: ";
        cin >> new_customers_wallets[ customers_current_number ];

        cout << "\nCustomer's Points: ";
        cin >> new_customers_points[ customers_current_number ];

        delete[] customers_IDs, customers_phone_numbers, customers_wallets, customers_points;

        customers_IDs = new_customers_ids;
        customers_phone_numbers = new_customers_phones;
        customers_wallets = new_customers_wallets;
        customers_points = new_customers_points;

        customers_current_number++;

        cout << "\n\nWould you like to add another customer ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while ( again && customers_current_number < MAXIMUM_CUSTOMERS_NUMBER );

    back_to_main();

}


void add_item() {

    bool again;

    do {

        string* new_items_names = new string [ items_current_number + 1 ];
        int* new_items_ids = new int [ items_current_number + 1 ];
        float* new_items_prices = new float [ items_current_number + 1 ];

        for ( int i = 0; i < items_current_number; i++ ) {

            new_items_names[i] = items_names[i];
            new_items_ids[i] = items_IDs[i];
            new_items_prices[i] = items_prices[i];

        }

    
        cout << "To add an item please enter the following" << endl;


        cout << "Item's name: ";
        cin >> new_items_names[ items_current_number ];

        cout << "\nItem's ID: ";
        cin >> new_items_ids[ items_current_number ];

        cout << "\nItem's price: ";
        cin >> new_items_prices[ items_current_number ];

        cout << "\nWould you like to add another item? ( 1 for yes, 0 for no ): ";
        cin >> again;

        delete[] items_names, items_IDs, items_prices;
        
        items_names = new_items_names;
        items_IDs = new_items_ids;
        items_prices = new_items_prices;
        

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
        cout << "Price: " << items_prices[i] << "$" << endl;
    }

    if (ask) {

        back_to_main();
    }
}


void make_order() {

    int buyer_id;
    int order;
    float points;
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

        float total = 0;
        cout << "\nPlease choose what you would like to order by entering its ID: ";

        do {

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


void redeem_item() {

    int buyer_id;
    int order;
    float points_cost;
    int orders_counter = 0;
    int balance;
    bool reorder;
    bool proceed;
    bool new_order;

    cout << "\n\nTo redeem an item, Please input your ID first: ";
    cin >> buyer_id;

    cout << "Items Menu: " << endl;
    print_items(0);

    do {

        float needed_points = 0;

        do {

            cout << "\nPlease choose what you would like to order by entering its ID: ";
            cin >> order;

            orders_counter++;

            for ( int i = 0; i < items_current_number; i++ ) {

                if ( order == items_IDs[i] ) {
                    
                    points_cost = items_prices[i] * 4;
                    needed_points += points_cost;

                }
            }

            cout << "\n\nDo you want to redeem another item? (1 for yes, 0 for no): ";
            cin >> reorder;

            if ( reorder ) {

                cout << "Type the item ID to redeem it: ";
            }

        } while (reorder);

        cout << "\n\nYou need: " << needed_points << " points " << endl;

        cout << "Do you want to contiunue or cancel the order? (1 for yes, 0 to cancel): ";
        cin >> proceed;

        if (proceed) {

            for (int k = 0; k < customers_current_number; k++) {

                if ( buyer_id == customers_IDs[k] ) {

                    if ( customers_points[k] >= needed_points ) {

                        customers_points[k] -= needed_points;
                        balance = customers_points[k];

                        cout << "\n-" << needed_points << " points from your account, your current balance is: " << balance << " points" << endl;

                        break;
                    }

                    else {

                        cout << "\nSorry, You don't have enough points to redeem this item." << endl;
                    }
                }
            }
        }

        cout << "Would you like to redeem another item? (1 for yes, 0 for no): ";
        cin >> new_order;

    } while ( new_order );

    back_to_main();
}


void show_customer_data() {

    int customer_id;
    int counter = 0;
    bool again;
    bool reask = false;

    do {

        cout << "Input a customer ID to show his data: ";
        cin >> customer_id;

        for ( int i = 0; i < customers_current_number; i++) {

            counter++;

            if ( customer_id == customers_IDs[i] ) {
                
                cout << "\n\nThe customer with ID " << customer_id << " data: ";

                cout << "\n\nID: " << customers_IDs[i] << endl;
                cout << "Phone Number: " << customers_phone_numbers[i] << endl;
                cout << "Wallet: " << customers_wallets[i] << endl;
                cout << "Points: " << customers_points[i] << endl;

                break;
  
            }

            else if( counter >= customers_current_number ) {

                cout << "\n\nNo customer has the id " << customer_id << endl;
                reask = true;
                break;
            }

        }

        if ( reask ) {

            continue;
        }

        cout << "\n\nDo you want to check another customer data? ( 1 for yes, 0 for no): ";
        cin >> again;

    } while ( again );

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

    float sorted_customers_points[customers_current_number];
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


void clean_memory() {

    delete[] customers_IDs;
    delete[] customers_phone_numbers;
    delete[] customers_wallets;
    delete[] customers_points;
    delete[] items_IDs;
    delete[] items_names;
    delete[] items_prices;
}