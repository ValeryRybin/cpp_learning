#include <iostream>

int main()
{   int n;
    std::cin>>n;
    int a[n];
    int b[n];
    for (int i=0;i<n;++i){
        std::cin>>a[i];
    }
    for (int i=0;i<n;++i){
        b[n-i-1]=a[i];
    }

    for (int i=0;i<n;++i){
        std::cout<<b[i]<<" ";
    }
    return 0;
}