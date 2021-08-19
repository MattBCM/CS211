#include <iostream>
using namespace std;
bool isSafe(int x[], int col); 
void pnt(int x[], int &y);

int main()
{
    int c = 0, cntr = 0, eq[8] = {-1}; // initialize everything to its values
    while (c < 8) // the column while loop will stop at 8
    {
        while (eq[c] < 8) // this will keep going until the row is at 8
        {
            eq[c]++; // add the row by one
            if (eq[c] == 8) // if the row is 8
            {
                eq[c] = 0; // initialize the row back to 0
                c--; // subtract the column by 1
                if (c == -1) // if we go beyond the back of the board
                    return 0; // close the program
                break; // get out of the row while loop
            }
            if (isSafe(eq, c) == true) // if the number passes the row and diagonal test
            {
            c++; // add row by one
            if (c == 8) // if the column equals to 8
            pnt(eq, cntr); // print out the board with the solution
            eq[c] = -1; // reset the row back to -1
            }
        }
    }
}
bool isSafe(int x[], int col)
{
    //ROW TEST
    for (int i = 0; i < col; i++) 
    {
        if (x[i] == x[col])
            return false;
    }
    //DIAGONAL TEST
    for (int i = 0; i < col; i++)
    {
        if ((col - i) == abs(x[col] - x[i]))
            return false;
    }
    return true;
}

//prints out the solution to the problem using nested for loop
void pnt(int x[], int &y)
{
    cout << "solution #" << ++y << " : " << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (x[j] == i) 
                cout << "1"
                     << " | ";
            else
                cout << "0"
                     << " | ";
        }
        cout << "\n-------------------------------" << endl;
    }
    cout << "\n\n"
         << endl;
}