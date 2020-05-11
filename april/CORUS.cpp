#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

void solve() {
    int N,Q;
    cin>>N>>Q;
    string s;
    cin>>s;
    int freq[26];
    memset(freq,0,sizeof(freq));
    for(auto &i: s) {
        freq[i-'a']+=1;
    }
    while (Q--) {
        int c;
        cin>>c;
        int ans = 0;
        for(int i = 0;i<26;i++) {
            ans = ans + max(0,freq[i]-c);
        }
        cout<<ans<<"\n";
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