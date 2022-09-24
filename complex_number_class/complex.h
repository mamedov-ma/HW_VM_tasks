#include <iostream>
#include <cmath>


namespace complex_math
{

struct Complex
{
    const float EPSILON = 10e-7;    // Сomparison accuracy

    float real;    
    float imag;    

    Complex();                                           
    Complex(float x, float y);          
    Complex(const Complex&);            

    float get_abs() const;               

    const Complex& operator=(const Complex&);   

    const Complex& operator++();   
    const Complex& operator--();  
    Complex operator++(int);       
    Complex operator--(int);      

    Complex operator+ (const Complex&) const;
    Complex operator+ (float) const;
    Complex operator+ () const;

    Complex operator- (const Complex&) const;
    Complex operator- (float) const;
    Complex operator- () const;

    Complex operator* (const Complex&) const;
    Complex operator* (float) const;
    
    Complex operator/ (const Complex&) const;
    Complex operator/ (float) const;
    
    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;
    bool operator> (const Complex&) const;
    bool operator< (const Complex&) const;
};

} // namespace complex_math
