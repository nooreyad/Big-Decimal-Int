#include "BigDecimalInt.h"
#include<iostream>
#include <cmath>
#include <cstring>
#include<algorithm>
using namespace std;
char a = ' ';

BigDecimalInt BigDecimalInt::summation(BigDecimalInt &anotherDec){
    BigDecimalInt result;
    char to_char;
    int digit1, digit2, sum ,carry = 0;
    for(int i = anotherDec.size()-1; i >= 0; i--){
        digit1 = anotherDec.num[i] - 48;
        digit2 = this->num[i] - 48;
        sum = digit1 + digit2 + carry;
        if(sum < 10){
            carry = 0;
            to_char = sum + 48;
            result.num = to_char + result.num;
        } else {
            to_char = sum%10 + 48;
            result.num = to_char + result.num;
            carry = sum/10;
        }
    }
    if(carry != 0){
        to_char = carry + 48;
        result.num = to_char + result.num;
    }
    if(this->Sign){
        result.Sign = true;
    }
    return result;
}


BigDecimalInt::BigDecimalInt() {
    Sign = false;
    num = "";
}

BigDecimalInt::BigDecimalInt(int decInt) {
    if(decInt < 0){
        decInt *= -1;
        Sign = true;
        num = to_string(decInt);
    }
    else {
        Sign = false;
        num = to_string(decInt);
    }
}

BigDecimalInt::BigDecimalInt(string decStr) {
    if (decStr[1] == '+' || decStr[1] == '-') {
        cout << decStr << "\n" << "This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    }
    if (decStr.find(a) != string::npos) {
        cout << decStr << "\n" << "This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
    }
    if (decStr[0] == '-') {
        Sign = true;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else if(decStr[0] == '+'){
        Sign = false;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else {
        Sign = false;
        num = decStr;
    }
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt &anotherDec) {
    BigDecimalInt result;
    if(this->Sign == anotherDec.Sign && this->size() == anotherDec.size()){
        return summation(anotherDec);
    } else if(this->Sign == anotherDec.Sign && this->size() > anotherDec.size()) {
        int steps = this->size() - anotherDec.size();
        for (int i = 0; i < steps; i++) {
            anotherDec.num = '0' + anotherDec.num;
        }
        return summation(anotherDec);
    } else if(this->Sign == anotherDec.Sign && this->size() < anotherDec.size()) {
        int steps = anotherDec.size() - this->size();
        for (int i = 0; i < steps; i++) {
            this->num = '0' + this->num;
        }
        return summation(anotherDec);
    }
//     else if(this->operator>(anotherDec) && this->size() == anotherDec.size()){         // -500 + 250 = 25 - 5      3 + -5 = 3 - 5
//                                                                                        // -3 + 5 = 5 - 3           5 + -3 = 5 - 3
//    }
    return result;
}

//BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
//
//}
//
//bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
//
//}

BigDecimalInt& BigDecimalInt::operator= (const BigDecimalInt& anotherDec){
    if(this == &anotherDec){
        return *this;
    }
    this->num = anotherDec.num;
    this->Sign = anotherDec.Sign;
    return *this;
}

bool BigDecimalInt::operator==(BigDecimalInt &anotherDec){
   if(this->sign() != anotherDec.sign() || this->size() != anotherDec.size()){
       return false;
   } else{
       for (int i = 0; i < anotherDec.size(); ++i) {
           if(anotherDec.num[i] != this->num[i]){
               return false;
           }
       }
       return true;
   }
}

bool BigDecimalInt::operator> (BigDecimalInt anotherDec) {
    if (this->sign() == 0 && anotherDec.sign() == 1) {
        return true;
    } else if (this->sign() == 1 && anotherDec.sign() == 0) {
        return false;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() > anotherDec.size()) {
        return true;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() < anotherDec.size()) {
        return false;
    } else if (this->sign() == 0 && anotherDec.sign() == 0 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] > anotherDec.num[i]) {
                return true;
            } else if (this->num[i] < anotherDec.num[i]) {
                return false;
            }
        }
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() > anotherDec.size()) {
        return false;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() < anotherDec.size()) {
        return true;
    } else if (this->sign() == 1 && anotherDec.sign() == 1 && this->size() == anotherDec.size()) {
        for (int i = 0; i < anotherDec.size(); ++i) {
            if (this->num[i] > anotherDec.num[i]) {
                return false;
            } else if (this->num[i] < anotherDec.num[i]) {
                return true;
            }
        }
        return false;
    }
    return false;
}


int BigDecimalInt::size() {
    int count = 0;
    for (auto item: num) {
        count++;
    }
    return count;
}

int BigDecimalInt::sign() {
    if(Sign){
        return 1;
    }else {
        return 0;
    }
}

ostream& operator << (ostream& out, BigDecimalInt& b){
    if(b.sign()){
        out << "-";
        for (char item: b.num) {
            out << item;
        }
    }else {
        for (char item: b.num) {
            out << item;
        }
    }
    return out;
}


