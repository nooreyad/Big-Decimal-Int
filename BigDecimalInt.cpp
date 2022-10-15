#include "BigDecimalInt.h"
#include<iostream>
#include <cmath>
using namespace std;
char a =' ';
int numberOfDigits;

BigDecimalInt::BigDecimalInt(int decInt) {
    int index=0;
    if( decInt<0){
        decInt*=-1;
        Sign =true;
        numberOfDigits =int(log10(decInt) + 1);
        index=numberOfDigits-1;
    }
    else{
        Sign= false;
        numberOfDigits =int(log10(decInt) + 1);
        index= numberOfDigits-1;

    }
    while(decInt!=0){
        num[index]='decInt%10';
        decInt = decInt/10;
        index--;
    }
cout<<num<<endl;
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
            for (int i = 1; i < decStr.size(); i++) {
                num.push_back(decStr[i]);
            }
        }
        cout << num << endl;
    }
}