#include<iostream>
#include "BigDecimalInt.h"
#include<cmath>
using namespace std;

int main(){
    BigDecimalInt str1 = 99697786;
    BigDecimalInt str2 = 96987786;
    //BigDecimalInt str3 = "6969786";  //Gives error
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str1.sign() << endl;
    if(str1 == str2){
        cout << "Yes";
    } else {
        cout << "No";
    }
//    if(str1 == str2){
//        cout <<"Yes";
//    } else {
//        cout << "no";
//    }
}