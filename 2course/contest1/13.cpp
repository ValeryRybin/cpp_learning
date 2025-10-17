#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    string binar_number_r = "";
    if (n==0) cout<<"0";
    while (n>0)
    {
        if(n%2==1){
            binar_number_r+="1";
            n=n/2;
        }
        else{
            binar_number_r+="0";
            n=n/2;
        }
    }
    string binar_number;
    for (int i = binar_number_r.size() - 1; i >= 0; i--) {
        binar_number = binar_number.append(1, binar_number_r[i]);
    }
    cout<<binar_number;
}