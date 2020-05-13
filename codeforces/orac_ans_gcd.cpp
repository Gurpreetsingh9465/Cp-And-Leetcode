#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0;i<n;i++) {
        cin>>arr[i];
    }
    ll gcd[n];
    gcd[n-1] = arr[n-1];
    for(ll i=n-2;i>=0;i--) {
        gcd[i] = __gcd(gcd[i+1],arr[i]);
    }
    ll ans = 0;
    for(ll i=0;i<n-1;i++) {
        ans = __gcd(ans,arr[i]*gcd[i+1]/__gcd(arr[i],gcd[i+1]));
    }
    cout<<ans<<"\n";
}


int main() {
    // fastIO;
    // ll T;
    // cin>>T;
    // while (T--) {
        solve();
    // }
    
    return 0;
}


