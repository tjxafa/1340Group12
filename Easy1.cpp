#include <iostream>
#include <cstdlib>
#include <ctime>
#include "E1.h"

using namespace std;
bool E1() {
    srand(time(nullptr));
    int secret_number = rand() % 100 + 750;
    int guess = 0;
    int tries = 0;
    cout << "/**********************/\n";
    cout << "/*    Blast Expert    */\n";
    cout << "/**********************/\n";
    cout << "+------------------------------------------------------------------------------------------------+\n";
    cout << "| Now you need to defuse a bomb set by AI.                                                       |\n";
    cout << "| After analysis, the bomb is locked with a three-digit code and encrypted between 750-849.      |\n";
    cout << "| You need to crack the code and defuse the bomb within 10 attempts.                             |\n";
    cout << "| **If the incorrect code is entered for the tenth time, the bomb will detonate immediately.**   | \n";
    cout << "+------------------------------------------------------------------------------------------------+\n";
    cout<<"Let's Start!"<<endl;
    cout<<endl;
    while (guess != secret_number) {
        cout << "Enter your code (750 - 849). ";
        cin >> guess;
        tries++;
    cout<<"+----------------------------------------------------------+\n";
        if (guess < secret_number){
            cout<<"| You miss. It is too small.                               |"<<endl;
            cout<<"| You have "<<10-tries<< " chnaces left.                                 |"<<endl;
        }
        else if (guess > secret_number){
            cout <<"| You miss. It is too large.                               |"<<endl;
            cout<<"| You have "<<10-tries<<" chnaces left.                                 |"<<endl;
        }
        else{
            cout<<endl;
            cout<<"What a thrill! Congratulations on successfully defusing the bomb!! "<<endl;
            cout<<endl;
            return true;
            }
    cout<<"+----------------------------------------------------------+\n";
    cout<<endl;
    if (tries == 10){
        cout<<"You lose."<<endl;
        cout<<"BOOM!!!"<<endl;
        cout<<endl;
        return false;
    }

    }
    return true;
}
