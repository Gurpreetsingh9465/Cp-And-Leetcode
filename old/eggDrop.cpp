#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k, int **dp) {
    if(dp[k][n] != -1) 
        return dp[k][n];
    if(k == 1) {
        dp[k][n] = n;
        return n;
    }
    if(n<=1)
        return dp[k][n] = n;
    int minNo = INT_MAX;
    for(int x = 1;x<=n-1;x++) {
        int no = max(eggDrop(n-x,k,dp), eggDrop(x-1,k-1,dp))+1;
        if(minNo > no) {
            minNo = no;
        }
    }
    dp[k][n] = minNo;
    return minNo;
}

int main() {
    int n,k;
    cin>>n>>k;
    int **dp = new int*[k+1];
    for(int i=0;i<=k;i++) {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++) {
            dp[i][j] = -1;
        }
    }
    cout<<eggDrop(n,k,dp)<<endl;
    return 0;
}