#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

ll pow2(int p) {
    return (1LL<<p);
}

void solve() {
    int n;
    cin>>n;
    if(n == 2) {
        cout<<"2\n";
        return;
    }
    ll ans = 0;
    bool turn = true;
    for(int i=1;i<=n/2;i++) {
        if(turn) {
            ans = ans + (pow2(n-i+1) + pow2(i));
        } else {
            ans = ans - (pow2(n-i+1) + pow2(i));
        }
        turn = !turn;
    }
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


