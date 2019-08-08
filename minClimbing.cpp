#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        int dp[N+1][N+1];
        for(int i = 0;i<N+1;i++) {
            dp[i][i] = 0;
        }
        for(int i = 0;i<N;i++) {
            dp[i][i+1] = cost[i];
        }
        dp[0][1] = 0;
        for(int k = 2; k<=N;k++) {
            for(int i = 0;i<=N-k;i++) {
                int j = i + k;
                dp[i][j] = min(dp[i][j-1]+cost[j-1], dp[i][j-2] + cost[j-2]);
            }
        }
        for(int i =0;i<N+1;i++) {
            for(int j = 0;j<N+1;j++) {
                cout << setw(4); 
                if(j<i) {
                    cout<<0;
                }else {
                    cout<<dp[i][j];
                }
            }
            cout<<endl;
        }
        return dp[0][N];
    }
};

int main() {
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<Solution().minCostClimbingStairs(v)<<endl;
    return 0;
}
