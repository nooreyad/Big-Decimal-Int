#include<iostream>
#include "BigDecimalInt.h"
using namespace std;

int main(){
    BigDecimalInt str1 = {"-87"};
    BigDecimalInt str2 = {"-87"};
    BigDecimalInt strtest = str1 + str2;
    cout << strtest << endl;
    cout << str1 << endl;
    cout << str2 << endl;
}