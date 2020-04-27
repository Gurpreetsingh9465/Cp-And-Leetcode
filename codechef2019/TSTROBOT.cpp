#include<bits/stdc++.h>
using namespace std;

int calculate(string s, int n, int X) {
    unordered_set<int> l;
    l.insert(X);
    for(auto &i: s) {
        if(i == 'R') {
            X+=1;
        } else {
            X-=1;
        }
        l.insert(X);
    }
    return l.size();
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,X;
        cin>>N>>X;
        string s;
        cin>>s;
        cout<<calculate(s,N,X)<<endl;
    }
    return 0;
}