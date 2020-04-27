#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

ll calculate(vector<ll> &arr, ll N, ll K) {
    ll i,j,max_diff = INT_MIN;
    if(K == 1) {
        for(ll k=1;k<N;k++) {
            ll diff = arr[k]-arr[k-1];
            if(max_diff<diff) {
                max_diff = diff;
                i=k;
            }
        }
        arr.insert(arr.begin()+i,(arr[i-1]+arr[i])/2);
        // for(auto &i: arr) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        max_diff = INT_MIN;
        for(ll k=1;k<=N;k++) {
            ll diff = arr[k]-arr[k-1];
            if(max_diff<diff) {
                max_diff = diff;
            }
        }
        return max_diff;
    }
    return 0;

}

int main() {
    // fastIO;
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++) {
        ll N, K;
        cin>>N>>K;
        vector<ll> v(N);
        for(ll i=0;i<N;i++) {
            cin>>v[i];
        }
        cout<<"Case #"<<t<<": "<<calculate(v, N, K)<<"\n";
    }
    return 0;
}
