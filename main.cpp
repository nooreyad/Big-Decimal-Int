#include <iostream>

using namespace std;

void binaryPrint(int decimal, string &binary){
    if (decimal <= 1){
        binary += (char)(decimal + '0');
    }
    else {
        binaryPrint(decimal/2, binary);
        if (decimal % 2){
            binary += '1';
        }
        else {
            binary += '0';
        }
    }
}

int main() {
    int decimal;
    string binary = "";
    cout << "Please enter the decimal number: ";
    cin >> decimal;
    binaryPrint(decimal, binary);
    cout << binary << endl;
}
