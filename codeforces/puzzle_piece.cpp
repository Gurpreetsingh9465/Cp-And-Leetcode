#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


bool solve() {
    int n,m;
    cin>>n>>m;
    if(n == 2 && m == 2)
        return true;
    if(n==1 || m==1)
        return true;
    // if(((n&1) && !(m&1)) || (!(n&1)  && (m&1)))
    //     return true;
    return false;
}


int main() {
    fastIO;
    ll T;
    cin>>T;
    while (T--) {
        if(solve()) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }    
    return 0;
}


