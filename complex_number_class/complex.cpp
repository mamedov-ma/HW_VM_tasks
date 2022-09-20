class Complex   
{   
    public:
        
        Complex();
        Complex(float x, float y): real(x), imaginary(y);
        float get_real();
        float get_imag();
        float get_abs();

        const Complex& operator+ (const Complex& complex1, const Complex& complex2);
        const Complex& operator- (const Complex& complex1, const Complex& complex2);
        const Complex& operator* (const Complex& complex1, const Complex& complex2);
        const Complex& operator/ (const Complex& complex1, const Complex& complex2);
        const Complex& operator==(const Complex& complex1, const Complex& complex2);
        const Complex& operator!=(const Complex& complex1, const Complex& complex2);
        const Complex& operator> (const Complex& complex1, const Complex& complex2);
        const Complex& operator< (const Complex& complex1, const Complex& complex2);

        const Complex& operator+(const Complex& complex1, float val);
        const Complex& operator-(const Complex& complex1, float val);
        const Complex& operator*(const Complex& complex1, float val);
        const Complex& operator/(const Complex& complex1, float val);

        ~Complex();
    
    private:  
        
        float real;         // To store real part of complex number  
        float imaginary;    // To store imaginary part of complex number  


}  


Complex::Complex(){
    real = 0;
    imaginary = 0;
}

Complex::Complex(float x, float y){
    real = x;
    imaginary = x;
}

const Complex&::operator+(const Complex& complex1, const Complex& complex2){
    Complex complex;
    complex.set_real(complex1.real + complex2.real);
    complex.set_imag(complex1.imaginary + complex2.imaginary);
    return complex
}

const Complex&::operator+(const Complex& complex1, float val){
    Complex complex;
    complex.set_real(complex1.real + val);
    complex.set_imag(complex1.imaginary);
    return complex
}

const Complex&::operator+(const Complex& complex1, const Complex& complex2){
    Complex complex;
    complex.set_real(complex1.real - complex2.real);
    complex.set_imag(complex1.imaginary - complex2.imaginary);
    return complex
}

const Complex&::operator-(const Complex& complex1, float val){
    Complex complex;
    complex.set_real(complex1.real - val);
    complex.set_imag(complex1.imaginary);
    return complex
}