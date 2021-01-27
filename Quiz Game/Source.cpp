#include <iostream>
#include <string>
using namespace std;

int random_eas(int a, int liv, int scr);
int random_har(int a, int liv, int scr);

int add_eas(int a, int liv, int scr);
int add_har(int a, int liv, int scr);
void menu();
void menu_2();



int main() {

    int optionSelect; // declares variable for user input (used with choosing which action to take in the menu)
    int userInput = 1, difficultySelect;
    bool quizRun = true;


    do { // do while loop for action selection, continuing until the user chooses the option to end the program

        int lives = 3, score = 0;

        menu();

        cin >> optionSelect; // reads user input for action selection

        menu_2();

        cin >> difficultySelect;

        if (optionSelect == 5) { // condition check if number entered during action selection is 5
            cout << "Thank you for your time. Exiting program... \n"; // displays message informing user about the program exiting
            break; // break statement to end the loop, effectively stopping the program
        }
        else if (optionSelect != 5 && !cin.fail()) {

            if (difficultySelect == 1 && optionSelect == 1) {
                score = random_eas(userInput, lives, score);
            }
            else if (difficultySelect == 2 && optionSelect == 1) {
                score = random_har(userInput, lives, score);
            }
            else if (difficultySelect == 1 && optionSelect == 2) {
                score = add_eas(userInput, lives, score);
            }
            else if (difficultySelect == 2 && optionSelect == 2) {
                score = add_har(userInput, lives, score);
            }

        }


        cout << "Your final score is " << score << "\n";
        if (score == 5) {
            cout << "Well done! \n";
        }
        cout << "Try again? \n"
            << "1 - Yes \n"
            << "2 - No \n";
        cin >> optionSelect;
        switch (optionSelect) {
        case 1:
            cout << "Your lives and score has been reset. You can try again.\n";
            break;
        case 2:
            cout << "Exiting program... \n";
            quizRun = false;
            break;
        }


    } while (quizRun);


    return 0;

}

void menu() {
    cout << "---------QUIZ---------- \n"
        << "Please select a topic for your quiz. \n"
        << "1 = Random \n"
        << "2 = Maths \n"
        << "5 = Exit the program \n"
        << "---------MENU---------- \n";
}
void menu_2() {
    cout << "---------QUIZ---------- \n"
        << "Please select a difficulty for your topic. You have three lives. \n"
        << "1 = Easy \n"
        << "2 = A Challenge \n"
        << "---------MENU---------- \n";
}


