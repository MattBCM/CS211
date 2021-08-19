#include <iostream>
using namespace std;
bool perfectSquare(int a); // the bool function to prototype it
int main(){
    int i = 1, ans = 0; // this is the counter for the while loop
    bool prftSqr = true; // this is the checker for the while loop on whether the last 2 digits of ans is odd

    while(prftSqr){ //while loop continues while the function PerfectSquare doesnt go with the condition
        prftSqr = perfectSquare(i); // the bool goes true when it dont fit the condition, while it goes false when it does
        i++; //iterates i to add by 1 each time

    }
    return 0;
}


bool perfectSquare(int a){
    int b = (a*a);
    if(b % 2 != 0 && (b / 10)%2 != 0){
           cout << "the perfect square who's last 2 digits are odd is " << a << " with " << b <<endl;
           return false; // ends the while loop if the square of i is a perfect square with the requirement
       }
    else return true;// continues the while loop adding one
}

/*In this assignment, I see that there is no perfect square that would have the last 2 numbers odd. This is why when 
you go run the program, it gives you a large number, but the perfect square is wrong in some sort of way. It would be outputed as
negative, which doesnt make sense as perfect squares are always positive. This goes for show that there is no perfect square with
the last 2 numbers as odd. this makes me now understand how to check using an infinite loop until it returns false.
*/