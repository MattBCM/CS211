#include <iostream>
using namespace std;
void pnt(int x[],int &c);
bool isSafe(int x[], int col, int mnp[][3], int wmnp[][3]);

int main()
{
    int c = 0, sle[3] = {-1}, ct = 0; 

    int mp[][3] = {{0, 2, 1}, // assign male prefernces
                   {0, 2, 1}, 
                   {1, 2, 0}};

    int wp[][3] = {{2, 1, 0}, // assign woman preference
                   {0, 1, 2}, 
                   {2, 0, 1}}; 
                   
    while(c < 3){
        while(sle[c] < 3){ 
            sle[c]++; // add row
            if(sle[c] == 3){ // if row goes to 3
                sle[c] = -1; // reset back to -1
                c--; // go back a row
                if(c < 0) return 0; // if row is less than -1 (out of bound) then we close program
                break; // leave the while loop
            }
            if(isSafe(sle, c, mp, wp) == true){ // iff the safe function returns true
                c++; // go to next row
                if(c == 3) pnt(sle, ct); // if the column reaches 3, we print
                sle[c] = -1; // reset row back to -1
                if(c == -1) c = 2; 
            }
        }
    }
}

void pnt (int x[], int &c){ // print out the solution
    c++;
    cout << "solution #" << c << ": " <<endl;
    cout <<"Men:     Woman: " << endl;
    for(int i = 0; i < 3; i++){
        cout << i << "        " << x[i] <<endl;
    }
    cout << "\n\n";
}
bool isSafe(int x[], int col, int mnp[][3], int wmnp[][3]){
    //1. if the woman has already been assigned to some man
    for (int i = 0; i < col; i++)
    {
        if (x[col] == x[i])
            return false;
        //if the new-man's woman ranking is greater than the other man's ranking and the current
        //woman's man's ranking is greater than the other's ranking, then return false.
        if ((mnp[col][x[col]] > mnp[col][x[i]]) && (wmnp[x[i]][i] > wmnp[x[i]][col]))
            return false;
        //vice versa for the description above
        if ((wmnp[x[col]][col] > wmnp[x[col]][i]) && (mnp[i][x[i]] > mnp[i][x[col]]))
            return false;
    }
    return true;
}