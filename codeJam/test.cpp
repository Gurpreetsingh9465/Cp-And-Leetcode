#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<int,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

#include <chrono> 
#define curr_time chrono::high_resolution_clock::now()
#define time_duration(begin, end) chrono::duration_cast<chrono::milliseconds>(end - begin).count()

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

int r, c;

vector<pii> res, cur;
bool vis[21][21];

void dfs(int i, int j){
    // if(i==r || j==c) return;

    // if(!res.empty()) return;
	// for(auto &i: cur) {
	// 	cout<<"("<<i.first+1<<","<<i.second+1<<") ";
	// }
	// cout<<"\n";
    if(cur.size()==r*c){
        res = cur;
        return;
    }

    cur.pb({i,j});
    vis[i][j] = 1;

    for(int a = 0; a < r; a++){
        for(int b = 0; b < c; b++){
            if(a==i || b==j || a+b==i+j || a-b==i-j || vis[a][b]) continue;
            dfs(a, b);
        }
    }

	if(cur.size()==r*c){
        res = cur;
        return;
    }

    cur.pop_back();
    vis[i][j] = 0;
}

void solve(){
    for(int a = 0; a < r; a++){
        for(int b = 0; b < c; b++){
            cur.clear();
            res.clear();
            memset(vis, 0, sizeof(vis));
            dfs(a,b);
            if(!res.empty()) break;
        }
    }
    if(res.empty()){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<"POSSIBLE\n";
    assert(res.size()==r*c);
    for(int i = 0; i < r*c; i++){
        cout<<res[i].first<<" "<<res[i].second<<"\n";
    }
}

int main(){
    fast 
    int T;
    cin>>T;
    int t;
    rep(t, 1, T+1){
        cin>>r>>c;
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}