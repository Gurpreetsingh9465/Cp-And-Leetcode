#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

int getMin(vector<int> &v) {
    int min_ = INT_MAX;
    int max_ = INT_MIN;
    for(int i=1;i<=3;i++) {
        if(v[i] == 0) {
            return -1;
        }
        min_ = min(min_,v[i]);
        max_ = max(max_,v[i]);
    }
    return max_-min_+1;
}


void solve() {
    string s;
    cin>>s;
    vector<int> v(4,0);
    s = ' '+s;
    int ans = 0;
    for(int i=1;i<=s.size()-1;i++) {
        int num = s[i]-'0';
        v[num] = i;
        int cur = getMin(v);
        if(cur == -1) {
            continue;
        }
        if(ans == 0) {
            ans = cur;
        }
        ans = min(ans,cur);
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


