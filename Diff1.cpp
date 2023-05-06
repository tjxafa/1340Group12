#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include "Diff1.h"

using namespace std;

map<string,double> t;

const int N = 9;
int ans[100];

//the function that prints the board of the sudoku.
void printBoard(const vector<vector<int>>& board){

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j != N - 1) {
                cout << "| ";
            }
        }

        cout << endl;
        if ((i + 1) % 3 == 0 && i != N - 1) {
            cout << "---------------------" << endl;
        }
    }

}



//the function that reads information from the txt file.
map<string, double> load_map_from_file() {

    map<string, double> my_map;
    ifstream fin("player.txt");
    string key;
    double value;

    while (fin >> key >> value) {
        my_map[key] = value;
    }
    return my_map;

}

//check valid move.
int checkboard(const vector<vector<int>>& board){

    int count=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]!=0) count++;
        }
    }

    if (count==81) return 1;
    else return 0;

} 

int playDiff1(){
    cout<<"*******Welcome to Sudoku World!********"<<endl;
    int blood=5;

    t=load_map_from_file();
    int random_num = rand() % 8 + 1; 

    //randomly choose a board from 1-8.
    string filename = "sudoku" + to_string(random_num) + ".txt";

    int n=0,m=0;
    int tema,temb,temc;
    pos ques[100];
    ifstream file(filename);
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {//save the lines and collumn of answers into the structed variable;
        for (int j = 0; j < N; j++) {
            file >> board[i][j];
            if (board[i][j]==0){
                ques[m].r=i+1;
                ques[m].c=j+1;
                m++;
            }
        }
    }

    while (file >> ans[n]) n++;
    file.close();
    printBoard(board);//print the board.

    while (checkboard(board)!=1){//check if the answer is correct.
        cout<<"The number of trial is "<<blood<<endl;
        cout<<"Your Answer is (row/column/number eg.2 1 9)-> ";
        cin>>tema>>temb>>temc;
        for (int i =0;i<100;i++){
            if (ques[i].r==tema) {
                if (ques[i].c==temb){
                    if (ans[i]==temc){
                        board[tema-1][temb-1]=temc;
                    }
                    else{
                        cout<<"Wrong answer, Try again!"<<endl;
                        blood--;
                    }
                }
            }
        }

        if (blood==0){
            cout<<"Oh no, you lose !";
            return 0;
        }
        printBoard(board);
    }

    cout<<"Congradulations, You Win!!!";
    cout<<"Record Saved!";
    
    //stop the timer and record the time into the txt file.
    return 1;

}
