#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

bool rec(int cur_x, int cur_y, vector<pair<int,int>> &path, int R, int C, bool **dp) {
    if((int)(path.size()) == R*C)
        return true;
    // int full_groups = path.size() / (3 * R);
    // int full_columns = 3 * full_groups;
    // int limit = C;
    // if (C - full_columns > 6) {
    //     limit = full_columns + 3;
    // }
    int limit = C;
    dp[cur_x][cur_y] = true;
    path.push_back({cur_x,cur_y});
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=limit;j++) {
            if(j<1 ||j>C)
                continue;
            if(cur_x != 0 && (cur_x == i || cur_y == j || cur_x+cur_y == i+j || cur_x-cur_y == i-j || dp[i][j]))
                continue;
            
            
            if(rec(i,j,path,R,C,dp)) {
                return true;
            }
        
        }
    }
    dp[cur_x][cur_y]=false;
    path.pop_back();
    return false;

}

void solve() {
    int R,C;
    cin>>R>>C;
    bool swapped = false;
    if(R<C) {
        swap(R,C);
        swapped = true;
    }
    bool **dp;
    dp = new bool*[R+1];
    for(int i=1;i<=R;i++) {
        dp[i] = new bool[C+1];
        for(int j=1;j<=C;j++) {
            dp[i][j] = false;
        }
    }
    vector<pair<int,int>> path;
    if(rec(0,0,path,R,C,dp)) {
        cout<<"POSSIBLE"<<"\n";
        for(auto &i: path) {
            if(swapped) {
                cout<<i.second<<" "<<i.first<<"\n";
            } else {
                cout<<i.first<<" "<<i.second<<"\n";
            }
        }
    } else {
        cout<<"IMPOSSIBLE"<<"\n";
    }
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
