#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }  

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i=0;
    int j=n-1;

    while (i<n && j>=0 && k!=0) {
        if(a[i] < b[j]) {
            a[i] = b[j];
            i++;
            j--;
            k--;
        } else {
            break;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans+=a[i];
    }
    cout<<ans<<"\n";
    
}


int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


