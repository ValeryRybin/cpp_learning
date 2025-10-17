#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
        if(i==0 || i==a-1 ){cout << "+";} 
        else if ((j==0 ))  {cout << "+";} 
        else if (j>1 && j<b){
        cout << " ";
        }  
    }
    if(i!=0 && i!=(a-1)){cout << "+";}
    cout<<endl;
    }
}