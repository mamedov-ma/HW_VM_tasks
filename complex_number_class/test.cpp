#include <iostream>
#include"complex.h"
using namespace std;


int main()
{

    Complex a(5, 7), b, c; 
    b = a++;
    c = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}