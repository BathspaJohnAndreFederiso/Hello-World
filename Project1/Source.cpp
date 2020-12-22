#include <iostream>
#include <string>
using namespace std;

double one_order(double a);
double two_order(double a);
double thr_order(double a);
double for_order(double a);
double fiv_order(double a);

bool bin_decision(int a, bool b);
bool ord_decision(int a, bool b);
double reset_value(double a); // declares function to reset the argument value back to 0
double debug(double a); // function to debug whenever an invalid/incorrect data type is entered in a cin
double inv_value(double a, double b);
void menu();


int main() {

    int itemOrder; // declares variable for choosing item order
    int orderInput = 0, actionInput = 0;
    double userBalance = 0;
    double cartSum = 0;
    bool machineRun = true, orderRun = true;

    

    do { // do while loop for vending machine program

        menu();
        userBalance = reset_value(userBalance);
        cartSum = reset_value(cartSum);

        cout << "Alternatively, you can press 0 to exit the program if you wish. \n";
        
        

        do{ // nested do while loop for item ordering and buying activities

            cin >> orderInput;

            if (orderInput > 6 || orderInput < 0 || cin.fail()) {

                debug(orderInput);

            }
            else if (orderInput == 0) { // condition check if number entered during action selection is 5

                cout << "Thank you for your time. Exiting program... \n"; // displays message informing user about the program exiting
                machineRun = false;
                break; // break statement to end the loop, effectively stopping the program

            }
            else if (orderInput != 0 && !cin.fail()) { // condition check


                while (cin.fail() || orderInput < 0 || orderInput > 5){
                    debug(orderInput); 
                    cin >> orderInput; 
                }

                switch (orderInput) {
                case 1:
                    cartSum = one_order(cartSum);
                    cout << "Milkshake added. ";
                    break; // break statement for this switch statement
                case 2:
                    cartSum = two_order(cartSum);
                    cout << "Coffee added. ";
                    break; // break statement
                case 3:
                    cartSum = thr_order(cartSum);
                    cout << "Soda added. ";
                    break; // break statement

                case 4:
                    cartSum = for_order(cartSum);
                    cout << "Chips added. ";
                    break; // break statement

                case 5:
                    cartSum = fiv_order(cartSum);
                    cout << "Milktea added. ";
                    break;
                }

                cout << "Finish your order? \n"
                    << "1 - Finish Order \n"
                    << "2 - Keep Buying \n";

                cin >> actionInput;

                while (cin.fail() || actionInput > 2 || actionInput < 1){
                    debug(actionInput);
                    cin >> actionInput;
                }

                orderRun = ord_decision(actionInput, orderRun);

            }
        
            
        } while (orderRun);

        if (orderInput != 0) {


            cout << "The value of your queued items are " << cartSum << ". Please enter your money. \n";

            cin >> userBalance;
           
            userBalance = inv_value(userBalance, cartSum);

            userBalance -= cartSum;


            cout << "Your item/s have been dispensed, and your change is " << userBalance << " AED. Buy again? \n"
                << "1 - Yes \n"
                << "2 - No \n";
            cin >> actionInput;
            machineRun = bin_decision(actionInput, machineRun);
        }

    } while (machineRun);

    return 0;
}


bool bin_decision(int a, bool b){
    if (a == 2) {
        cout << "Thank you for your time, exiting program... \n";
        return b == false;
    }
    else if (a == 1) {
        cout << "Bringing up the menu... \n";
        return b == true;
    }
}

bool ord_decision(int a, bool b) {
    if (a == 1) {
        cout << "-------------------------\n"
            << "Exiting buy process... \n"
            << "-------------------------\n";
        return b == false;
    }
    else if (a == 2) {
        cout << "-------------------------\n"
            << "Restarting buy process...\n"
            << "------------------------- \n";
    }
}

double inv_value(double a, double b){
    while (a < b || cin.fail()) {
        cout << "Your entered balance is invalid! Please enter a bigger/appropriate value! \n";
        cin.clear();
        cin.ignore(1000, '\n'); // ignores the input
        cin >> a;
    }
    return a;
}

double debug(double a) { // debug function, included with every cin command
    cout << "Invalid input, try again. \n"; // displays message informing about the incorrect input
    cin.clear(); // clears bad input flag
    cin.ignore(1000, '\n'); // ignores the input
    return a; // returns the value of any argument
}

double reset_value(double a) {
    return a = 0;
}



void menu() {
    cout << "---------------------- \n"
        << "Here are the available items. \n"
        << "----------------------- \n"
        << "1. Milkshake - 5 AED \n"
        << "2. Coffee - 3.50 AED \n"
        << "3. Soda - 3.30 AED \n"
        << "4. Chips - 6.20 AED\n"
        << "5. Milktea - 2 AED \n"
        << "----------------------- \n" // displays menu of possible actions (mathematical operations or quit the program) to choose from
        << "Please use the number assigned to each item to select them \n";
       
}

double one_order(double a) {
    a += 5.0;
    return a;
}
double two_order(double a) {
    a += 3.5;
    return a;
}
double thr_order(double a) {
    a += 3.3;
    return a;
}
double for_order(double a) {
    a += 6.2;
    return a;
}
double fiv_order(double a) {
    a += 2.0;
    return a;
}
