#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define IM 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int N;
        cin>>N;
        vector<int> v(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<N;i++) {
            ans = ans + v[N-i-1] - i;
            ans = ans%IM;
        }
        ans = ans%IM;
        cout<<ans<<"\n";
    }
        
    return 0;
}