int random_eas(int a, int liv, int scr) {

    bool quizRun = true;
    do {


        cout << "1. The sum of the numbers 1 and 3 are  \n"
            << " 1) 4 \n"
            << " 2) 5 \n"; // displays the result
        cin >> a;
        switch (a) {
        case 1:

            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 2:
            liv -= 1;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }


        cout << "2. The difference of the number 3 when subtracted by 6 is:  \n"
            << " 1) Four \n"
            << " 2) Three \n"
            << " 3) Negative Three \n"
            << " 4) Negative Four \n";
        cin >> a;
        switch (a) {
        case 3:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 1:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "3. The quotient of 10 when divided by 2 is: \n"
            << " 1) Five \n"
            << " 2) Three \n"
            << " 3) Ten \n"
            << " 4) Eight \n";

        cin >> a;
        switch (a) {
        case 1:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "4. The product of 15 when multiplied by 3 is: \n"
            << " 1) 55 \n"
            << " 2) 45 \n"
            << " 3) 35 \n"
            << " 4) 30 \n";

        cin >> a;
        switch (a) {
        case 2:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "5. The 20 when divided by 3 is is: \n"
            << " 1) 5.99 \n"
            << " 2) 6.65 \n"
            << " 3) 4 \n"
            << " 4) 6.66 \n";

        cin >> a;
        switch (a) {
        case 4:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 2:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "You have reached the end of this quiz without losing all your lives. \n";
        quizRun = false;
        break;

    } while (quizRun);


    return scr;

};

int random_har(int a, int liv, int scr) {

    bool quizRun = true;
    do {


        cout << "1. The sum of the numbers 1 and 3 are  \n"
            << " 1) 4 \n"
            << " 2) 5 \n"; // displays the result
        cin >> a;
        switch (a) {
        case 1:

            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 2:
            liv -= 1;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }


        cout << "2. The difference of the number 3 when subtracted by 6 is:  \n"
            << " 1) Four \n"
            << " 2) Three \n"
            << " 3) Negative Three \n"
            << " 4) Negative Four \n";
        cin >> a;
        switch (a) {
        case 3:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 1:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "3. The quotient of 10 when divided by 2 is: \n"
            << " 1) Five \n"
            << " 2) Three \n"
            << " 3) Ten \n"
            << " 4) Eight \n";

        cin >> a;
        switch (a) {
        case 1:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "4. The product of 15 when multiplied by 3 is: \n"
            << " 1) 55 \n"
            << " 2) 45 \n"
            << " 3) 35 \n"
            << " 4) 30 \n";

        cin >> a;
        switch (a) {
        case 2:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "5. The 20 when divided by 3 is is: \n"
            << " 1) 5.99 \n"
            << " 2) 6.65 \n"
            << " 3) 4 \n"
            << " 4) 6.66 \n";

        cin >> a;
        switch (a) {
        case 4:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 2:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "You have reached the end of this quiz without losing all your lives. \n";
        quizRun = false;
        break;

    } while (quizRun);


    return scr;

};
int add_eas(int a, int liv, int scr) {

    bool quizRun = true;
    do {

        cout << "1. The sum of the numbers 1 and 3 are  \n"
            << " 1) 4 \n"
            << " 2) 5 \n"; // displays the result
        cin >> a;
        switch (a) {
        case 1:

            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 2:
            liv -= 1;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }


        cout << "2. The difference of the number 3 when subtracted by 6 is:  \n"
            << " 1) Four \n"
            << " 2) Three \n"
            << " 3) Negative Three \n"
            << " 4) Negative Four \n";
        cin >> a;
        switch (a) {
        case 3:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 1:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "3. The quotient of 10 when divided by 2 is: \n"
            << " 1) Five \n"
            << " 2) Three \n"
            << " 3) Ten \n"
            << " 4) Eight \n";

        cin >> a;
        switch (a) {
        case 1:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "4. The product of 15 when multiplied by 3 is: \n"
            << " 1) 55 \n"
            << " 2) 45 \n"
            << " 3) 35 \n"
            << " 4) 30 \n";

        cin >> a;
        switch (a) {
        case 2:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "5. The 20 when divided by 3 is is: \n"
            << " 1) 5.99 \n"
            << " 2) 6.65 \n"
            << " 3) 4 \n"
            << " 4) 6.66 \n";

        cin >> a;
        switch (a) {
        case 4:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 2:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "You have reached the end of this quiz without losing all your lives. \n";
        quizRun = false;
        break;

    } while (quizRun);


    return scr;
}


int add_har(int a, int liv, int scr) {

    bool quizRun = true;
    do {


        cout << "1. Which of these choices is the area of a circle with a radius of 30  \n"
            << " 1) 2827.43 \n"
            << " 2) 3993.23 \n"
            << " 3) 4923.43 \n"
            << " 4) 1827.42 \n";
        cin >> a;
        switch (a) {
        case 1:

            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 2:
        case 3:
        case 4:
            liv -= 1;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }


        cout << "2. The square root of 8 is:  \n"
            << " 1) 4.23 \n"
            << " 2) 3.734 \n"
            << " 3) 2.82 \n"
            << " 4) 2.828 \n";
        cin >> a;
        switch (a) {
        case 4:
        case 3:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 1:
        case 2:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "3. Which of these is 1/4s converted to decimal form?: \n"
            << " 1) 0.25 \n"
            << " 2) 0.4 \n"
            << " 3) 0.2 \n"
            << " 4) 0.12 \n";

        cin >> a;
        switch (a) {
        case 1:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 2:
        case 4:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "4. 9/18 when simplified is: \n"
            << " 1) 6 \n"
            << " 2) 1/3 \n"
            << " 3) 2 \n"
            << " 4) 1/2 \n";

        cin >> a;
        switch (a) {
        case 4:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
        case 2:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }

        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "5. Is 6 a prime number?: \n"
            << " 1) True \n"
            << " 2) False \n"
            << " 3) Maybe \n";

        cin >> a;
        switch (a) {
        case 2:
            cout << "Correct! You have gained a point. \n";
            scr++;
            break;
        case 3:
        case 1:
            liv--;
            cout << "Wrong! You have " << liv << " live(s) remaining.\n";
            break;
        }


        if (liv == 0) {
            cout << "You have run out of lives. Ending quiz... \n";
            break;
        }



        cout << "You have reached the end of this quiz without losing all your lives. \n";
        quizRun = false;
        break;

    } while (quizRun);


    return scr;
}