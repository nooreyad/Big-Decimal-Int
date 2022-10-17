#include<iostream>
#include "BigDecimalInt.h"
#include<cmath>
using namespace std;

int main(){
    BigDecimalInt str1 = 9969778;
    BigDecimalInt str2 = -96987786;
    BigDecimalInt str3 = 89;
    BigDecimalInt str4 {"6969786"};  //Gives error
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str1.sign() << endl;
    if(str1 == str2){
        cout << "Yes";
    } else {
        cout << "No";
    }
    str3 = str1;
    cout << str3;
//    if(str1 == str2){
//        cout <<"Yes";
//    } else {
//        cout << "no";
//    }
}