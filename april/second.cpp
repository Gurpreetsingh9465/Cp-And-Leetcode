#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


bool isDivisible(string N, int l, int r, vector<vector<int>> &prefixarr) {
    int ele = ((r-l)%6);
    int num = prefixarr[ele][r] - (l-1<0?0:prefixarr[ele][l-1]);
    if(num%7 == 0) {
        return true;
    }
    return false;
}

void solve() {
    string N;
    int Q;
    cin>>N;
    int n = N.size();
    vector<int> mul1 = {5,4,6,2,3,1};
    vector<vector<int>> prefixarr(6);
    for(int i=0;i<6;i++) {
        int cur = 0;
        for(int j=0;j<N.size();j++) {
            int num = N[j]-'0';
            num*=mul1[(i+j)%6];
            cur+=num;
            prefixarr[i].push_back(cur);
        }
    }

    cin>>Q;
    while (Q--) {
        int l,r;
        cin>>l>>r;
        l-=1;
        r-=1;
        if(isDivisible(N,l,r,prefixarr)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}


