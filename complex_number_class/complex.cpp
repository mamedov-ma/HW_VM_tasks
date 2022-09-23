#include"complex.h"

namespace complex_math{

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(float x)
{
    real = x;
    imag = 0;
}

Complex::Complex(float x, float y)
{
    real = x;
    imag = y;
}

Complex::Complex(const Complex& orig)
{
    real = orig.real;
    imag = orig.imag;
}

float Complex::get_real() const
{
    return real;
}

float Complex::get_imag() const
{
    return imag;
}

float Complex::get_abs() const
{
    return std::sqrt(real * real + imag * imag);
}

const Complex& Complex::operator=(const Complex& orig)
{
    real = orig.real;
    imag = orig.imag;
    return *this;
}

const Complex& Complex::operator++()
{
    real++;
    return *this;
}

const Complex& Complex::operator--()
{
    real --;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex res(real++, imag);
    return res;
}

Complex Complex::operator--(int)
{
    Complex res(real--, imag);
    return res;
}

Complex Complex::operator+(const Complex& complex)
{
    Complex res(real + complex.real, imag + complex.imag);
    return res; 
}

Complex Complex::operator+(float val)
{
    Complex res(real += val, imag);
    return res;
}

Complex Complex::operator-(const Complex& complex)
{
    Complex res(real - complex.real, imag - complex.imag);
    return res;
}

Complex Complex::operator-(float val)
{
    Complex res(real - val, imag);
    return res;
}

Complex Complex::operator* (const Complex& complex)
{
    Complex res(real * complex.real - imag * complex.imag, real * complex.imag + imag * complex.real);
    return res;
}

Complex Complex::operator* (float val)
{
    Complex res(real * val, imag * val);
    return res;
}

Complex Complex::operator/ (const Complex& complex)
{
    float denominator = complex.real * complex.real + complex.imag * complex.imag;
    Complex res((real * complex.real + imag * complex.imag) / denominator, (imag * complex.real - real * complex.imag) / denominator);
    return res;
}

Complex Complex::operator/ (float val)
{
    Complex res(real / val, imag / val);
    return res;
}

bool Complex::operator==(const Complex& complex)
{
    return (std::abs(real - complex.real) < eps) && (std::abs(imag - complex.imag) < eps);
}

bool Complex::operator!=(const Complex& complex)
{
    return (std::abs(real - complex.real) > eps) || (std::abs(imag - complex.imag) > eps);
}

bool Complex::operator> (const Complex& complex)
{
    return this->get_abs() > complex.get_abs();
}

bool Complex::operator< (const Complex& complex)
{
    return this->get_abs() < complex.get_abs();
}


std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if(complex.get_imag() < 0)
    { 
        out << complex.get_real() << complex.get_imag() << "j";
        return out;
    }
    else
    {
        out << complex.get_real() << "+" << complex.get_imag() << "j";
        return out;
    }
}


} // namespace
