#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


bool solve() {
    ll n,k;
    cin>>n>>k;
    ll arr[n+1];

    // median is ((n+1)/2) index of sorted
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    }

    ll kCount = 0;
    ll less_count = 0;
    ll more_count = 0;
    if(n == 1 && arr[1] == k)
        return true;

    bool flag = false;
    for(int i=1;i<=n;i++) {
        if(arr[i]<k)
            arr[i] = 0;
        else if(arr[i] > k)
            arr[i] = 2;
        else
            arr[i] = 1;
        if(arr[i] == 1)
            flag = true;
    }
    if(flag == false)
        return false;
    for(ll i=1;i<=n;i++) {
        for(int j=i+1;j<=n && j-i<=2;j++) {
            if(arr[i] && arr[j])
                return true;
        }
    }
    return false;
}


int main() {
    fastIO;
    ll T;
    cin>>T;
    while (T--) {
        if(solve()) {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }    
    return 0;
}


