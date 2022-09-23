#include <iostream>
#include <cmath>

#define eps 10e-7       // Сomparison accuracy

namespace complex_math{

class Complex {   
   
    private:  

        float real;    
        float imag;    


    public: 

        Complex();                         
        Complex(float x);                   
        Complex(float x, float y);          
        Complex(const Complex&);            

        float get_real() const;
        float get_imag() const;
        float get_abs() const;               

        const Complex& operator=(const Complex&);   

        // unary operators decloration
        const Complex& operator++();   
        const Complex& operator--();  
        Complex operator++(int);       
        Complex operator--(int);      

        // ariphmetic operators decloration
        const Complex operator+ (const Complex&);
        const Complex operator+ (float);

        const Complex operator- (const Complex&);
        const Complex operator- (float);
    
        const Complex operator* (const Complex&);
        const Complex operator* (float);
        
        const Complex operator/ (const Complex&);
        const Complex operator/ (float);
        
        // logical operators decloration
        bool operator==(const Complex&);   
        bool operator!=(const Complex&);
        bool operator> (const Complex&);
        bool operator< (const Complex&);

        friend std::ostream& operator<<(std::ostream&, const Complex&);    

};



} // namespace
