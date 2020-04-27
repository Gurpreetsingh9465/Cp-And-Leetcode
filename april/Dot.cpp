#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int const MOD=998244353;

ll fpq(int *a, int p, int q, int m) {
    int ans = 0;
    for(int i=0;i<m;i++) {
        ans = (ans%MOD + a[p+i]*a[q+i])%MOD;
    }
    return ans;
}

ll getForArr(int *arr, int N, int M) {
    ll ans = 0;
    for(int i=1;i<=N-M+1;i++) {
        for(int j=1;j<=N-M+1;j++) {
            ans = (ans%MOD + fpq(arr,i,j,M)%MOD)%MOD;
        }
    }
    return ans;
}


void solve() {
    int N,M,Q;
    cin>>N>>M>>Q;
    int arr[N+1];
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    while (Q--) {
        int pos, val;
        cin>>pos>>val;
        arr[pos] = val;
        cout<<getForArr(arr,N,M)<<"\n";
    }
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}


