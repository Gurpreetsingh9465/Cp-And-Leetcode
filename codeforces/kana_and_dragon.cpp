#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


bool solve() {
    int x,n,m;
    cin>>x>>n>>m;
    while (x>0) {
        if(x<=m*10) {
            return true;
        }
        if(n==0 && m == 0)
            return false;
        if(n) {
            x = (x/2) + 10;
            n--;
        } else if(m) {
            x-=10;
            m--;
        }
    }

    return false;
}


int main() {
    fastIO;
    int T;
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


