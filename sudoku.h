#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>

struct pos {
    int r, c;
};

void printBoard(const std::vector<std::vector<int>>& board);
void save_map_to_file(const std::map<std::string, double>& t);
void printdata(const std::map<std::string, double>& t);
std::map<std::string, double> load_map_from_file();
int checkboard(const std::vector<std::vector<int>>& board);

#endif