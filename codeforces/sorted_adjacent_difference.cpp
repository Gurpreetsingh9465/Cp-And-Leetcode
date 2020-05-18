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
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int i,j;
    if(n&1) {
        i = n/2;
        j = i+1;
    } else {
        j = n/2;
        i = j-1;
    }
    vector<int> ans(n);
    int index = 0;
    while (i>=0 || j< n) {
        if(i>=0) {
            ans[index++] = v[i];
            i--;
        }
        if(j<n) {
            ans[index++] = v[j];
            j++;
        }
    }
    for(auto &i: ans) {
        cout<<i<<" ";
    }
    cout<<"\n";

}


int main() {
    fastIO;
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


