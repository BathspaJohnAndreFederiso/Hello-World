#include <iostream>
#include <string>
using namespace std;

double one_order(double a);
double two_order(double a);
double thr_order(double a);
double for_order(double a);
double fiv_order(double a);
double reset_value(double a); // declares function to reset the argument value back to 0
double debug(double a); // function to debug whenever an invalid/incorrect data type is entered in a cin
void menu();


int main() {

    int itemOrder; // declares variable for choosing item order
    int orderInput, actionInput;
    double cartSum = 0, userBalance = 0; // declares variables, one for carrying item prices and one for the user's Balance
    bool machineRun = true;

    menu();

    do { // do while loop for vending machine program

        reset_value(cartSum);
        reset_value(userBalance);
        

        cout << "Alternatively, you can press 0 to exit the program if you wish. \n";
        
        

        do{

            cin >> itemOrder; // reads user input for action selection

            if (itemOrder > 6 || itemOrder < 0 || cin.fail()) {
                debug(itemOrder);
            }
            else if (itemOrder == 0) { // condition check if number entered during action selection is 5
                cout << "Thank you for your time. Exiting program... \n"; // displays message informing user about the program exiting
                machineRun = false;
                break; // break statement to end the loop, effectively stopping the program
            }
            else if (itemOrder != 0 && !cin.fail()) { // condition check


                cout << "Please enter two numbers. \n"; // displays message informing user to enter numbers to be used in calculating

                cin >> orderInput; // reads user input
                while (cin.fail()) { // these while statements check if any invalid data types are entered
                    debug(orderInput); // calls debug function and puts in the appropriate argument for both userInput variables
                    cin >> orderInput; // another cin to let the user continue inputting values
                }


                switch (itemOrder) {
                case 1:
                    one_order(cartSum);
                    cout << "Milkshake added.";
                    break; // break statement for this switch statement
                case 2:
                    two_order(cartSum);
                    cout << "Coffee added.";
                    break; // break statement
                case 3:
                    thr_order(cartSum);
                    cout << "Soda added.";
                    break; // break statement

                case 4:
                    for_order(cartSum);
                    cout << "Chips added.";
                    break; // break statement

                }

                cout << "Please enter your money. \n";

                cin >> userBalance;
            }
        
            
        } while (true);

    } while (machineRun);

    return 0;
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
        << "Please use the number assigned to each \n"
        << "item to select them. \n";
}

double one_order(double a) {
    return a += 5;
}
double two_order(double a) {
    return a += 3.50;
}
double thr_order(double a) {
    return a += 3.30;
}
double for_order(double a) {
    return a += 6.20;
}
double fiv_order(double a) {
    return a += 2;
}
