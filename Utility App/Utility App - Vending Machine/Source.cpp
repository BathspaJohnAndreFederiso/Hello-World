#include <iostream>
#include <string>
using namespace std;

double one_order(double a);
double two_order(double a);
double thr_order(double a);
double for_order(double a);
double fiv_order(double a); // functions that add item prices appropriate to each item to the cartSum variable

bool bin_decision(int a, bool b);
bool ord_decision(int a, bool b); // functions that contain if-elses to complement inputs that decide how to run the "ordering items" phase and the entire machine itself

double reset_value(double a); // declares function to reset the argument value back to 0
double debug(double a); // declares function that deals with whenever an invalid/incorrect data type is entered in a cin
double loop_debug(double a);
double inv_value(double a, double b); // function that contains a condition check if one variable is lesser than the other
void menu(); // function that displays an item menu and how to order them

int main() {

    int orderInput = 0, actionInput = 0; // declares variables that reads user input for item order and decisions respectively
    double userBalance = 0, cartSum = 0; // declares variables for reading user input on their balance and the value of accumulated ordered items
    bool machineRun = true, orderRun; // declares bool variables for running do while loops related to the app itself and the item ordering phase

    do { // do-while loop for the entire vending machine program


        menu(); // calls the menu function to display the items and possible actions

        orderRun = true; // sets bool orderRun to true at the start of every loop of this do-while
        userBalance = reset_value(userBalance);
        cartSum = reset_value(cartSum); // calls functions to reset both userBalance and cartSum variables at the start of each instance


        do { // nested do-while loop for item ordering and buying activities

            cin >> orderInput; // reads user input on which item they will order

            if (orderInput > 6 || orderInput < 0 || cin.fail()) { // condition check if the inputted value is not within the available numbers to choose from or an invalid data type

                debug(orderInput); // calls debug function with orderInput as argument

            }
            else if (orderInput == 0) { // condition check if number entered during action selection is 0

                cout << "Thank you for your time. Exiting program... \n"; // displays message informing user about the program exiting
                machineRun = false; // sets the bool value for the loop of the entire machine to false, stopping the operation
                break; // break statement to end the loop, also stopping this nested do loop, so the other parts of this phase don't run when the user chooses to end early

            }
            else if (orderInput != 0 && !cin.fail()) { // condition check for if the orderInput is both not 0 and an invalid data type

                switch (orderInput) { // switch case that takes the orderInput variable
                case 1: // case that triggers when the variable is 1

                    cartSum = one_order(cartSum); // calls one_order function with cartSum argument to add to the variable itself
                    cout << "Milkshake added. \n";  // prints message saying this particular item is dispensed
                    break; // break statement to separate this case
                    // the other cases are extremely similar, only with the case condition, function and type of item being dispensed the only differences
                case 2:

                    cartSum = two_order(cartSum);
                    cout << "Coffee added. \n";
                    break; // break statement

                case 3:

                    cartSum = thr_order(cartSum);
                    cout << "Soda added. \n";
                    break; // break statement

                case 4:

                    cartSum = for_order(cartSum);
                    cout << "Chips added. \n";
                    break; // break statement

                case 5:

                    cartSum = fiv_order(cartSum);
                    cout << "Milktea added. \n";
                    break; // break statement

                }

                cout << "---------------------- \n"
                    << "Finish your order? \n"
                    << "1 - Finish Order \n"
                    << "2 - Keep Buying \n"
                    << "3 - Cancel Order \n"
                    << "---------------------- \n";// prints message displaying a simple menu of possible actions to take

                cin >> actionInput; // actionInput is used again to read the input in this part
                actionInput = loop_debug(actionInput); // calls loop_debug function with the actionInput argument, and returns the result here


                switch (actionInput) { // switch case with actionInput as argument
                case 3: // case condition that triggers when actionInput is equal to 3

                    cartSum = reset_value(cartSum); // calls reset_value with cartSum argument, to change the variable itself
                    cout << "Order canceled. You may order again or exit. \n"; // prints message informing the user about the result of this action
                    break; // break statement

                case 1:
                case 2: // case condition that triggers whenever actionInput is equal to 1 or 2

                    orderRun = ord_decision(actionInput, orderRun); // calls ord_decision function with bool orderRun and actionInput as argument, changing orderRun with any returned bool values
                    break; // break statement

                }

            }


        } while (orderRun); // this nested do-while loop uses the bool variable orderRun to operate

        if (orderInput != 0) { // condition check if orderInput is not equal to 0 (the exit program choice in the first cin of this program)


            cout << "The value of your queued items are " << cartSum << " AED. Please enter your money. \n"; // displays message that shows the value of the accumulated items so far and tells user to
                                                                                                             // input the money value
            cin >> userBalance; // reads input for the user's money value

            userBalance = inv_value(userBalance, cartSum); // calls inv_value with userBalance and cartSum arguments, changes the value of userBalance if the 
                                                           // the if-else statement in this function successfully triggers
            userBalance -= cartSum; // subtracts the value of the accumulated items from the entered value for userBalance


            cout << "Your item/s have been dispensed, and your change is " << userBalance << " AED. Buy again? \n"
                << "1 - Yes \n"
                << "2 - No \n"; // displays message informing of the successful transaction, remaining change (if any) and one more decision to make
            cin >> actionInput; // reads user input for this one last decision, which is either to buy again or exit after the transaction
            machineRun = bin_decision(actionInput, machineRun); // calls bin_decision function with variables actionInput and machineRun as arguments, returns the result from this function
        }

    } while (machineRun); // this do-while loop uses bool variable machineRun to operate

    return 0;
}


