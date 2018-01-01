#include <iostream>
#include "complex.h"

using namespace std;

int main() {

    char plus,i;

    complex x(1,2), y(3,4), z;
    double a,b;

    cout << "Please type a complex number in the form a+bi: ";
    cin.clear();
    cin >> a;
    cin >> b;
    cin >> i;
    //cin >> z;

    cout << endl << "The number typed was: " << a << b << endl;
    z=x+y;
    z.print();

    return 0;
}