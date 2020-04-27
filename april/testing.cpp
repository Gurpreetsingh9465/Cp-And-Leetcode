#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int const max_n = 500001;
int const MOD = 1000000007;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b,a%b);
}

int F(int x) {
    int ans = 0;
    for(int i=1;i<=x;i++) {
        ans= (ans%MOD + gcd(i,x)%MOD)%MOD;
    }
    return ans%MOD;
}

int main() {

    int x;
    cin>>x;
    for(int i =1;i<=x;i++) {
        cout<<i<<" => "<<F(i)<<"\n";
    }
}