#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

ll getMin(ll l) {
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    while (l) {
        int cur = l%10;
        min_num = min(min_num,cur);
        max_num = max(max_num,cur);
        l/=10;
    }
    return min_num*max_num*1LL;
    
}

void solve() {
    ll a,k;
    cin>>a>>k;
    for(int i=1;i<k;i++) {
        ll num = getMin(a);
        if(num == 0) {
            cout<<a<<"\n";
            return;
        }
        a = a+num;
    }
    cout<<a<<"\n";
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


