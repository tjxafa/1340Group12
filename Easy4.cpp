#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <map>
#include <unistd.h>
#include <stdlib.h>
#include "Easy4.h"

using namespace std;

bool playEasy4(){
    srand(time(nullptr));
    string ai_list[6] = {"ChatGPT","Claude","YouChat","Poe","HebbiaAI"};
    int index = rand()%100 +1;
    map<string,int> data;
    cout << "/*************************/\n";
    cout << "/*    MEMORY FRAGMENTS   */\n";
    cout << "/*************************/\n";
    cout << "****************************************************************\n";
    cout << "| It's time to test your memory skills!                        |\n";
    cout << "| You will need to memorize the power indices of 5 AI leaders, |\n";
    cout << "| and then give the correct index for each leader!             |\n";
    cout << "| You have to answer at least 3 question correctly to win!     |\n";
    cout << "****************************************************************\n";
    cout<<"Let's Start!"<<endl;
    cout<<endl;
        for (int i=0; i<5; ++i){
            data[ai_list[i]] = index;
            index = rand()%100 + 1;
        }
        char Yes;
        cout<<"Are you ready to memorize?"<<endl;
        cout<<"Enter \'Y\' if you are ready! ";
        cin>>Yes;
        for(int i=0; i<data.size(); ++i){
            system("clear");
            cout<<"This AI........."<<endl;
            sleep(1);
            cout<<"***AI Name: "<<ai_list[i]<<endl;
            cout<<"***AI Index: "<<data[ai_list[i]]<<endl;
            cout<<"Do you memorize its index?"<<endl;
            cout<<"Enter \'Y\' if you have already memorize it. ";
            cin>>Yes;
        }
        cout<<endl;
        sleep(1);
        cout<<"Now is your turn!"<<endl;
        cout<<"Enter \'Y\' if you are ready! ";
        cin>>Yes;
        int p_ans;
        int score=0;
        system("clear");
        for(int i=0; i<5; ++i){
            cout<<endl;
            cout<<"What is the power index of \""<<ai_list[i]<<"\"? ";
            cin>>p_ans;
            cout<<"Um........"<<endl;
            sleep(1);
            if (p_ans == data[ai_list[i]]){
                cout<<"Great!! You are Right!!"<<endl;
                score+=1;
                cout<<"Your Score: "<<score<<endl;
        }
            else{
                cout<<"Oops....You are Wrong.."<<endl;
                cout<<"***Your Score: "<<score<<endl;
            }
        //cout<<"Keep Going!"<<endl;
        }
        sleep(1);
        cout<<endl;
        if (score >= 3){
        cout<<"You have ultimately achieved victory!"<<endl;
        cout<<"Congratulations!!"<<endl;
            return true;
        }
        else{
            cout<<"That's too bad... You Lose.."<<endl;
            cout<<"You did a good job already! You get"<<score<<"score!"<<endl;
            cout<<"Don't give up! Let's try again!"<<endl;
            return false;
            }

	return true;
}
