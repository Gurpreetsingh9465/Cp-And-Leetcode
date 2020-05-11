#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

class DisjollSet {
    public:
        ll *parent;
        ll *size;
        vector<int> rank;
        void make_set(ll v) {
            parent[v] = v;
            size[v] = 1;
        }
        DisjollSet(ll N, vector<int> rank) {
            this->rank = rank;
            parent = new ll[N+1];
            size = new ll[N+1];
            for(ll i=1;i<=N;i++) {
                make_set(i);
            }
        }
        ll find_set(ll v) {
            if (v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }
        ll getSize(ll i) {
            ll a = find_set(i);
            return size[a];
        }
        void union_sets(ll a, ll b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if(rank[a] < rank[b]) {
                    parent[a] = b;
                } else if(rank[a] > rank[b]) {
                    parent[b] = a;
                } else {
                    parent[a] = b;
                    size[b]+=size[a];
                }
            }
        }
        ~DisjollSet() {
            delete[] parent;
            delete[] size;
        }
};


void solve() {
    int N,M;
    cin>>N>>M;
    vector<int> intel(N+1);
    for(int i = 1;i<=N;i++) {
        cin>>intel[i];
    }
    DisjollSet *dj = new DisjollSet(N, intel);
    for(int i=0;i<M;i++) {
        ll u,v;
        cin>>u>>v;
        dj->union_sets(u,v);
    }

    unordered_map<int, ll> m;
    for(int i=1;i<=N;i++) {
        int par = dj->find_set(i);
        if(m.count(par) == 0) {
            m[par] = dj->size[par];
        }
    }

    ll ans = 1;

    for(auto &i: m) {
        ans = (ans%MOD * i.second%MOD)%MOD;
    }

    cout<<ans<<"\n";
}

int main() {
    fastIO;
    solve();
    return 0;
}


