#include <iostream>
#include <cmath>
using namespace std;

#define eps 10-7       // Сomparison accuracy


class Complex {   
   
    private:  

        float real;    // To store real part of complex number  
        float imag;    // To store imaginary part of complex number 


    public: 

        Complex();                           // default constructor
        Complex(float x);                    // constructor with one argument 
        Complex(float x, float y);           // constructor with two arguments
        Complex(const Complex&);             // copy constructor
        
        float get_real() const;
        float get_imag() const;
        float get_abs() const;               

        const Complex& operator=(const Complex&);   // assignment operator decloration

        // unary operators decloration
        const Complex& operator++();   // Prefix increment operator
        const Complex& operator--();   // Prefix decrement operator
        Complex operator++(int);       // Postfix increment operator
        Complex operator--(int);       // Postfix decrement operator

        // ariphmetic operators decloration
        Complex operator+ (const Complex&);
        Complex operator+ (float);

        Complex operator- (const Complex&);
        Complex operator- (float);
    
        Complex operator* (const Complex&);
        Complex operator* (float);
        
        Complex operator/ (const Complex&);
        Complex operator/ (float);
        
        // logical operators decloration
        bool operator==(const Complex&);    
        bool operator!=(const Complex&);
        bool operator> (const Complex&);
        bool operator< (const Complex&);
};

ostream& operator<<(ostream&, const Complex&);    //output operator decloration (NOT IN Complex)!
