#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {

    int a,b,c,d;
    cin>>a>>b>>c>>d;
//233
    vector<int> v(d-a+1);
    int count = 0;
    for(int i=d;i>=c;i--) {
        int l = a;
        int r = c;
        while (l<=b && r>=b) {
            if((l+r)>i) {
                count+=(b-l+1)+((l+r)-i+1);
                r--;
            } else {
                l++;
            }
        }
        break;
    }

    cout<<count<<"\n";
    
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}


