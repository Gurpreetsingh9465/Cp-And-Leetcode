#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

void solve() {
    int n,k;
    cin>>n>>k;
    int ans = 0;
    int prev = k;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        if(a == prev) {
            prev--;
        } else {
            prev = k;
        }
        if(prev == 0) {
            ans++;
            prev = k;
        }
    }
    cout<<ans<<"\n";
}


int main() {
    fastIO;
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++) {
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
