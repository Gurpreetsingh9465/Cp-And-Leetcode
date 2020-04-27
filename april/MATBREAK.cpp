#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef unsigned long long ll;

int MOD = 1000000007;

ll fast_exp_rec(int base, int exp) {
    if(exp == 0)
        return 1;
    if(exp == 1)
        return base;
    ll inter = fast_exp_rec(base, exp/2)%MOD;
    if(exp&1) {
        return ((inter*inter)%MOD*base)%MOD;
    }
    return (inter*inter)%MOD;
}

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

void solve() {
    int N, A;
    cin>>N>>A;
    if(A == 0) {
        cout<<"0"<<"\n";
        return;
    }
    ll cur = 1;
    ll prev = 1;
    ll curPower = 1;
    ll ans = 0;
    for(int i=1;i<=N;i++) {
        curPower = cur*prev;
        ans = (ans + fast_exp_rec(A, curPower)%MOD)%MOD;
        prev = curPower+prev;
        cur+=2;
    }
    cout<<(ans)<<"\n";
}

int main() {
    // fastIO;
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


