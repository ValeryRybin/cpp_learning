#include <iostream>
using namespace std;

int main() {
    int a;
    long long s = 1;
    cin >> a;
    for(int i=1; i<a+1; i++){
        s*=i;
    }
    cout << s <<endl;
}    