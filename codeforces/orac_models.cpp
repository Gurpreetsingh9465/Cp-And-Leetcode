#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

class node {
    public:
        int index, number, num;
        node(int index, int number, int num) {
            this->index = index;
            this->number = number;
            this->num = num;
        }
        // node(node &n) {
        //     index = n.index;
        //     number = n.number;
        //     num = n.num;
        // }
};

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i = 1;i<=n;i++) {
        cin>>nums[i];
    }
    int dp[n+1];
    for(int i=1;i<=n;i++) {
        dp[i] = 1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=2;i*j<=n;j++) {
            if(nums[i*j] > nums[i])
                dp[i*j] = max(dp[i]+1,dp[i*j]);
        }
    }
    int ans = INT_MIN;
    for(int i = 1;i<=n;i++) {
        ans = max(ans,dp[i]);
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


