#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


const int MOD = 1000000007;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i = 1;i<=n;i++) {
        cin>>v[i];
    }
    int positions[n+1];
    for(int i = 1;i<=n;i++) {
        positions[v[i]] = i;
    }
    vector<vector<int>> ans(k+1);
    int index = 0;
    int i = 1;
    while(i < n){
        if(index>k) {
            cout<<"-1\n";
            return;
        }
        int i1 = i;
        int i2 = v[i1];
        int i3 = v[i2];
        if(i1 == i2 || i1 == i3){
            i++;
            continue;
        }
        int temp = v[i3];
        v[i3] = v[i2];
        v[i2] = v[i1];
        v[i1] = temp;
        ans[index++] = {i1,i2,i3};
    }
    i = 1;
    while(i<n) {
        if(index>k) {
            cout<<"-1\n";
            return;
        }
        if(v[i] == i) {
            i++;
            continue;
        }
        int i1 = i;
        int i2 = v[i];
        int i3 = 0;
        int i4 = 0;
        int j = i1+1;
        while(j < n){
            if(j != i2 && v[j] != j) {
                i3 = j;
                i4 = v[j];
                break;
            }
            j++;
        }
        if(i3 == 0) {
            cout<<"-1\n";
            return;
        }
        int a = v[i1], b = v[i2], c = v[i3], d=v[i4];
        v[i1] = c;
        v[i2] = a;
        v[i3] = b;
        ans[index++] = {i1,i2,i3};
        ans[index++] = {i1,i4,i3};
        a = v[i1], b = v[i2], c = v[i3], d=v[i4];
        v[i1] = c;
        v[i4] = a;
        v[i3] = d;
    }
    // for(int i = 1;i<=n;i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    cout<<index<<"\n";
    for(int i = 0;i<index;i++) {
        for(auto &j: ans[i]) {
            cout<<j<<" ";
        }
        cout<<"\n";
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