#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

ll const max_n = 200005;


ll dfs(unordered_map<ll,vector<ll>> &v, int cur, bool *visited, vector<ll> &deg,int level) {
    if(visited[cur])
        return 0;
    visited[cur] = true;
    ll s = 1;
    for(int i=0;i<v[cur].size();i++) {
        s = s + dfs(v,v[cur][i],visited,deg,level+1);
    }
    deg[cur] = level-s;
    return s;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    unordered_map<ll,vector<ll>> v;
    for(ll i=0;i<n-1;i++) {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool *visited = new bool[n+1];
    for(ll i = 1;i<=n;i++) {
        visited[i] = false;
    }
    vector<ll> deg(n+1,0);
    dfs(v,1,visited,deg,1);
    sort(deg.begin()+1,deg.end(),greater<int>());
    ll ans = 0;
    for(int i = 1;i<=k;i++) {
        ans = ans + 1LL*deg[i];
    }
    cout<<ans<<"\n";
}


int main() {
    // fastIO;
    solve();
    // cout<<1LL<<"\n";
    return 0;
}


