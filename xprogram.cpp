#include <iostream>
using namespace std;

int main(){
int x;
cout << "please enter a positive odd number: ";
cin >> x;

while(x % 2 == 0 || x < 0){
    cout << "Invalid number. Please enter another number: ";
    cin >> x;
}

for(int r = 0; r < x; r++){
    for(int c = 0; c < x; c++){
        if(r == c || (r + c) == x-1){
            if(c > x/2) cout << "x";
            if(c < x/2) cout << "+";
            if(c == x/2) cout << "*";
        }
        else cout << " ";
    }
    cout << "\n";
}
}