#include <iostream>
#include "cmath"
using namespace std;

int main() {
    int n, a;
    int max=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> a;
        if (abs(a)>abs(max))  {max=a;}  
    }  
    cout << max;
}