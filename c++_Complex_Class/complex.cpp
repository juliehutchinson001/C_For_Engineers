#include <iostream>
#include <cmath>
#include "complex.h"

complex::complex() {
    real=0.0;
    imag=0.0;

    return;

}

complex::complex(double a) {
    real = a;
    imag = 0.0;

    return;

}

complex::complex(double a, double b) {
    real=a;
    imag=b;

    return;

}

complex::complex(int a, int b) {
    real=static_cast<double> (a);
    imag=static_cast<double> (b);

    return;

}

void complex::print() const {
        std::cout << *this;
 /*   if(imag<0)
        if (imag==-1)
            std::cout << real << "-i";
        else
            std::cout << real << imag << "i";
    else
         if (imag==0)
            std::cout << real;
        else
            if (imag==1)
                std::cout << real << "+i";
            else
                std::cout << real << "+" << imag << "i";
*/
    return;

}

void complex::set(double a, double b) {
    real=a;
    imag=b;
    return;

}

void complex::set(int a, int b) {
    real=static_cast<double> (a);
    imag=static_cast<double> (b);

    return;

}

double complex::getReal() const {
    return real;
}

double complex::getImag() const{
    return imag;
}

void complex::get(double& x,double& y) const {
    x=real;
    y=imag;
    return;
}


complex complex::operator+ (double& x){
    return complex(real+x,imag);
}

complex complex::operator+(complex &x) {
    return complex(real + x.real, imag + x.imag);
}

complex complex::operator+=(complex &x) {
    *this= complex(real + x.real, imag + x.imag);
    return *this;
}

complex complex::operator+=(int &x) {
    *this= complex(real + x, imag);
    return *this;
}

complex complex::operator++ (int x) {
    complex temp;
    temp=*this;
    this->real=this->real+1;
    return temp;
}

complex complex::operator++ () {
    return complex(++real,imag);
}


complex complex::operator- (double& x){
    return complex(real-x,imag);
}

complex complex::operator-(complex &x) {
    return complex(real - x.real, imag - x.imag);
}

complex complex::operator-=(complex &x) {
    *this= complex(real - x.real, imag - x.imag);
    return *this;
}

complex complex::operator-=(double &x) {
    *this= complex(real - x, imag);
    return *this;
}

complex complex::operator-- (int x) {
    complex temp;
    temp=*this;
    this->real=this->real-1;
    return temp;
}

complex complex::operator-- () {
    return complex(--real,imag);
}

complex complex::operator*(complex &x) {
    return complex((real * x.real) - (imag * x.imag), (real * x.imag) + (imag * x.real));
}

complex complex::operator*(double &x) {
    return complex((real * x), (imag * x));
}

complex complex::operator*=(complex &x) {
    *this=complex((real * x.real) - (imag * x.imag), (real * x.imag) + (imag * x.real));
    return *this;
}

complex complex::operator*=(double &x) {
    *this=complex((real * x), (imag * x));
    return *this;
}

complex complex::operator/(complex &x) {
    complex c = x.conj();
    double n = x.norm();

    return ((*this) * c) / (n * n);
}

complex complex::operator/=(complex &x) {
    complex c = x.conj();
    double n = x.norm();

    *this=((*this) * c) / (n * n);
    return *this;
}

complex complex::operator/(double d) {
    return complex(real / d, imag / d);
}

complex complex::operator/=(double d) {
    *this = complex(real / d, imag / d);
    return *this;
}

std::istream &operator>>(std::istream &in, complex &c)     //input
{
    char plus;
    char i;
    in >> c.real >> plus >> c.imag >> i;
    return in;
    //return c.a >> c.b;
}

std::ostream &operator<<(std::ostream &out, complex c)     //output
{
    if(c.imag<0)
        if (c.imag==-1)
            out << c.real << "-i";
        else
            out << c.real << c.imag << "i";
    else
         if (c.imag==0)
            out << c.real;
        else
            if (c.imag==1)
                out << c.real << "+i";
            else
                out << c.real << "+" << c.imag << "i";
    return out;

}

void complex::operator=(const complex &c) {
    real=c.real;
    imag=c.imag;

    return;
}

bool complex::operator==(complex &c) {
    return ((real==c.real)&&(imag==c.imag)) ? 1 : 0;
}

bool complex::operator!=(complex &c) {
    return ((real==c.real)&&(imag==c.imag)) ? 0 : 1;
}

complex complex::conj() const {
    return complex(real,-imag);
}

double complex::norm() const {
    return sqrt(real * real + imag * imag);
}


double complex::modulus() const {
    return sqrt((real*real)+(imag*imag));
}
