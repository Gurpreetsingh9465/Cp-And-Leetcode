#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int fun(int n,int k) {
    return n+2*k;
}

int smallest(int n) {
    int ans = n;
    for(int i=3;i<=n;i+=2) {
        if(n%i == 0) {
            ans = i;
            break;
        }
    }
    return ans;
}

int solve() {
    int n,k;
    cin>>n>>k;
    if(n&1) {
        n = n+smallest(n);
        return fun(n,k-1);
    }
    return fun(n,k);
}


int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        cout<<solve()<<"\n";
    }
    
    return 0;
}


