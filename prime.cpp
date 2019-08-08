#include<bits/stdc++.h>

bool isPrime(unsigned long int a) {
    if(a == 1) {
        return false;
    }
    if(a == 2) {
        return true;
    }
    if(a%2 == 0) {
        return false;
    }
    for(unsigned long int i=3;i<=sqrt(a)+1;i+=2) {
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin>>n;
    unsigned long int arr[n][2];
    for(int i=0;i<n;i++) {
        std::cin>>arr[i][0];
        std::cin>>arr[i][1];
    }
    for(int i=0;i<n;i++) {
        for(unsigned long int j = arr[i][0];j<=arr[i][1];j++) {
            if(isPrime(j)) {
                std::cout<<j<<std::endl;
            }
        }
        std::cout<<std::endl;
    }

    return 0;
}