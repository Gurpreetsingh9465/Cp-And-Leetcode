#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll max_n = 1e5+5;

void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++) {
        cin>>v[i];
    }
    if(n==1) {
        cout<<"0\n";
        return;
    }

    ll m = v[0];
    ll max_diff = 0;
    for(ll i=1;i<n;i++) {
        if((v[i] - m)<0) {
            max_diff = max(max_diff, abs(v[i]-m));
        } 
        m = max(m, v[i]);
    }
    cout<<ceil(log2(max_diff+1))<<endl;    
}


int main() {
    fastIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