bool bin_decision(int a, bool b) { // defines bool function bin_decision, with one int and one bool variable as arguments
    if (a == 2) { // condition check if the int argument is equal to 2
        cout << "Thank you for your time, exiting program... \n"; // prints message displaying the program exiting message
        return b == false; // changes bool argument to false
    }
    else if (a == 1) { // condition check if the int argument is equal to 1
        cout << "Bringing up the menu... \n"; // prints message informing about the program starting again
        return b == true; // changes bool argument to true
    }
}

bool ord_decision(int a, bool b) { // defines bool function ord_decision, with one int and one bool variable as arguments
    if (a == 1) { // condition check if the int argument is equal to 1
        cout << "-------------------------\n"
            << "Exiting buy process... \n"
            << "-------------------------\n"; // prints message displaying the ordering phase of the application ending
        return b == false; // returns bool argument as false
    }
    else if (a == 2) { // condition check if the int argument is equal to 2
        cout << "You can buy again. \n"; // prints message informing user about their ability to buy again
        return b == true; // returns bool argument as true
    }
}

double inv_value(double a, double b) { // defines double function inv_value, with two double variables as arguments
    while (a < b || cin.fail()) { // this while loop condition checks for if the first argument is less than the second argument, or if an incorrect data type has been entered
        cout << "Your entered balance is invalid! Please enter a bigger/appropriate value! \n"; // displays message informing about the error and tells user to try again
        cin.clear(); // clears bad input flag
        cin.ignore(1000, '\n'); // ignores the input
        cin >> a; // another cin input so the user can try again
    }
    return a; // returns the value of the first double argument
}

double debug(double a) { // defines this debug function, included with the cin for orderInput
    cout << "Invalid input, try again. \n"; // displays message informing about the incorrect input
    cin.clear(); // clears bad input flag
    cin.ignore(1000, '\n'); // ignores the input
    return a; // returns the value of any argument to main
}
double loop_debug(double a) { // this debug function doesn't need a while loop from int main to operate, included with the cin for userBalance
    while (cin.fail() || a > 3 || a < 1) { // while loop that operates as long either cin.fail is achieved here, action input is greater than 3 or lesser than 1
        cout << "Invalid input, try again. \n"; // displays message informing about the incorrect input
        cin.clear(); // clears bad input flag
        cin.ignore(1000, '\n'); // ignores the input
        cin >> a; // repeats cin input for the argument
    }
    return a; // returns value to main
}
double reset_value(double a) { // defines double function reset_value with one argument
    return a = 0; // a simple operation that changes the value of the argument to 0
}


void menu() { // defines void function menu
    cout << "---------------------- \n"
        << "Here are the available items. \n"
        << "----------------------- \n"
        << "1. Milkshake - 5 AED \n"
        << "2. Coffee - 3.50 AED \n"
        << "3. Soda - 3.30 AED \n"
        << "4. Chips - 6.20 AED\n"
        << "5. Milktea - 2 AED \n"
        << "----------------------- \n" // displays menu of possible actions (mathematical operations or quit the program) to choose from
        << "Please use the number assigned to each item to select them \n" // printed message tells user to use the numbers assigned to each item to choose them for ordering
        << "Alternatively, you can press 0 to exit the program if you wish. \n"; // prints message telling users how to end the program early without ordering

}

double one_order(double a) { // these double functions take one argument, and are very similar except for the value to be added for each function 
    a += 5.0; // adds 5.0 to the argument value
    return a; // returns value after operation
}
double two_order(double a) {
    a += 3.5; // adds 3.5 
    return a;
}
double thr_order(double a) {
    a += 3.3; // adds 3.3
    return a;
}
double for_order(double a) {
    a += 6.2; // adds 6.2
    return a;
}
double fiv_order(double a) {
    a += 2.0; // adds 2.0
    return a;
}