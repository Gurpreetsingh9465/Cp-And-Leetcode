#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a-b)<=0) {
        cout<<b<<"\n";
        return;
    }
    if((c-d)<=0) {
        cout<<-1<<"\n";
        return ;
    }
    ll ans = b+(ceil((((a-b)*1.0)/((c-d)*1.0)))*c*1LL);
    cout<<ans<<"\n";
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


