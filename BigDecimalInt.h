#include<iostream>
#include<string>
using namespace std;
#ifndef ASSIGNMENT_1_OOP_BIG_DECIMAL_INT_CLASS_H
#define ASSIGNMENT_1_OOP_BIG_DECIMAL_INT_CLASS_H
class BigDecimalInt {
private:
    string num;
public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigDecimalInt b);
};




#endif //ASSIGNMENT_1_OOP_BIG_DECIMAL_INT_CLASS_H
