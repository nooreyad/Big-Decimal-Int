
#ifndef BIG_DECIMAL_INT_H
#define BIG_DECIMAL_INT_H
#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt {
private:
    string num;
    bool Sign;
public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt &anotherDec);
    BigDecimalInt& operator= (const BigDecimalInt& anotherDec);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigDecimalInt& b);
};





#endif //BIG_DECIMAL_INT_H
