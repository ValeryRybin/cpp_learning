#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    for(int i=0; i<a/2; i++){
        for(int k=0; k<((a/2-i)); k++)
            cout<<" ";
        for(int k=0; k<2*i+1; k++)
            cout<<"+";
        for(int k=0; k<((a/2-i)); k++)
            cout<<" ";
        cout<<endl;
    }
    for(int i=a/2; i>=0; i--){
        for(int k=0; k<((a/2-i)); k++)
            cout<<" ";
        for(int k=0; k<2*i+1; k++)
            cout<<"+";
        for(int k=0; k<((a/2-i)); k++)
            cout<<" ";
        cout<<endl;
    }
}