#include <iostream>
#include"complex.h"
using namespace std;


int main()
{

    Complex a, b, c;
    a.set_real(5);
    a.set_imag(7);
    b = a;
    c = a + b;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}