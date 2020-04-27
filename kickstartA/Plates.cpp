#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int a[52][32];
int dp[52][50*30+2];
int n,k,p, ans;

int solve(int i, int s){
    if(i<0){
        return 0;
    }

    int &res = dp[i][s];

    if(s==0){
        return res = 0;
    }

    if(res != -1){
        return res;
    }

    int j;
    for(int j=0;j<min(s+1, k+1);j++) {
        res = max(res, solve(i-1, s-j) + a[i][j]);
    }
    return res;
}


int main(){
    fastIO
    int T;
    cin>>T;
    int t;
    for(int t=1;t<=T;t++) {
        int i,j;
        cin>>n>>k>>p;
        for(int i=0;i<n;i++) {
            for(int j=1;j<k+1;j++) {
                cin>>a[i][j];
                a[i][j] += a[i][j-1];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<t<<": "<<solve(n-1, p)<<"\n";
    }
    return 0;
}