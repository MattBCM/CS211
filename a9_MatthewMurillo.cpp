#include <iostream>
using namespace std;

typedef double (*FUNC)(double); // create FUNC function that accepts double as parameter
double integrate(FUNC f, double a, double b); // function to integrate
double line(double x); // function for f(x) = x
double square(double x); // function for f(x) = x^2
double cube(double y);// function for f(x) = x^3

int main(){
    cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x) = x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x) = x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
}

double line(double x){
    return x;
}
double square(double x){
    return x*x;
}
double cube(double x){
    return x*x*x;
}
double integrate(FUNC f, double a, double b){
    double sum = 0, delta = .0001, x = a; // 
    while(x < b){
        sum += f(x)*delta; // adds the sum to find out the area under the curve
        x += delta; // increses x by itself plus delta
    }
return sum; // returns a double 
}
