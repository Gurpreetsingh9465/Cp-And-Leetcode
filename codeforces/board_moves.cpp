#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef unsigned long long ll;

const ll max_n = 1e5+5;

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    // memset(arr,0,sizeof(arr));
    arr[1] = 0;
    for(ll i=3;i<=n;i+=2) {
        ll iby2 = (i*1LL)/2;
        ll mul = ((2*1LL*i) + 2*1LL*(i-2))*1LL*iby2;
        arr[i] = arr[i-2]+mul;
    }
    cout<<arr[n]<<"\n";
}


int main() {
    fastIO;
    ll T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


