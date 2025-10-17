#include <iostream>
using namespace std;
int NOK(int a, int b){
    int ab = a*b;
    while(a!=b){
        if(a>b) a=a-b; 
        else b=b-a;
    }
    return (ab/a);
}
int main() {
    int a, b, c;
    cin>>a>>b>>c;
    cout<<NOK(NOK(a,b),c);        
}