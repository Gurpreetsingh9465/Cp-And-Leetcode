#include<bits/stdc++.h>
#define li int
int main() {
    int t;
    std::cin>>t;
    while(t--) {
        li n;
        std::cin>>n;
        li q[n];
        li a[n];
        for(li i=0;i<n;i++) {
            std::cin>>q[i];
            a[i] = i+1;
        }
        for(li i=1;i<n;i++) {
                a[i] -= q[i];
                for(li j = i-1 ; j>=(i-q[i]) ; j--) {
                    a[j]+=1;
                }
        }
        for(li i=0;i<n;i++) {
            std::cout<<a[i]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}