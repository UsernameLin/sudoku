#include <iostream>
#include <random>
#include <vector>
class sudoku
{

public:
sudoku(int empty, unsigned seed = 0);
void makeSudoku();
void printSudoku();
void play();

// ~sudoku();

private:
bool checkBox(int num, int row_num, int col_num);
bool checkHorizontal(int num, size_t row_num);
bool checkVertical(int num, size_t col_num);
int rand();
std::vector<std::vector<int>> masterList;
std::vector<std::vector<int*>> vertical;
std::vector<std::vector<int*>> box;
int empty_tiles;
 std::mt19937 mt;
};

