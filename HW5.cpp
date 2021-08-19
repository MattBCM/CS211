#include <iostream>
#include <cmath>
using namespace std;

bool solve(int x[], int col, int &y);
bool isSafe(int x[], int col);
void pnt(int x[], int &y);

int main()
{
    int eq[8] = {-1}, c = 0, cntr = 0; // declaring variables and board
    eq[0] = -1; // first queen at the top left corner
    if(solve(eq, 0, cntr) == false){
        cout << "no solution" <<endl;
    }
}
bool solve(int x[], int col, int &y){
    if (col == 8){
        pnt(x, y); // once the column reaches the end of the board, we print the board
        return true;
    }
    bool res = false;
    for(int i = 0; i < 8; i++){
    x[col] = i;
        if(isSafe(x, col) == true){
            res = solve(x, col +1, y);
            x[col+1] = 0;
        }
    }
 return res;
}

bool isSafe(int x[], int col){
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
void pnt(int x[], int &y){
    cout << "solution #" << ++y << " : " << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(x[j] == i)
            cout << "1" << " | ";
            else cout << "0" << " | ";
        }
        cout << "\n-------------------------------" << endl;
    }
    cout << "\n\n"
         << endl;
     // once we printed anything, we go back to Backtrack to subtract column by 1 to find more solutions
}