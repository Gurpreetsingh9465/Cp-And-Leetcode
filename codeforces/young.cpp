#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int j = n-1;
    int ans = 0;
    sort(v.begin(), v.end());
    int num = INT_MAX;
    for(int j=n-1;j>=0;j--) {
        num = min(num,v[j]);
        num--;
        if(num == 0){
            num = INT_MAX;
            ans++;
        }
    }
    if(num == 0)
        ans++;
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


