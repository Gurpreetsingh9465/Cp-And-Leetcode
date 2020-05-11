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

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxN = 1e5;
int dp[mxN];


int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        dp[1] = 0;
        dp[2] = 0, dp[3] = 1, dp[4] = 1;
        rep(i, 5, n+1){
            rep(j, 1, ceil(i/2.0)){
                dp[i] = dp[i] + dp[j] + dp[i-j] +dp[n-1];
            }
        }
        
        cout<<dp[n]<<"\n";
        memset(dp, 0, sizeof(dp));

        
    }
    return 0;
}