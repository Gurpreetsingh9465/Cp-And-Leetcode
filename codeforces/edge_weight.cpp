#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

int cnt;

void dfs(vector<vector<int>> &graph,int cur,int par, int level , int dp[]) {
    dp[cur] = level;
    int c = 0;
    for(auto &i: graph[cur]) {
        if(par == i)
            continue;
        if(graph[i].size() == 1)
            c++;
        dfs(graph,i,cur,level+1,dp);
    }
    if(c>=1)
        cnt++;
}

void solve() {
    int n;
    cnt = 0;
    cin>>n;
    vector<vector<int>> graph(n+1);
    int a,b;
    for(int i=1;i<=(n-1);i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> leafs;
    int root = -1;
    for(int i=1;i<=n;i++) {
        if(graph[i].size() == 1)
            leafs.push_back(i);
        else
            root = i;
    }
    int dp[n+1];
    dfs(graph,leafs[0],-1,0,dp);
    int mini = 1;
    for(auto i: leafs) {
        if((dp[i]&1) == 1) {
            mini = 3;
        }
    }
    cnt = 0;
    dfs(graph,root,-1,0,dp);
    cout<<mini<<" "<<(n-1-(int)leafs.size()+cnt)<<"\n";
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
    
    return 0;
}


