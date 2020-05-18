#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


void solve() {
    ll n;
    cin>>n;
    vector<ll> cards(sqrt(n)+1);
    for(ll i=1;i<=sqrt(n);i++) {
        cards[i] = ((3*i*i)+i)/2;
    }
    ll ans = 0;
    while (n) {
        ll index = lower_bound(cards.begin(),cards.end(),n) - cards.begin();
        if(cards[index] != n)
            index-=1;
        if(index == 0)
            break;
        ll count = n/cards[index];
        ans+=count;
        n = n - count*cards[index];
    }
    cout<<ans<<"\n";
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


