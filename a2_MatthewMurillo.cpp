#include <iostream>
#include <string>
using namespace std;

string add(string string1, string string2); // prototyping the add function, which returns a string

int main(){
string x, y; // declaring 2 string functions
while(true){ // always goes into a loop
    cout << "please input one large numbers: ";
    cin >> x; // enters 2 numbers which is stored in the string, not actually numbers
    if(x == "done"){
        cout << "thank you for trying this out!" <<endl; // ends the program if the user enters done on either x or y string
        return 0;
    }
    cout << "please enter another large number: ";
    cin >> y;
    
cout << "the 2 numbers added up is: " << add(x, y) << "\n" <<endl; // prints out the function "add" which adds the numbers
}
return 0;
}

string add(string str1, string str2){
string str, s1 = str1, s2 = str2; // stores the answer "str", "s1" is the first string and "s2" is the second string
int bgrLgth = str1.length(), smlLgth = str2.length(), carry = 0; // integers are the length of the string to be used in the for loops

// this swaps the numbers around if the second number inputed is greater than the first number inputed
if(smlLgth > bgrLgth){ 
    int temp = bgrLgth;
    string temp2 = s1;
    s1 = s2; 
    s2 = temp2;
    bgrLgth = smlLgth;
    smlLgth = temp;
}

//this function adds '0' to the front of "s2" so it can match the length of "s1" 
while(smlLgth != bgrLgth){
    s2.insert(0, 1, '0');
    smlLgth++;
} 

//this loops until the end of the small length adding the 2 numbers together
for(int i = smlLgth-1; i >= 0; i--){
    int sum = ((s1[i]-48) + (s2[i]-48) + carry); // adds the numbers using ascii numbers, 48 representing '0' since the numbers are relatively in the same area. carry would be either 0 or 1 if the 2 numbers added is greater than 0
    str.insert(0, 1, (sum % 10)+48); //inserts "sum" into a string, which is going to be the output, in the very front of the string, place 0,1.
    carry = sum / 10; // if the 2 numbers added is greater than 10, it gets stored into carry as 1
}
// this is only if carry = 1 at the very end of the for loop, adding by 1
if(carry == 1){
    str.insert(0,1, '1');
}
return str; // returns to the user the string "str", the solution

}

/* In this assignment, I see that we have to use ASCII numbers in order to give the illusion that the numbers are adding up with integers.
using strings and using string functions in order to insert characters and have the for loop end at a point, I was able to create a function
to add up all the numbers in each place. using the ascii letters converted to integer numbers, we add those up and then add it with '0' to
return a number and then insert it to a string. This got me learning and remembering the functions to strings and cstrings as there are specific
ones to the specific tasks.
*/