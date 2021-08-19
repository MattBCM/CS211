#include <iostream>
using namespace std;

int main()
{
    int eq[8][8] = {0}, c = 0, r = 0, cntr = 1; // declaring variables and board
    eq[0][0] = 1; // first queen at the top left corner
Nc:
    c++; // add the column variable by 1
    if (c == 8)
        goto Print; // once the column reaches the end of the board, we print the board
    r = -1; // initialize row back to -1
Nr:
    r++; // add row by one
    if (r == 8)
        goto Backtrack; // if there is no solutions in the row, then we go to backtrack to substract column by 1

        /*Check test on whether the queen can be placed in the spot by the
        diagonal test and the row test using for loops */

        //ROW TEST
        for (int i = 0; i < c; i++)
        {
        if (eq[r][i] == 1)
            goto Nr; // goes back to Nr
        }
        //UP-DIAGONAL TEST    
        for (int i = 0; r - i >= 0 && c - i >= 0; i++)
        {
            if (eq[r - i][c - i] == 1)
                goto Nr; // goes back to Nr
        }
        //DOWN-DIAGONAL TEST
        for (int i = 0; r + i < 8 && c - i >= 0; i++)
        {
            if (eq[r + i][c - i] == 1)
                goto Nr; // goes back to Nr
        }
    eq[r][c] = 1; // places queen if no queens are in the way
    goto Nc; // goes back to Nc to add column by 1 and redo program

// if r = 8, we go to here to subtract column by 1 and find another solution in the column    
Backtrack:
    c--; // subtract c by 1
    if (c == -1)
        return 0; // if column reaches the end of the board, then there are no more solution, closing the program
    r = 0; // set r back to 0
    while (eq[r][c] != 1)
        r++; // keep adding row by 1 until eq[r][c] equals to 1
    eq[r][c] = 0; // we remove the queen at that spot
    goto Nr; // return back to Nr to continue moving down

//prints out the solution to the problem using nested for loop
Print:
    cout << "solution #" << cntr++ << " : " << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << eq[i][j] << " | ";
        }
        cout << "\n-------------------------------" << endl;
    }
    cout << "\n\n"
         << endl;
    goto Backtrack; // once we printed anything, we go back to Backtrack to subtract column by 1 to find more solutions
}