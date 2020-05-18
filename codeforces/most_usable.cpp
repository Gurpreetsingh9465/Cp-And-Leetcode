#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    int n,m;
    cin>>n>>m;
    if(n == 1) {
        cout<<"0\n";
        return;
    }
    if(n == 2) {
        cout<<m<<"\n";
        return;
    }
    cout<<2*m<<"\n";
    return;
}


int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


