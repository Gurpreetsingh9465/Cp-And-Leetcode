#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

bool rec()

void solve() {
    int n,m;
    cin>>n>>m;
    int n1,n2,n3;
    vector<pair<int,vector<int>>> graph(n+1);
    cin>>n1>>n2>>n3;
    int dp[n+1][n1+1][n2+1][n3+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].second.push_back(v);
        graph[v].second.push_back(u);
        graph[u].first = 0;
        graph[v].first = 0;
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++) {
        if(visited[i] == false) {
            bool a =rec();
            if(a == false) {
                
            }
        }
    }
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


