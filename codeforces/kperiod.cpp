#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

int countOne(int prefix[], int n, int i, int j) {
    if(i == 0) {
        return prefix[1] - prefix[j];
    }
    if(i+1>n)
        return 0;
    if(j>n) {
        return prefix[i+1];
    }
    i+=1;
    return prefix[i]-prefix[j];
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int prefix[n+1];
    int a = 0;
    for(int i=n;i>=1;i--) {
        if(s[i-1] == '1')
            a++;
        prefix[i] = a;
    }

    int dp[n+1];
    dp[n] = 0;
    // cout<<countOne(prefix,n,8,10)<<"=========";
    for(int i=n-1;i>=1;i--) {
        if(s[i-1] == '0') {
            dp[i] = min( countOne(prefix,n,i,n+1), 1+countOne(prefix,n,i,i+k)+((i+k)<=n?dp[i+k]:0) );
        } else {
            dp[i] = min(1 + countOne(prefix,n,i,n+1), countOne(prefix,n,i,i+k)+((i+k)<=n?dp[i+k]:0) );
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++) {
        ans = min(ans,dp[i]+countOne(prefix,n,0,i));
    }
    // for(int i=1;i<=n;i++) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    cout<<ans<<"\n";
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


