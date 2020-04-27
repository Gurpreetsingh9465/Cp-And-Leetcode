#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

vector<ll> calculate(ll u, ll v) {
    int elements_and = v-u; 
    if(elements_and<0) {
        return {};
    } else if(elements_and == 0) {
        return {v};
    } else {

    }
}

int main() {
    fastIO;
    ll u,v;
    cin>>u>>v;
    vector<ll> ans = calculate(u,v);
    if(ans.size()>0) {
        cout<<ans.size()<<'\n';
        for(auto &i: ans) {
            cout<<i<<" ";
        }
        cout<<"\n";
    } else {
        cout<<"-1\n";
    }
    return 0;
}


