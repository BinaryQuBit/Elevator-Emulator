// Name: Amandip Padda
// SID: 200455829
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// STRUCT
struct Complex
{
    double real;
    double imag;
};

// prototypes as per document
void add(Complex z1, Complex z2, Complex *result);
void subtract(Complex z1, Complex z2, Complex *result);
void multiply(Complex z1, Complex z2, Complex *result);
void divide(Complex z1, Complex z2, Complex *result);

int main()
{
    char sel;                           // Operator selection
    Complex complex1, complex2, result; // declare inputs

    cerr << "Complex calculator" << endl;
    cerr << "Type a letter to specify the arithmetic operator (A, S, M, D)" << endl;
    cerr << "followed by two complex numbers expressed as pairs of doubles." << endl;
    cerr << "Type Q to quit." << endl;

    while (true)
    {
        cerr << "Enter exp: ";

        if (!(cin >> sel)) // no input of operator error
        {
            if (cin.eof())
            {
                break;
            }
            cout << "error code: 2: missing arguments" << endl;
        }

        if (sel == 'Q' || sel == 'q') // quit functionality
        {
            string extra;
            getline(cin, extra);
            if (!extra.empty())
            {
                cout << "error code: 3: extra arguments" << endl;
            }
            else
            {
                break;
            }
        }

        if (!(cin >> complex1.real >> complex1.imag >> complex2.real >> complex2.imag)) // error for no input of numbers
        {
            cout << "error code: 2: missing arguments" << endl;
            break;
        }

        string extra; // extra arguments error with no position
        getline(cin, extra);
        if (!extra.empty() && extra.find_first_not_of(" \t") != string::npos)
        {
            cout << "error code: 3: extra arguments" << endl;
            break;
        }

        if (sel == 'A' || sel == 'a') // addition
        {
            add(complex1, complex2, &result);
            cout << result.real << " + j " << result.imag << endl;
        }
        else if (sel == 'S' || sel == 's') //substraction
        {
            subtract(complex1, complex2, &result);
            if (result.imag < 0)
            {
                result.imag = abs(result.imag);
                cout << result.real << " - j " << result.imag << endl;
            }
            else
            {
                cout << result.real << " + j " << result.imag << endl;
            }
        }
        else if (sel == 'M' || sel == 'm') //multiply
        {
            multiply(complex1, complex2, &result);
            cout << result.real << " + j " << result.imag << endl;
        }
        else if (sel == 'D' || sel == 'd') //divide
        {
            divide(complex1, complex2, &result);
            cout << result.real << " + j " << result.imag << endl;
        }
        else
        {
            cout << "error code: 1: illegal command" << endl; //last else to handle illegal command
            break;
        }
    }

    return 0;
}

// Function definitions
void add(Complex z1, Complex z2, Complex *result)
{
    result->real = z1.real + z2.real;
    result->imag = z1.imag + z2.imag;
}

void subtract(Complex z1, Complex z2, Complex *result)
{
    result->real = z1.real - z2.real;
    result->imag = z1.imag - z2.imag;
}

void multiply(Complex z1, Complex z2, Complex *result)
{
    result->real = z1.real * z2.real - z1.imag * z2.imag;
    result->imag = z1.real * z2.imag + z1.imag * z2.real;
}

void divide(Complex z1, Complex z2, Complex *result)
{
    double denom = z2.real * z2.real + z2.imag * z2.imag;
    result->real = (z1.real * z2.real + z1.imag * z2.imag) / denom;
    result->imag = (z1.imag * z2.real - z1.real * z2.imag) / denom;
}
