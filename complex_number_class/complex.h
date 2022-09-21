#include <iostream>
#include <cmath>
using namespace std;

#define eps 10-7

class Complex {   
   
    private:  

        float real;    // To store real part of complex number  
        float imag;    // To store imaginary part of complex number 


    public: 

        Complex();
        Complex(float x, float y);
        Complex(const Complex&);
        
        void set_real(float n);
        void set_imag(float n);
        float get_real() const;
        float get_imag() const;
        float get_abs() const;

        const Complex &operator=(const Complex&);

        Complex operator+ (const Complex&);
        Complex operator+ (float);

        Complex operator- (const Complex&);
        Complex operator- (float);
        
        Complex operator* (const Complex&);
        Complex operator* (float);

        Complex operator/ (const Complex&);
        Complex operator/ (float);
        
        bool operator==(const Complex&);
        bool operator!=(const Complex&);
        bool operator> (const Complex&);
        bool operator< (const Complex&);
};

ostream& operator<<(ostream&, const Complex&);
