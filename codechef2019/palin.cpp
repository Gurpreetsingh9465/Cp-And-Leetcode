#include<bits/stdc++.h>
using namespace std;

int calculate(string s) {
    int n = s.length();
    if(n <= 1) 
        return n;
    pair<int,pair<char,char>> dp[n][n];
    int l = 0;
    for(int k = 0;k<n;k++) {
        for(int i = 0;i<n-k;i++) {
            int j = i+k;
            if(i==j) {
                dp[i][j] = {1, {s[i],s[j]}};
            }else if(j-i == 1) {
                if(s[i] == s[j]) {
                    dp[i][j] = {2, {s[i], s[j]}};
                } else {
                    dp[i][j] = {1, {s[i],s[j]}};
                }
            } else {
                auto pr = dp[i+1][j-1].second;
                if(s[i] == s[j] && !(s[i] == pr.first || s[j] == pr.second)) {
                    dp[i][j] = {dp[i+1][j-1].first + 2, {s[i], s[j]}};
                } else {
                    if(dp[i][j-1].first > dp[i+1][j].first) {
                        dp[i][j] = dp[i][j-1];
                    } else {
                        dp[i][j] = dp[i+1][j];
                    }
                }
            }
            if(dp[i][j].first > l) {
                l = dp[i][j].first;
            }
        }
    }
    return l - (l&1);
}

int main() {
    string s;
    cin>>s;
    int n = calculate(s);
    cout<<n<<endl;
    return 0;
}