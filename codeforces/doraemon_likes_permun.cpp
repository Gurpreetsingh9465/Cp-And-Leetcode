#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;


void solve() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    vector<pair<int,bool>> freq(n+1,{0,false});
    int count = 0;
    for(int i=1;i<=n;i++) {
        int a = v[i];
        if(freq[a].first == 2) {
            cout<<"0\n";
            return;
        }
        if(freq[a].first == 1) {
            freq[a].second = true;
        }
        freq[a].first+=1;
        if(freq[a].first == 2) {
            count++;
        }
    }
    cout<<count<<"========\n";
    vector<pair<int,int>> ans;
    for(int i=1;i<=n-1;i++) {
        int a = v[i];
        if(count == 0) {
            ans.push_back({i,n-i});
            continue;
        }
        if(freq[a].second == false) {
            continue;
        }
        if(freq[a].first == 2) {
            freq[a].first-=1;
            count-=1;
            continue;
        }
        if(freq[a].second == 1) {
            freq[a].second+=1;
            count+=1;
            continue;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto &i: ans) {
        cout<<i.first<<" "<<i.second<<"\n";
    }

}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


