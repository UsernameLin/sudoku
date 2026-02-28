#include <iostream>
#include <random>
#include <vector>
class sudoku
{

public:
sudoku(int empty, int seed = 0):empty_tiles(empty)
{
    makeSudoku(seed);
};
void makeSudoku(int seed){};
void printSudoku(){};
void play(){};

// ~sudoku();

private:
bool checkBox(int num, int row_num, int col_num){};
bool checkVertical(int num, int row_num){};
bool checkHorizontal(int num, int col_num){};
std::vector<std::vector<int>> masterList;
std::vector<std::vector<int*>> vertical;
std::vector<std::vector<int*>> box;
int empty_tiles;
};

