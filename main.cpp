#include <iostream>

using namespace std;

bool bears(int n){
    int factor = (n % 10)*((n % 100)/10);
    if (n == 42){
        return true;
    }
    else if (n < 42){
        return false;
    }
    else if (((n % 5) == 0) && (bears(n - 42))){
        return true;
    }
    else if ((factor != 0) && (((n % 4) == 0) || (n % 3) == 0) && (bears(n - factor))){
        return true;
    }
    else if ((n % 2) == 0 && bears(n / 2)){
        return bears(n - (n / 2));
    }
    else {
        return false;
    }
}

int main(){
    int n;
    cout << "Enter the number of teddy bears: ";
    cin >> n;
    bears(n);
    if (bears(n)){
        cout << "it is possible to win" << endl;
    }
    else{
        cout << "it is not possible to win";
    }
}