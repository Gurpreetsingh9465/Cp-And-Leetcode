#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a, ll b){        
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){     
    if(a>b)
        return (a/gcd(a,b))*b;
    else
        return (b/gcd(a,b))*a;    
} 

int main() {
    int T;
    cin>>T;
    while(T--) {
        ll N,A,B,K;
        cin>>N>>A>>B>>K;
        ll ans = N/A;
        ans += N/B;
        ans -= 2*(N/lcm(A,B));
        if(ans>=K) {
            cout<<"Win"<<endl;
        } else {
            cout<<"Lose"<<endl;
        }
    }
}