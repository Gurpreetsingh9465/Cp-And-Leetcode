#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;


void solve() {
    vector<int> freq(202,0);
    int ans = 0;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        freq[a]++;
    }
    for(int i=1;i<=202;i++) {
        if(freq[i] != 0) {
            ans = i;
        } else {
            if(x == 0) {
                break;
            }
            ans = i;
            x-=1;
        }
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


