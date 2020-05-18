#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

bool isPowerOfTwo(int n) 
{ 
    if(n==0) 
    return false; 
  
return (int)(ceil((log2(n) ))) ==  
       (int)(floor(((log2(n))))); 
} 

bool solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    int i=0;
    vector<int> good(2, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i] && !good[0]) {
            return false;
        } else if (a[i] < b[i] && !good[1]) {
            return false;
        }
        if (a[i] == -1) good[0] = 1;
        if (a[i] == 1) good[1] = 1;
    }
    return true;
    
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
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


