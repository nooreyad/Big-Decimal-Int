#include<iostream>
#include "BigDecimalInt.h"
#include<cmath>
using namespace std;

int main(){
    BigDecimalInt str1 = 300;
    BigDecimalInt str2 = 10;
    BigDecimalInt str3 = 89;
    BigDecimalInt str4 {"6969786"};
    BigDecimalInt str5 {"-68798797978979879969786"};
    BigDecimalInt str6 {"+68798797978979879969786"};
    cout << str1 << endl;
    BigDecimalInt str9 = str1 + str2;
    cout << str9;
//    cout << str1.sign() << endl;
//    if(str5 > str6){
//        cout << "Yes" << endl;
//    } else {
//        cout << "No" << endl;
//    }
//    str3 = str1;
//    str1 = str4;
//    cout << str1;
//    if(str1 == str2){
//        cout <<"Yes" << endl;
//    } else {
//        cout << "no" << endl;
//    }

}