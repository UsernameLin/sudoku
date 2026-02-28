#include "sudoku.h"
using namespace std;

bool sudoku::checkBox(int num, int row_num, int col_num)
{

}
bool sudoku::checkVertical(int num, int row_num)
{
    
}
bool sudoku::checkHorizontal(int num, int row_num)
{
    
}
void sudoku::makeSudoku(int seed)
{
    if(seed == 0)
    {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    }
    mt19937 engine(seed);
    uniform_int_distribution<int> rand(1,9); 
    int numbers[] = {9,9,9,9,9,9,9,9,9};
    for(int i = 0; i<9; ++i)
    {
        for(int j = 0; j<9; ++j)
        {
            int num = rand(engine);
            while(checkVertical(num,i) || checkHorizontal(num,j)||checkBox(num,i,j))
            {
                num = rand(engine);
            }
            masterList[i][j] = num;
        }
    }

}
