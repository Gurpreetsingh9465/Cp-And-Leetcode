#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_num = 100001;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b,a%b);
}


bool can(vector<int> &arr, int g, int x, int y, int z) {
    for(auto &i: arr) {
        int check = i/g;
        while (check!=1) {
            int d = 0;
            if(check%x == 0) {
                check/=x;
                d++;
            }
            if(check%y == 0) {
                check/=y;
                d++;
            }
            if(check%z == 0) {
                check/=z;
                d++;
            }
            if(d == 0) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int N,X,Y,Z;
    cin>>N>>X>>Y>>Z;
    vector<int> v(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    int g = 0;
    for(auto &i: v) {
        g=gcd(i,g);
    }

    if(can(v,g,X,Y,Z)) {
        cout<<"She can\n";
    } else {
        cout<<"She can't\n";
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


