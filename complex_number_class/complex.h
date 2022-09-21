#include <iostream>
#include <cmath>
using namespace std;

#define eps 10-7       // Сomparison accuracy


class Complex {   
   
    private:  

        float real;    // To store real part of complex number  
        float imag;    // To store imaginary part of complex number 


    public: 

        Complex();                           //default constructor
        Complex(float x, float y);           //constructor with arguments
        Complex(const Complex&);             //copy constructor
        
        void set_real(float n);                 
        void set_imag(float n);
        float get_real() const;
        float get_imag() const;
        float get_abs() const;               

        const Complex &operator=(const Complex&);   // = operator overloading

        // ariphmetic operators overloading
        Complex operator+ (const Complex&);
        Complex operator+ (float);

        Complex operator- (const Complex&);
        Complex operator- (float);
    
        Complex operator* (const Complex&);
        Complex operator* (float);
        
        Complex operator/ (const Complex&);
        Complex operator/ (float);
        
        // logical operators overloading
        bool operator==(const Complex&);    
        bool operator!=(const Complex&);
        bool operator> (const Complex&);
        bool operator< (const Complex&);
};

ostream& operator<<(ostream&, const Complex&);    //output overloading (NOT IN Complex)!
