#include "BigDecimalInt.h"
#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;
char a =' ';

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
        cout<< "This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    } else if (decStr.find(a) != string::npos) {
        cout << "This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
    } else {
        if (decStr[0] == '-') {
            Sign = true;
            for (int i = 1; i < decStr.size(); i++) {
                num.push_back(decStr[i]);
            }
        } else {
            Sign = false;
            if(decStr[0]=='+') {
                for (int i = 1; i < decStr.size(); i++) {
                    num.push_back(decStr[i]);
                }
            }
            else{
                num=decStr;
            }
        }
    }
}