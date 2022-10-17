#include "BigDecimalInt.h"
#include<iostream>
#include <cmath>
#include <cstring>
#include<algorithm>
using namespace std;
char a = ' ';

BigDecimalInt::BigDecimalInt(int decInt) {
    if( decInt<0){
        decInt*=-1;
        Sign =true;
        num= to_string(decInt);
    }
    else{
        Sign= false;
        num= to_string(decInt);
    }
}

BigDecimalInt::BigDecimalInt(string decStr) {
    if (decStr[1] == '+' || decStr[1] == '-') {
        cout<<decStr<<"\n"<<"This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    }
    if (decStr.find(a) != string::npos) {
        cout <<decStr<<"\n"<< "This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
        }
    if (decStr[0] == '-') {
        Sign = true;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else if(decStr[0]=='+'){
        Sign = false;
        for (int i = 1; i < decStr.size(); i++) {
            num.push_back(decStr[i]);
        }
    }
    else{
        num=decStr;
    }
}

BigDecimalInt& BigDecimalInt::operator= (const BigDecimalInt& anotherDec){
    if(this == &anotherDec){
        return *this;
    }
    num = anotherDec.num;
    Sign = anotherDec.Sign;
    return *this;
}

bool BigDecimalInt::operator==(BigDecimalInt &anotherDec){
    cout << "operator == called" << endl;
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
        for (auto item: b.num) {
            out << item;
        }
    }else {
        for (auto item: b.num) {
            out << item;
        }
    }
    return out;
}