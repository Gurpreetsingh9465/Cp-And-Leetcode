#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


bool solve() {
    ll n;
    cin>>n;
    ll arr[n];
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
    }
    ll max_num = INT_MIN;
    for(int i=0;i<n;i++) {
        max_num = max(max_num,arr[i]);
    }
    unordered_set<int> indexes;
    for(int i=0;i<n;i++) {
        int newIndex = i + arr[i]%n;
        if(indexes.count(newIndex))
            return false;
        indexes.insert(newIndex);
    }
    return true;
}


int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        if(solve()) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    
    return 0;
}


