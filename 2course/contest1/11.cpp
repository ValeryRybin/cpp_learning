#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false; 
    }
    
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false; 
        }
    }
    return true;
}

int main() {
    int a, count=0;
    cin >> a;
    
    int num = 2; 

    while (count < a) {
        if (isPrime(num)) {
            count++;
            if (count == a) {
                cout <<num<< endl;
                break;
            }
        }
        num++;
    }
    
    return 0;
}