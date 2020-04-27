#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 5;
    int ***dp = new int**[2];
    for(int i = 0;i<N;i++) {
        dp[i] = new int *[N];
        for(int j=0;j<N;j++) {
            dp[i][j] = new int[N];
            for(int k = 0;k<2;k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k = 0;k<2;k++) {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}