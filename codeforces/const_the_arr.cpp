#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll max_n = 1e5+5;

class Cmp {
    public:
        bool operator() (pair<ll,ll> &l, pair<ll,ll> &r) {
            if((r.second-r.first) == (l.second-l.first)) {
                return r.first < l.first;
            }
            return (r.second-r.first) > (l.second-l.first);
        }
};

void solve() {
    ll n;
    cin>>n;
    vector<ll> ans(n+1,0);
    ll i=1;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,Cmp> Q;
    Q.push({1,n});
    while (!Q.empty()) {
        ll size = Q.size();
        while (size--) {
            pair<ll,ll> t = Q.top();
            Q.pop();
            if(t.first == t.second) {
                ans[t.first] = i;
                i++;
                continue;
            }
            ll mid = (t.first+t.second)/2;
            ans[mid] = i;
            if(mid-1>=t.first)
                Q.push({t.first,mid-1});
            if(mid+1<=t.second)
                Q.push({mid+1,t.second});
            i++;
        }
    }
    for(ll i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }   
    cout<<"\n";
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


