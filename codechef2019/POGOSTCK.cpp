#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> &v, int k) {
    for(int i=1;i<=k;i++) {
        for(int j=v.size()-i-k;j>=0;j-=k) {
            v[j]+=v[j+k];
        }
    }
    int max = INT_MIN;
    for(auto &i: v) {
        if(i>max) {
            max = i;
        }
    }
    return max;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,K;
        cin>>N>>K;
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i];
        }
        cout<<calculate(v,K)<<endl;
    }
    return 0;
}