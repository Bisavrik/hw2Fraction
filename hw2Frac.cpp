#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify()
    {
        int gcd_value = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_value;
        denominator /= gcd_value;

        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {} 

    void setNumerator(int num)
    {
        numerator = num;
        simplify();
    }

    void setDenominator(int denom)
    {
        if (denom == 0)
        {
            cout << "Denominator cannot be zero!" << endl;
            denominator = 1;
        }
        else
        {
            denominator = denom;
        }
        simplify();
    }

    int getNumerator() 
    {
        return numerator;
    }

    int getDenominator()
    {
        return denominator;
    }

    Fraction add( Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction subtract(Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction multiply(Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.simplify();
        return result;
    }

    Fraction divide(Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.simplify();
        return result;
    }
};

void printFraction(Fraction& f)
{
    cout << f.getNumerator() << "/" << f.getDenominator() << endl;
}

int main()
{
    Fraction f1, f2, result;


    f1.setNumerator(3);
    f1.setDenominator(4);

    f2.setNumerator(2);
    f2.setDenominator(5);

    cout << "f1: ";
    printFraction(f1);

    cout << "f2: ";
    printFraction(f2);

    result = f1.add(f2);
    cout << "Sum: ";
    printFraction(result);

    result = f1.subtract(f2);
    cout << "Difference: ";
    printFraction(result);

    result = f1.multiply(f2);
    cout << "Product: ";
    printFraction(result);

    result = f1.divide(f2);
    cout << "Quotient: ";
    printFraction(result);

    return 0;
}
