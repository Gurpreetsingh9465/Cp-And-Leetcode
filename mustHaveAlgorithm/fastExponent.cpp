#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

int main() {
    cout<<fast_exp(5,10);
    return 0;
}
