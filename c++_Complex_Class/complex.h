#ifndef COMPLEX_H
#define COMPLEX_H


class complex {

public:
    complex();
    complex(double a);
    complex(double a,double b);
    complex(int a,int b);
    void print() const;
    void set(double a=0,double b=0);
    void set(int a=0,int b=0);
    double getReal() const;
    double getImag() const;
    void get(double&,double&) const;

    complex operator+ (double&);
    complex operator+ (complex&);
    complex operator+= (complex&);
    complex operator+= (int&);
    complex operator++ (int);
    complex operator++ ();
    complex operator- (double&);
    complex operator- (complex&);
    complex operator-= (complex&);
    complex operator-= (double&);
    complex operator-- (int);
    complex operator-- ();
    complex operator* (complex&);
    complex operator* (double&);
    complex operator*= (complex&);
    complex operator*= (double&);
    complex operator/ (complex&);
    complex operator/= (complex&);
    complex operator/= (double);
    complex operator/ (double);
    void operator= (const complex&);
    bool operator== (complex&);
    bool operator!=(complex &c);
    friend std::istream &operator>> (std::istream &in, complex& c);
    friend std::ostream &operator<<(std::ostream &out, complex c);

    complex conj() const;
    double norm() const;
    double modulus() const;

private:
    double real;
    double imag;
};

#endif // COMPLEX_H
