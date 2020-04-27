#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i];
        }
        pair<int,int> dp[N];
        for(int i = 0;i<N;i++) {
            dp[i] = {1,-1};
        }
        int max_so_far = INT_MIN;
        for(int i = 1;i<N;i++) {
            for(int j = 0;j<i;j++) {
                if(dp[j].second == -1) {
                    dp[i].first = max(dp[i].first,dp[j].first+1);
                    dp[i].second = v[i]>v[j]?1:0;
                } else if(dp[j].second == 0) {
                    if(v[i] > v[j]) {
                        dp[i].first = max(dp[i].first,dp[j].first+1);
                        dp[i].second = 1;
                    }
                } else if(dp[j].second == 1) {
                    if(v[i] < v[j]) {
                        dp[i].first = max(dp[i].first,dp[j].first+1);
                        dp[i].second = 0;
                    }
                }
                max_so_far = max(max_so_far,dp[i].first);
                
            }
        }
        std::cout<<max_so_far<<endl;
        
    }
    return 0;
}