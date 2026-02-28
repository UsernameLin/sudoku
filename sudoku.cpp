#include "sudoku.h"
using namespace std;

int sudoku::rand()
{
    if(seed == 0)
        {
        mt = mt19937{static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count())};
        }
    std::uniform_int_distribution<int> die{1, 9};
    int value{die(mt)};
    return value;
};

bool sudoku::checkHorizontal(int num, size_t row_num)
{
    for(size_t i = 0; i<9; ++i)
    {
        if(masterList[row_num][i] == num)
        {
            return true;
        }
    }
    return false;
}
bool sudoku::checkVertical(int num, size_t col_num)
{
    for(size_t i = 0; i<9; ++i)
    {
        if(masterList[i][col_num] == num)
        {
            return true;
        }
    }
    return false;
}
bool sudoku::checkBox(int num, int row_num, int col_num)
{
    row_num = abs(row_num - 1)/ 3 ;
    col_num = abs(col_num - 1)/ 3 ;
    for(int i = row_num * 3; i < 3; ++i)
    {
        for(int j = col_num * 3; j< 3; ++j)
        {
            if(masterList[static_cast<size_t>(i)][static_cast<size_t>(j)] == num)
            {
                return true;
            }
        }
    }
    return false;
}
void sudoku::makeSudoku()
{
    int numbers[] = {9,9,9,9,9,9,9,9,9};
    for(size_t i = 0; i<9; ++i)
    {
        for(size_t j = 0; j<9; ++j)
        {
            int num = rand();
            while(numbers[num-1] == 0){num = rand();}
            while(checkVertical(num,i) || checkHorizontal(num,j)||checkBox(num,static_cast<int>(i),static_cast<int>(j)))
            {
                num = rand();
            }
            masterList[i][j] = num;
            --numbers[num-1];
        }
    }

}
void sudoku::printSudoku()
{
    for(size_t i = 0; i<masterList.size(); ++i)
    {
        for(size_t j = 0; j< masterList[i].size(); ++j)
        {
            cout << masterList[i][j] << " ";
        }
        cout << '\n';
    }
}
sudoku::sudoku(int empty, unsigned seed = 0):empty_tiles(empty),mt(seed),seed(seed)
{
    masterList.resize(9);
    for(int i = 0; i < 9; ++i)
    {
        masterList[static_cast<size_t>(i)].assign(9,-1);
    }
    makeSudoku();
};
