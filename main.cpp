#include "sudoku.h"
#include <getopt.h>

using namespace std;
// enum options{
// EASY,
// HARD,
// CUSTOM
// };
int getMode(int argc, char* argv[]){
    opterr = false;
    int opt = 0, index = 0;
    option longOpts[] = {
    {"easy", no_argument, NULL, 'e'},
    {"hard", no_argument, NULL, 'd'},
    {"custom", required_argument, NULL, 'c'},
    {"help", no_argument, NULL, 'h'},
    };

    while ((opt = getopt_long(argc, argv, "edc:h", longOpts, &index)) != -1)
    {
        switch (opt)
        {
            case 'e':
            {
                
                return 9;
            }
            case 'd':
            {
                return 18;

            }
            case 'c':
            {
                return stoi(optarg);
            }
            case 'h':
            {
                cout << "You want help?  This program accepts:\n";
                cout << "  -e, --Easy easy sudoku\n";
                cout << "  -d, --Hard hard sudoku \n";
                cout << "  -c, --Custom decide how many empty spaces \n";
                cout << "  -h, --help    This help page\n";
                break;
            }
            default:
            {
                cout << "I didn't recognize one of your flags!\n";
                exit(1);
            }
        } // switch
    } // while
    exit(1);
}
int main(int argc, char* argv[])
{
    sudoku g(getMode(argc, argv));
    return 0;
}