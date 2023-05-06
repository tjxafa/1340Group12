#include <iostream>
# include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "Easy2.h"

using namespace std;

bool Easy2() {
    cout << "/**********************/\n";
    cout << "/*      THE FATE      */\n";
    cout << "/**********************/\n";
    cout << "*****************************************************\n";
    cout << "| It's time to test your luck!                      |\n";
    cout << "| You need to compete with the AI opponent on luck! |\n";
    cout << "| **Player who win three games will be the winner** |\n";
    cout << "| 'R' for Rock                                      |\n";
    cout << "| 'P' for Paper                                     |\n";
    cout << "| 'S' for Scissors                                  |\n";
    cout << "*****************************************************\n";
    cout<<"GOOD LUCK!"<<endl;
    cout<<endl;
    srand(time(nullptr));
    char enemy[] = "RPS";
    char enemy_choose = enemy[rand() % 3];
    char player_choose;
    int score=0, lose = 0;
    while (score<3 and lose<3){
        cout<<endl;
        cout<<endl;
        cout << "YOU CHOOSE A....";
        cin >> player_choose;
        cout<<"The RESULT IS......"<<endl;
        sleep(1);
        switch (enemy_choose) {
            case 'R':
                switch (player_choose) {
                    case 'R':
                        cout<<"WOW! YOU TIE!" << endl;
                        break;
                    case 'P':
                        cout << "Congratulations! YOU WIN!!" << endl;
                        score++;;
                        break;
                    case 'S':
                        cout << "Oops..... YOU LOSE..." << endl;
                        lose++;
                        break;
                }
                cout<<"***Your Score: "<<score<<endl;
                cout<<"***AI's Score: "<<lose<<endl;
                break;
            case 'P':
                switch (player_choose) {
                    case 'R':
                        cout << "Oops..... YOU LOSE..." << endl;
                        lose++;
                        break;
                    case 'P':
                        cout<<"WOW! YOU TIE!" << endl;
                        break;
                    case 'S':
                        cout << "Congratulations! YOU WIN!!" << endl;
                        score++;
                        break;
                }
                cout<<"***Your Score: "<<score<<endl;
                cout<<"***AI's Score: "<<lose<<endl;
                break;
            case 'S':
                switch (player_choose) {
                    case 'R':
                        cout << "Congratulations! YOU WIN!!" << endl;
                        score++;
                        break;
                    case 'P':
                        cout << "Oops..... YOU LOSE..." << endl;
                        lose++;
                        break;
                    case 'S':
                        cout<<"WOW! YOU TIE!" << endl;
                        break;
                }
                cout<<"***Your Score: "<<score<<endl;
                cout<<"***AI's Score: "<<lose<<endl;
                break;
        }
        enemy_choose = enemy[rand() % 3];
        //cout<<enemy_choose<<endl;;

    }
    if (score == 3){
        cout<<endl;
        cout<<"You have ultimately achieved victory!!!"<<endl;
        cout<<"Well Done!!"<<endl;
        return true;
    }
    if (lose == 3){
        cout<<endl;
        cout<<"AI have ultimately achieved victory!"<<endl;
        cout<<"Try Again!"<<endl;
        return false;
    }
    return true;
    }


