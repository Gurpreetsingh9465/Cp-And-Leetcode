#include<bits/stdc++.h>
using namespace std;

vector<string> getSubsets(string s, int start) {
    int n = s.length();
    if(n-1 == start) {
        return {string(1,s[n-1]), string()};
    }
    vector<string> inter = getSubsets(s,start+1);
    vector<string> ans;

    for(auto i: inter) {
        ans.push_back(i);
        ans.push_back(s[start]+i);
    }
    return ans;
}

int main() {
    vector<string> ans = getSubsets("abc",0);
    for(auto &i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}