#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int n;
	int count=0, count2=0;
	cin>>n;
	if (n==0) cout<<"0";
	for (int i=0; n>=pow(2,i); i++) count++;
	for (int i=n; i>0; i=i/2) if (i%2==1) count2++;
	for (int i=0; count2>i;i++) cout<<"1";
	for (int i=0; (count-count2)>i;i++) cout<<"0";
	
	return 1;
}