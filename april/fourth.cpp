#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

ll const MOD = 1000000007;
ll const max_n = 200001;


bool cmp(vector<ll> &a, vector<ll> &b) {
    return a[2] < b[2];
}


class DisjollSet {
    public:
        ll *parent;
        ll *size;
        void make_set(ll v) {
            parent[v] = v;
            size[v] = 1;
        }
        DisjollSet(ll N) {
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
                if (size[a] < size[b])
                    swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
        ~DisjollSet() {
            delete[] parent;
            delete[] size;
        }
};

void solve() {
    ll N;
    cin>>N;
    vector<vector<ll>> graph(N-1);

    for(ll i = 0;i<N-1;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[i] = {a,b,c};
    }
    DisjollSet d(N);
    sort(graph.begin(), graph.end(), cmp);
    ll ans = 0;

    for(auto &i: graph) {
        ans = (ans%MOD + (i[2]%MOD*(d.getSize(i[0])%MOD*d.getSize(i[1])%MOD)%MOD)%MOD)%MOD;
        d.union_sets(i[0], i[1]);
    }

    cout<<ans<<"\n";
}

int main() {
    fastIO;
    ll T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}


