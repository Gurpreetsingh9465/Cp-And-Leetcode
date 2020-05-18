#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    int n;
    cin>>n;
    double rad = 0.0174533;
    if(n%2 == 0) {

        double internal_angle = ((n-1)*180*1.0)/(n*1.0);
        double prevAngle = 0;
        double ans = 1.0;
        while (true) {
            double cur_angle = (180-internal_angle)+prevAngle;
            prevAngle = cur_angle;
            double co = cos(cur_angle*rad);
            if(co<=0)
                break;
            ans = ans + 2.0 * co;
        }
        cout<<ans<<"\n";
    }
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


