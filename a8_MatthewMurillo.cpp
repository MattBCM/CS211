#include <iostream>
using namespace std;
void pnt(int q[], int &y);
bool isSafe(int x[], int col);

int main(){
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

void pnt(int q[], int &y){
    int i, j, k, l; // defines variables
    typedef char box[5][7]; // creates box 

    box bb, wb, *board[8][8];
    // this is the black queen
    box bq = {{'\xdb',' ', '\xdb', ' ', '\xdb', ' ', '\xdb'},
          {'\xdb',' ', '\xdb', ' ', '\xdb', ' ', '\xdb'},
          {'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
          {'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'},
          {'\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb', '\xdb'}};

    // this is the white queen
    box wq = {{' ', '\xdb', ' ' , '\xdb', ' ', '\xdb', ' '},
            {' ', '\xdb', ' ' , '\xdb', ' ', '\xdb', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    
    // fill in bb = black box and wb = white box
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = '\xdb';
        }
    }
// fill board with pointers to bb and wb in alternate positions
for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
        if((i+j)%2 == 0) board[i][j] = &wb; // if i+j is even, assign the board[i][j] the address of wb
        else board[i][j] = &bb; // if odd, assign the address of bb
    }
}

for(int i = 0; i < 8; i++){
    if((q[i] + i)%2 == 0) board[q[i]][i] = &wq; // if the row of solution + col of solution is even, replace the piece of the board with a white queen
    else board[q[i]][i] = &bq; // else replace a piece with a black queen
}

// print the board with pointers in the array board
cout << "solution #" << ++y << " : " << endl;
// print the upper level
cout << "   ";
for(int i = 0; i < 7*8; i++){
    cout << '_'; 
}
cout << endl;

// now print the board
for(int i = 0; i < 8; i++){
    for(int k = 0; k < 5; k++){
        cout << "   " << char(179);
        for(int j = 0; j < 8; j++){
            for(int l = 0; l < 7; l++){
                cout << (*board[i][j])[k][l]; // dereferences the pointer to the address of either a black box, white box, white queen or black queen
            }
        }
        cout << char(179) << endl; // at end of line print bar and then new line
    }
    cout << "   ";
    for(int i = 0; i < 7 * 8; i++){
        cout << char(196); // prints bottom border
    }
    cout << endl;
}
cout << "\n"; // spaces board out
}

bool isSafe(int x[], int col)
{
    //ROW TEST
    for (int i = 0; i < col; i++) 
    {
        if (x[i] == x[col]) // if the array already contains the number, return false
            return false;
    }
    //DIAGONAL TEST
    for (int i = 0; i < col; i++)
    {
        if ((col - i) == abs(x[col] - x[i])) // if column - i equals to absolute value of the row, then they are diagonal and false
            return false;
    }
    return true; // if these test fails, then we return true and a solution is made
}