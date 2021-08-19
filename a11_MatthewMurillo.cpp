#include <iostream>
#include <cmath>
using namespace std;

class rat{
private:
    int n;
    int d;
public:
    //constructors

    //default constructors
    rat(){
        n = 0;
        d = 1;
    }
    // 2 parameter constructor
    rat(int i, int j){
        n = i;
        d = j;
        if((n%d == 0) || (d%n == 0)){
        lowest();
        }
    }

    //converstion constructor
    rat(int i){
        n = i;
        d = 1;
    }

    //accessor functions (usually set and get)
    int getN(){return n;}
    int getD(){return d;}

    void setN(int i){n = i;}
    void setD(int i){d = i;}

    // lowest terms for gcd
    void lowest(){
        int num = n;
        int dem = d;
        int gcd = 1;
        int l;

        if(num >= dem){ l = num; }
        else l = dem;

        for(int i = l; i >= 2; i--){
            if((num % i == 0) && (dem % i == 0)){
                gcd = i;
                break;
            }
        }

        num /= gcd;
        dem /= gcd;

        n = num;
        d = dem;
    }

/*
    rat operator+(rat r){
        rat t;
        t.n = (n * r.d) + (d * r.n);
        t.d = d*r.d;
        return t;

    }
*/
    friend ostream& operator<<(ostream& os, rat r);
    friend istream& operator>>(istream& is, rat r);
}; // end rat

ostream& operator<<(ostream& os, rat r){
    if(abs(r.n) >= r.d || r.n == 0){
        int x = (r.n/r.d);
        r.n = (r.n % r.d);
        if(r.n == 0){
            os<<x<<endl;
            return os;
        }
        r.lowest();
        os<<x<<" "<<r.n<<"/"<<r.d<<endl;
        return os;
    } 
    os<<r.n<<"/"<<r.d<<endl;
    return os;
}
istream& operator>>(istream& is, rat r){
    is>>r.n>>r.d;
    return is;
}

    rat operator+(rat a, rat b){
        rat t;
        t.setN((a.getN()*b.getD())+(a.getD()*b.getN()));
        t.setD(a.getD()*b.getD());
        t.lowest();
        return t;
    }
    rat operator-(rat a, rat b){
        rat t;
        t.setN((a.getN()*b.getD())-(a.getD()*b.getN()));
        t.setD(a.getD()*b.getD());
        t.lowest();
        return t;
    }
    rat operator*(rat a, rat b){
        rat t;
        t.setN(a.getN()*b.getN());
        t.setD(a.getD()*b.getD());
        t.lowest();
        return t;
    }
    rat operator/(rat a, rat b){
        rat t;
        t.setN(a.getN()*b.getD());
        t.setD(a.getD()*b.getN());
        t.lowest();
        return t;
    }

int main(){
rat x(1, 4);
cout << "---Addition--- \n\n" << "x+5:" << x + 5;
cout << "5+x: " << 5 + x << "\n";
cout <<"---Subtraction--- \n\n"<<"5-x: " <<5 - x;
cout <<"x-5: "<< x - 5 << "\n";
cout <<"---Multiplication---\n\n"<< "x*5: " << x*5;
cout <<"5*x: " <<5*x << "\n";
cout <<"---Division---\n\n" << "5/x: " <<5/x;
cout <<"x/5: "<<x/5 << "\n\n";
cout << "x: " << x;
}