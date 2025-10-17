#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int n;
        cin>>n;
	int max_a=-1000000;
        int count=0;
	for(int i=0; n>i; i++){
	int a;
	cin>>a;
	if(a>max_a) {
	max_a=a;
	count=1;
	}
	else if(a==max_a) count++;
	}
	cout<<count;
	return 1;
}