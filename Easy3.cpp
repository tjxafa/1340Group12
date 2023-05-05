#include <iostream>
# include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "E3.h"
using namespace std;

bool E3(){
    srand(time(nullptr));
    int a = rand() %9 + 1;
    int b = rand() %10 + 5;
    int c = 3*a-2*b;
    int total_score=0;
    int c_ans, p_ans;
    cout << "/***********************/\n";
    cout << "/*     MATH CRISIS     */\n";
    cout << "/***********************/\n";
    cout << "********************************************************\n";
    cout << "| It's time to test your intelligence!!!               |\n";
    cout << "| You will be given five challenging questions by AI.  |\n";
    cout << "| For achieving thefinal victory,                      |\n";
    cout << "| You have to answer at least 4 question correctly!    |\n";
    cout << "********************************************************\n";
    cout<<"Let's Start!!"<<endl;
    cout<<endl;
    for(int i=0; i<5; ++i){
        if (i>=0 && i<2){
            cout<<"what is the value of \"";
            cout<<"2*"<<a<<"+"<<b<<"\"?  ";
            c_ans = 2*a+b;
            cin>>p_ans;
            cout<<"Um......."<<endl;
            sleep(1);
            if (c_ans == p_ans) {
                cout<<"Good Job!!";
                cout<<"You are Right!!"<<endl;
                total_score+=1;
            }
            else cout<<"Oops...You are Wrong.."<<endl;
        }
        else if (i>1 && i<4){
            cout<<"what is the value of \"";
            cout<<"(-"<<a<<"+"<<b<<")^2+"<<b<<"\"?  ";
            c_ans = pow((b-a),2)+b;
            cin>>p_ans;
            cout<<"Um......."<<endl;
            sleep(1);
            if (c_ans == p_ans) {
                cout<<"Good Job!!";
                cout<<"You are Right!!"<<endl;
                total_score+=1;
                }
                else cout<<"Oops...You are Wrong.."<<endl;
            }
        else{
            cout<<"what is the value of ";
            cout<<"("<<a<<"+3*"<<b<<"-2*"<<c<<")*2"<<"\"?  ";
            c_ans = (a+3*b-2*c)*2;
            cin>>p_ans;
            cout<<"Um......."<<endl;
            sleep(1);
            if (c_ans == p_ans) {
                cout<<"Good Job!!";
                cout<<"You are Right!!"<<endl;
                total_score+=1;
                }
            else cout<<"Oops...You are Wrong.."<<endl;
        }
    cout<<"Keep Going!!"<<endl;
    sleep(0.5);
    cout<<"***Your Score: "<<total_score<<endl;
    cout<<endl;        
     a = rand() %9 + 1;
     b = rand() %10 + 5;
    }
    sleep(1);
    if (total_score > 4){
        cout<<"You have ultimately achieved victory!"<<endl;
        cout<<"Congratulations!!"<<endl;
        return true;
    }
    else{
        cout<<"You didn't get 4 scores..."<<endl;
        cout<<"That's too bad....You Lose."<<endl;
        cout<<"Try Again!"<<endl;
        return false;
    }
    return true;
}
