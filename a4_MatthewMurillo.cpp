#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int eq[8] = {0}, c = 0, cntr = 1; // declaring variables and board
    eq[0] = 0; // first queen at the top left corner
Nc:
    c++; // add the column variable by 1
    if (c == 8)
        goto Print; // once the column reaches the end of the board, we print the board
    eq[c] = -1; // initialize row back to -1
Nr:
    eq[c]++; // add row by one
    if (eq[c] == 8)
        goto Backtrack; // if there is no solutions in the row, then we go to backtrack to substract column by 1

        /*Check test on whether the queen can be placed in the spot by the
        diagonal test and the row test using for loops */

        //ROW TEST
        for (int i = 0; i < c; i++)
        {
        if (eq[i] == eq[c])
            goto Nr; // goes back to Nr
        }
        //DIAGONAL TEST    
        for (int i = 0; i < c; i++)
        {
            if ((c - i) == abs(eq[c] - eq[i]))
                goto Nr; // goes back to Nr
        }
    goto Nc; // goes back to Nc to add column by 1 and redo program

// if r = 8, we go to here to subtract column by 1 and find another solution in the column    
Backtrack:
    c--; // subtract c by 1
    if (c == -1)
        return 0; // if column reaches the end of the board, then there are no more solution, closing the program
    goto Nr; // return back to Nr to continue moving down

//prints out the solution to the problem using nested for loop
Print:
    cout << "solution #" << cntr++ << " : " << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(eq[j] == i)
            cout << "1" << " | ";
            else cout << "0" << " | ";
        }
        cout << "\n-------------------------------" << endl;
    }
    cout << "\n\n"
         << endl;
    goto Backtrack; // once we printed anything, we go back to Backtrack to subtract column by 1 to find more solutions
}