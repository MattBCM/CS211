#include <iostream>
using namespace std;

bool isSafe(int x[], int col); 
void pnt(int x[], int &y);
void sol(int n);

int main()
{
    int n;
    cout << "please enter a size for the board: ";
    cin >> n;
    for(int i = 0; i <= n; i++){
        sol(i);
    }
}   

void sol(int n)
{
    int* eq = new int [n];
    eq[0] = -1;
    int c = 0, cntr = 0;
    while (c < n) // the column while loop will stop at n
    {
        while (eq[c] < n) // this will keep going until the row is at n
        {
            eq[c]++; // add the row by one
            if (eq[c] == n) // if the row is n
            {
                eq[c] = 0; // initialize the row back to 0
                c--; // subtract the column by 1
                if (c == -1){ // if we go beyond the back of the board
                    cout << "there are " << cntr << " solutions to the " << n << " queens problem" <<endl;
                    delete [] eq;
                    return; // close the program
                }
                break; // get out of the row while loop
            }
            if (isSafe(eq, c) == true) // if the number passes the row and diagonal test
            {
            c++; // add row by one
            if (c == n) // if the column equals to n
            cntr++;
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

