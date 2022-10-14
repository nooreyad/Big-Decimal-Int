#include "BigDecimalInt.h"
#include<iostream>
#include<vector>
using namespace std;

BigDecimalInt::BigDecimalInt(int decInt) {

}
BigDecimalInt::BigDecimalInt(string decStr){
    char a =' ';
    if(decStr[1]=='+' || decStr[1] =='-'){
        cout<<"This input doesn't represent a valid format for the number\nPlease enter the number with only one sign\n";
    }
    else if(decStr.find(a) != string::npos){
        cout<<"This input doesn't represent a valid format for the number\nPlease enter the number without spaces\n";
    }
    else {
        num = decStr;
    }
}