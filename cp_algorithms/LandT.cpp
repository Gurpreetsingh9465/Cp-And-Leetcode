#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int first_three(int n, int k)
{
    double x = k * log10(n);
    return int(pow(10, x - ll(x)) * 100);
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,k;
    cin>>n>>k;
    // find LLL...TTT ( find first and last 3 digit of n^k n is atleat 6 digit long)
    cout<<binpow(n,k,10)<<"\n";
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


