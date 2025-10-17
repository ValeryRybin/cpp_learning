#include <iostream> 
using namespace std;

int main (){ 
int x_v , x_m , Vv , Vm, x_zabor, N,L,K; 
cin>> Vv >> Vm >> L>> K >> N;
x_m=0;
x_v=L+1;
x_zabor=L+K+2;
int Vvcur;
while (x_v<x_zabor){
if (x_m>=x_v) {cout<<"0";  break;}
else {
N--;
if (Vv>=N) Vvcur=Vv-N;
else Vvcur=0;
x_m+=Vm; x_v+=Vvcur; 
}
}
if (x_v>=x_zabor) cout<<N;
return 1;
}