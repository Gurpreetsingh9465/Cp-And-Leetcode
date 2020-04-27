#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int N = s.length();
    string result = "";
    if(N == 0) 
        return result;
    if(N == 1)
        return s;
    if( N == 2) {
        if(s[0] == s[1])
            return s;
        result = s[0];
        return result;
    }
    int table[N][N];
    memset(table, 0, sizeof(table));
    for(int i=0;i<N;i++) {
        table[i][i] = 1;
    }
    int start = 0;
    int end = 0;
    for(int k = 1; k<=N;k++) {
        for(int i = 0; i<N-k ; i++) {
            int j = i+k;
            // cout<<i<<" "<<j<<endl;

            if( s[i] == s[j] && (table[i+1][j-1] == 1 || k == 1) ) {
                table[i][j] = 1;
                start = i;
                end = j;
            }
        }
    }
    for(int i=start;i<=end;i++) {
        result+=s[i];
    }
    return result;
}

int main() {
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<endl;
    return 0;
}