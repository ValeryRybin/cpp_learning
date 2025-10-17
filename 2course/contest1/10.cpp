#include <iostream>
#include <string>
using namespace std;

int main() {
    int count=0;
    string numbers;
    cin >> numbers;
    int len = numbers.size();
    for (int i=0; i<len; i++)
        if (numbers[i]=='1') 
            count++;

    cout<<count<<endl;
    return 0;
}