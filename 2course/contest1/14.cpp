#include <iostream>
using namespace std;
int NOK(int a, int b){
    int nod;
    int ab = a*b;
    while(a!=b){
        if(a>b) a=a%b; 
        else b=b%a;
    }
    nod=a;
    return (ab/nod);
}
int main() {
    int a, b, c;
    cin>>a>>b>>c;
    cout<<NOK(a,b);
    cout<<NOK(NOK(a,b),c);        
}