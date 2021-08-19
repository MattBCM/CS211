#include <iostream>
using namespace std;
void pnt(int x[], int &y);
bool isSafe(int x[], int col, int h[][8]);

int main()
{
    int c = 0, cntr = 0, crs[8] = {0}, h[][8] = { {-1, 0, 1, 0, 1, 2, 0, 3}, 
                                                  {-1,-1,-1, 1, 2, 4, 3, 4}, 
                                                  {-1,-1,-1, 2, 3,-1, 4, 5}, 
                                                  {-1,-1,-1,-1,-1,-1,-1, 6}, 
                                                  {-1,-1,-1,-1,-1,-1,-1,-1}}; // initialize everything to its values
    while (c < 8) // the column while loop will stop at 8
    {
        while (crs[c] < 9) // this will keep going until the row is at 8
        {
            crs[c]++; // add the row by one
            if (crs[c] == 9) // if the row is 8
            {
                crs[c] = 0; // initialize the row back to 0
                c--; // subtract the column by 1
                if (c == -1) // if we go beyond the back of the board
                    return 0; // close the program
                break; // get out of the row while loop
            }
            if (isSafe(crs, c, h) == true) // if the number passes the row and diagonal test
            {
            c++; // add row by one
            if (c == 8) // if the column equals to 8
            pnt(crs, cntr); // print out the board with the solution
            crs[c] = 0; // reset the row back to 0
            }
        }
    }
}
bool isSafe(int x[], int col, int h[][8])
{
    for(int i = 0; i < 5; i++){
        //checks if there are any corresponding numbers in the placements using the helper array
        if((x[h[i][col]] == (x[col]+1)) || (x[h[i][col]] == (x[col] -1)) || (x[h[i][col]]==x[col])){ 
            return false;}
    }
    for(int j = 0; j < col; j++){
        if(x[j] == x[col]) // if a number is already in the array, return false
        return false;
    }
return true; // if nothing fails, then return true
}

//prints out the solution to the problem
void pnt(int x[], int &y)
{
    cout << "solution #" << ++y << " : " << endl;
    cout << "  " << x[1] << " " << x[2] << "  " <<endl;
    cout << x[0] << " " << x[3] << " " << x[4] << " " << x[5] << endl;
    cout << "  " << x[6] << " " << x[7] << "  " <<endl;
cout << "\n";
}