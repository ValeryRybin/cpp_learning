#include <iostream> 
using namespace std;

int main (){ 
int x_scv , x_drone , v_scv , v_drone, x_minerals;
cin>>x_scv >> x_drone >> v_scv >> v_drone >> x_minerals;
x_scv+=v_scv;
x_drone+=v_drone;
while (x_scv<x_minerals && x_drone<x_minerals){
if (x_scv-1==x_drone) x_drone+=v_drone;
if (x_drone-1==x_scv) x_scv+=v_scv;
else {x_drone+=v_drone; x_scv+=v_scv;}
}
if(x_scv>=x_minerals && x_drone>=x_minerals) cout<<"both";
else if (x_scv>=x_minerals) cout<<"SCV";
else cout<<"drone";
return 1;
}