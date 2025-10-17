#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int n;
        cin>>n;
	double max_w=0;
	int max_n=0;
	for(int i=0; n>i; i++){
	double a,b,c;
	cin>>a>>b>>c;
	if (a*a*b*c > max_w){
	 max_w = a*a*b*c;
	 max_n = i;
	}
	}
	cout<<max_n;
	return 1;
}