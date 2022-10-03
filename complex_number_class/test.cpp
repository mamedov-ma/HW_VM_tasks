#include "complex.h"

using namespace complex_math;


void  print_log(bool state, int n)
{
    if(!state)
    {  
        std::cout << "!!! FAILED test " << n << std::endl;
        exit(EXIT_FAILURE);
    }
     
    std::cout << "passed test " << n << std::endl;
}  

void Test1()
{
    Complex a;
    Complex c(0,0);
    print_log((a == c), 1);
}

void Test2()
{
    Complex a(1, 2);
    Complex b = a;
    print_log(a != b, 2);   
}

void Test3()
{
    Complex a(1, 2);
    Complex b;
    b = a;
    print_log(a == b, 3);
}

void Test4()
{
    Complex a(1, 2);
    Complex b;
    b = a;
    print_log(a == b, 4);
}

void Test5()
{
    Complex a(0, 0);
    print_log((a.get_abs() - 0 < a.EPSILON) & (a.real - 0 < a.EPSILON) & (a.imag - 0 < a.EPSILON), 5);
}

void Test6()
{
    Complex a(3, 4);
    print_log((a.get_abs() - 5 < a.EPSILON) & (a.real - 3 < a.EPSILON) & (a.imag - 4 < a.EPSILON), 6);
}

void Test7()
{
    Complex a(-3, -4);
    print_log((a.get_abs() - 5 < a.EPSILON) & (a.real + 3 < a.EPSILON) & (a.imag + 4 < a.EPSILON), 7);
}

void Test8()
{
    Complex a(3, 4);
    Complex b = a++;
    a--;
    print_log(a == b, 8);
}

void Test9()
{
    Complex a(3, 4);
    Complex b = ++a;
    print_log(a == b, 9);
}

void Test10()
{
    Complex a(3, 4);
    Complex b = --a;
    print_log(a == b, 10);
}

void Test11()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c = b + b;
    print_log(a == c, 11);
}

void Test12()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c = a - b;
    print_log(b == c, 12);
}

void Test13()
{
    Complex a(3, 4);
    Complex b(2, 4);
    b = b + 1;
    print_log(b == a, 13);
}

void Test14()
{
    Complex a(3, 4);
    Complex b(2, 4);
    a = a - 1;
    print_log(b == a, 14);
}

void Test15()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c(0, 16);
    print_log((a * b) == c, 15);
}

void Test16()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c(2, 0);
    print_log((a / b) == c, 16);
}

void Test17()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c(2, 0);
    print_log((a / b) == c, 17);
}

void Test18()
{
    Complex a(4, 4);
    Complex b(2, 2);
    Complex c = a / 2;
    print_log(b == c, 18);
}

void Test19()
{
    Complex a;
    Complex b;  
    print_log(a == b, 19);
}

void Test20()
{
    Complex a(0, 1);
    Complex b(1, 0);
    print_log(a != b, 20);
}

void Test21()
{
    Complex a(0, 0);
    Complex b(1, 0);
    print_log((a < b) & (b > a), 21);
}

void Test22()
{
    Complex a(0, 0);
    Complex b(0, 1);
    print_log((a < b) & (b > a), 22);
}

void Test23()
{
    Complex a(3, 4);
    Complex b = +a;
    a = -a;
    print_log(std::abs(a.real + b.real) < a.EPSILON, 23);
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();
    Test13();
    Test14();
    Test15();
    Test16();
    Test17();
    Test18();
    Test19();
    Test20();
    Test21();
    Test22();
    Test23();
    
    return EXIT_SUCCESS;
}

