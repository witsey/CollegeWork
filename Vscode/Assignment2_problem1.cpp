// Assignment 2 Problem 1

#include <iostream>
using namespace std;
hello world
// Customers Data

int customers_IDs []                     { 1 , 2 , 3 };
long long int customers_phone_numbers [] { 20123456789 , 20123456788 , 20123456787 };
int customers_wallets []                 { 1000 , 2000 , 500 };
int customers_points []                  { 15 , 99 , 14};

int customers_number = 3;

// Items Data

int items_IDs []      { 1 , 2 , 3 , 4 , 5};
string items_names [] { "cappuccino" , "espresso" , "Turkish coffee" , "lemon" , "orange" };
int items_prices []   { 1000 , 50 , 50 , 25 , 25 };

int items_number = 5;

// Functions Prototypes: 

void add_customer();
void add_item();
void print_customers();
void print_items();
void make_order();
void print_highest_customer();
void sort_customers();
void back_to_main();

// Program

int main() {

    int choice;
    
    cout << "Menu: " << endl << "\n 1.Add a customer \t2.Add a menu item \n 3.Print all items \t4.Print all items \n 5.Make an order \t6.Redeem an item " << endl << "\n 7.Show the customer with the highest ponits \n\n 8.Sort customers based on earned points \n\nPlease choose an option from the menu by entering its number: ";
    cin >> choice;

    switch (choice) {

        case 1: {
            
            add_customer();
            
        }
        break;

        case 2: {
            
            add_item();
        }
        break;

        case 3: {

            print_customers();
        }
        break;

        case 4: {

            print_items();
        }
        break;

        case 5: {

            make_order();
        }
        break;

        case 6: {

            cout << "";
        }

        case 7: {

            print_highest_customer();
        }
        break;

        case 8: {

            sort_customers();
        }

        cout << "Hello world";
    }
}


void add_customer() {

    bool again;

    do {

        cout << "\nTo add a customer please enter the following:";

        cout << "\nCustomer's ID: ";
        cin >> customers_IDs[ customers_number ];
    
        cout << "\nCustomer's Phone Number: ";
        cin >> customers_phone_numbers [ customers_number ];
    
        cout << "\nCustomer's Points: ";
        cin >> customers_points [ customers_number];

        customers_number++;

        cout << "\n\nWould you like to add another customer ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while ( again );

    back_to_main();
}


void add_item() {

    bool again;
    
    do {
        
        cout << "\nItem's ID: ";
        cin >> items_IDs[ items_number ];
    
        items_number++;

        cout << "\n\nWould you like to add another item? ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while ( again );

    back_to_main();
    
}


void print_customers() {
    
    for ( int i = 0; i < customers_number; i++) {

        cout << "\nCustomer " << i + 1 << ": " << endl;
        cout << "ID: " << customers_IDs[i] << endl;
        cout << "Phone Number: " << customers_phone_numbers[i] << endl;
        cout << "Points: " <<customers_points[i] << endl;
        
    } 
    
    back_to_main();
}


void print_items() {

    for ( int i = 0; i < items_number; i++) {

        cout << "\n" << items_names[i] << ": " << endl; 
        cout << "ID: " << items_IDs[i] << endl;
        cout << "Price: " << items_prices [i] << endl;
        
    } 


}


void make_order() {

    int buyer_id;
    int order;
    int points;
    bool again;

    cout << "\n\nTo make an order, Please input your ID first: ";
    cin >> buyer_id;

    do {

        cout << "Items Menu: " << endl;
        print_items();

        cout << "\nPlease choose what you would like to order by entering its ID: ";
        cin >> order;

        for ( int i = 0; i < items_number; i++) {

            if ( order == items_IDs[i] ) {

            
                for ( int j = 0; j < customers_number; j++) {

                    if ( buyer_id == customers_IDs[j] ) {
                        
                        if ( customers_wallets[j] >= items_prices[i] ) {
                            
                            points = ( items_prices[i] / 4 );
                            customers_points[j] += points;

                            cout << "\nYou've bought " << items_names[i] << "!" << endl;
                            customers_wallets[j] = customers_wallets[j] - items_prices[i];
                            cout << "\n-$" << items_prices[i] << " from your wallet." << endl;

                            cout << "Your ballance is: " << customers_wallets[j] << "$" << endl;
                            cout << "And you've gained " << points << " points from this purchase!" << endl;
                            cout << "Your current points: " << customers_points[j] << " point(s)" << endl;
                    
                            break;
                        }
                        else {

                            cout << "\nSorry You dont have enough money to order this item" << endl;
                            break;
                        }
                        
                    }
                
                }
                break;
            }
        }

        cout << "\n\nWould you like to order another item? ( 1 for yes, 0 for no ): ";
        cin >> again;

    } while ( again == 1);

    back_to_main();
}


void print_highest_customer() {

    int highest_customer_id;
    int highest_points = 0;
    bool not_equal = 0;

    for ( int i = 0; i < customers_number; i++) {

        if ( customers_points[i] > highest_points ) {

            highest_customer_id = customers_IDs[i];
            highest_points = customers_points[i];
            not_equal = 1;
        }

        if ( customers_points[i] == highest_points ) {

            cout << "\n\nAll customers are equal in points which is " << highest_points << " point(s)" << endl;
            not_equal = 0;
            break;
        }

    }

    if ( not_equal ) {

        cout << "\n\nThe customer with the highest points is Customer " << highest_customer_id << endl;
        cout << "With " << highest_points << " point(s)" << endl;

    }

    back_to_main();
}


void sort_customers() {

    int sorted_customers_points [ customers_number ];
    int sorted_customers_IDs [ customers_number ];
    
    // Initialising new arrays for the sorted descending  list


    for ( int i = 0 ; i < customers_number ; i++) {

        sorted_customers_points[i] = customers_points[i];
        sorted_customers_IDs[i] = customers_IDs[i];
    }
    
    // Sorting the arrays


    for ( int i = 0 ; i < customers_number ; i++)  {
        
        for ( int j = 0 ; j < customers_number - i -1 ; j++) {
            
            if ( sorted_customers_points[j] < sorted_customers_points[j + 1] ) {
                
                swap( sorted_customers_points[j], sorted_customers_points[j + 1]);
                swap( sorted_customers_IDs[j], sorted_customers_IDs[j + 1]);
                
            }

        }


    }

    // Printing the arrays

    for ( int k = 0; k < customers_number; k++) {

        cout << "\n\n" << k + 1 << ".Customer " << sorted_customers_IDs[k] << " Has " << sorted_customers_points[k] << " Point(s)" << endl;
    }

    back_to_main();
}


void back_to_main() {

    bool back;
    
    cout << "\n\nWould you like to get back to the main menu? ( 1 for yes, 0 for no ): ";
    cin >> back; 

    if ( back ) {
        
        cout << "\n\n<< Back to Menu >>" << endl << endl;
        main();

    }
}

