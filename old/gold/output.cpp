#include<bits/stdc++.h>
using namespace std;


int main() {
    int x;
    cin>>x;
    int initial = x;
    int sum = 1;
    x = x/2;
    for(sum; x>0;x=x/2) {
        sum+=1;
    }
    cout<<sum<<" "<<floor(log2(initial))+1<<endl;
    sum = 1;
    do {
        sum+=1;
        x/=2;
    } while(x>0);
    cout<<sum<<" "<<floor(log2(initial))+1<<endl;
    return 0;
}