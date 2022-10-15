#include "BigDecimalInt.h"
#include<iostream>
#include <cmath>
using namespace std;
char a =' ';
int numberOfDigits;

BigDecimalInt::BigDecimalInt(int decInt) {
    int index;
    if( decInt<0){
        decInt*=-1;
        sign =true;
        numberOfDigits =int(log10(decInt) + 1);
        index=numberOfDigits-1;
    }
    else{
        sign= false;
        numberOfDigits =int(log10(decInt) + 1);
        index= numberOfDigits-1;

    }
    while(decInt!=0){
        num[index]=decInt%10
        decInt = decInt/10;
        index--;
    }

}
BigDecimalInt::BigDecimalInt(string decStr){
    if(decStr[1]=='+' || decStr[1] =='-'){
        cout<<"This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    }
    else if(decStr.find(a) != string::npos){
        cout<<"This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
    }
    else {
        num = decStr;
        if(decStr[0]=='-'){
            sign= true;
        }
        else{
            sign = false;
        }
    }
}