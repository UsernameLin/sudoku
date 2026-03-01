#include "sudoku.h"
#include <queue>
using namespace std;

int sudoku::rand()
{
    std::uniform_int_distribution<int> die{1, 9};
    return die(mt);
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
    int new_row_num = row_num/ 3 ;
    int new_col_num = col_num/ 3 ;
    for(int i = new_row_num * 3; i < (new_row_num * 3) + 3; ++i)
    {
        for(int j = new_col_num * 3; j< (new_col_num * 3)+3; ++j)
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
    queue<int> q;
            q.push(1);
            q.push(2);
            q.push(3);
            q.push(4);
            q.push(5);
            q.push(6);
            q.push(7);
            q.push(8);
            q.push(9);
    for(size_t i = 0; i<9; ++i)
    {
        for(size_t j = 0; j<9; ++j)
        {
            queue<int> c = q;
            int num = rand();
            while(checkVertical(num,j) || checkHorizontal(num,i)||checkBox(num,static_cast<int>(i),static_cast<int>(j)))
            {
                if(c.empty())
                {
                    printSudoku();
                    masterList[i].assign(9,-1);
                    c = q;
                    j = 0;
                    num = rand();
                }
                else
                {
                num = c.front();
                c.pop();
               }
            }
            masterList[i][j] = num;
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
sudoku::sudoku(int empty, unsigned seed):empty_tiles(empty),mt(seed == 0 ? static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()): seed)
{
    masterList.resize(9);
    for(int i = 0; i < 9; ++i)
    {
        masterList[static_cast<size_t>(i)].assign(9,-1);
    }
    makeSudoku();
};
void sudoku::play(){
    
    while(true)
    {
        int num;
        cin >> num;
        while(num < 0 || num > 9)
        {
            cin >> num;
        }
        if(empty_tiles == 0)
        {
            return;
        }

    }
}