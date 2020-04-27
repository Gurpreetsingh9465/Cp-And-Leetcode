#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,K;
        cin>>N>>K;
        ll ans = 0;
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i];
        }

        for(int i = 0;i<N;i++) {
            ans = ans + (v[i]%K);
        }
        cout<<(ans%K)<<endl;
    }
    return 0;
}