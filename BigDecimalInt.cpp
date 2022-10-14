#include "BigDecimalInt.h"
#include<iostream>
using namespace std;

BigDecimalInt::BigDecimalInt(int decInt) {

}
BigDecimalInt::BigDecimalInt(string decStr){
    vector<char>numbers={'0','1','2','3','4','5','6','7','8','9'};
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
//    for(int i=0;i<decStr.size();i++){
//        auto rslt = find(numbers.begin(), numbers.end(),decStr[i] );
//        if()
//    }
}


