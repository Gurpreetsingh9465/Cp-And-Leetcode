#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

void solve(int t) {
    int X,Y;
    cin>>X>>Y;
    cout<<"Case #"<<t<<": "<<rec(X,Y)<<"\n";
}


int main() {
    fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        solve(t);
    }
    return 0;
}


