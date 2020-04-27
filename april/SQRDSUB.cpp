#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

void solve() {
    int i, n;
    cin>>n;
    ll arr[n];
    for(i = 0;i<n;i++) {
        cin>>arr[i];
    }
    ll count2 = 0;
    if(arr[0]%4==0) count2+=2;
    else if(arr[0]%2==0) count2++;
    int l = 0, r = 0;
    ll res = 0;
    while(r<n){
        if(l<=r && count2>=2){
            res += n - r;
            if(arr[l]%4==0) count2 -= 2;
            else if(arr[l]%2==0) count2--;
            l++;
        } else {
            r++;
            if(arr[r]%4==0) count2+=2;
            else if(arr[r]%2==0) count2++;
        }
    }
    i = 0;
    ll len;
    while(i<n){
        if(arr[i]&1){
            l = i;
            int j = i;
            while(j<n && arr[j]&1)
                j++;       
            len = j - i;
            res += (len*(len+1))/2;
            i = j;
        }
        i++;
    }
    cout<<res<<"\n";
}

int main(){
    fastIO;
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}