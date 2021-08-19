#include <iostream>
using namespace std;

bool validSolution(int x[], int size);
void print(int x[], int &counter);

int main(){
int eq[8] = {0}, c = 0, cntr = 1; // initializing the variables

for(int i0 = 0; i0 < 8; i0++){
    for(int i1 = 0; i1 < 8; i1++){
        for(int i2 = 0; i2 < 8; i2++){
            for(int i3 = 0; i3 < 8; i3++){
                for(int i4 = 0; i4 < 8; i4++){
                    for(int i5 = 0; i5 < 8; i5++){
                        for(int i6 = 0; i6 < 8; i6++){
                            for(int i7 = 0; i7 <8; i7++){
                                // setting the number of the array to be the number of the array
                                    eq[0] = i0;
                                    eq[1] = i1;
                                    eq[2] = i2;
                                    eq[3] = i3;
                                    eq[4] = i4;
                                    eq[5] = i5;
                                    eq[6] = i6;
                                    eq[7] = i7;
                                    if(validSolution(eq, 8)){ //checks whether the solution is a valid solution, returning true or false
                                        print(eq, cntr); // print function printing the chess board
                                    }
                            }
                        }
                    }
                }
            }
        }
    }
}

}

bool validSolution (int x[], int size){
        for (int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){ // nested for loop which checks until the value of i, which keeps increasing
        if (x[j] == x[i]) // if the value of one array value is the same as another, that means row test failed
            return false; // returns false to the boolean function
        //DIAGONAL TEST    
            if ((i - j) == abs(x[j] - x[i])) 
            return false; // returns false to the boolean function
            }
        }
        return true;
}
void print(int x[], int &counter){
    cout << "solution #" << counter++ << " : " << endl; // coutner to the solution
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(x[j] == i) // if the value inside the array equals to the row in the nested loop, then print out 1, else a 0
            cout << "1" << " | ";
            else cout << "0" << " | ";
        }
        cout << "\n-------------------------------" << endl; // spacing for the problem
    }
    cout << "\n\n"
         << endl;
}