#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

void solve() {
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i = 0;i<N;i++) {
        cin>>v[i];
    }
    int min_num = INT_MAX;
    int max_num = 1;
    int cur = 1;
    for(int i = 1;i<N;i++) {
        if(v[i-1] + 2 >= v[i]) {
            cur++;
        } else {
            min_num = min(cur, min_num);
            max_num = max(max_num, cur);
            cur = 1;
        }
    }
    min_num = min(cur, min_num);
    max_num = max(max_num, cur);
    // if(min_num == INT_MAX) {
    //     min_num = 1;
    // }
    cout<<min_num<<" "<<max_num<<"\n";
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}


