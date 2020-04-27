#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool isBobWinner(ll *arr, ll n, ll a, ll b) {
    ll bob = 0;
    ll alice = 0;
    ll both = 0;
    for(int i = 0;i<n;i++) {
        if(arr[i]%a == 0 && arr[i]%b == 0) {
            both++;
        } else if(arr[i]%a == 0) {
            bob++;
        } else if(arr[i]%b == 0) {
            alice++;
        }
    }
    if(both == 0) {
        if(bob>alice)
            return true;
        else
            return false;
    } else {
        if(bob>=alice)
            return true;
        else
            return false;
    }
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        ll N, a, b;
        cin>>N>>a>>b;
        ll *arr = new ll[N];
        for(ll i = 0 ; i < N; i++) {
            cin>>arr[i];
        }
        if(isBobWinner(arr, N, a, b)) {
            cout<<"BOB"<<endl;
        } else {
            cout<<"ALICE"<<endl;
        }
    }
    return 0;
}