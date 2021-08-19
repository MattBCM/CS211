#include <iostream>
using namespace std;
void move(char F, char T, char E, int n);

int main(){
    char A = 'A', B = 'B', C = 'C';
    int n = 3;
    move(A, B, C, n);
}

void move(char F, char T, char E, int n){
    if(n == 1){ // if number n reaches 1, the top ring
        cout << "Transfer ring " << n << " from tower " << F << " to tower " << T <<endl; // bring first ring to the T tower
        return;
    }
    move(F, E, T, n-1); // recalls the function, moving all the smaller tiles (n-1) from the beginning tower to the extra tower
    cout << "Transfer ring " << n << " from tower " << F << " to tower " << T <<endl; // prints out the move
    move(E, T, F, n-1); // when the largest tile moves to the destination tower, move all the other tiles from E tower to T tower
    return; // closes function
}