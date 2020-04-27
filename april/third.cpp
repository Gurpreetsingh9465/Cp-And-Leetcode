#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

ll const max_n = 500001;
ll const MOD = 1000000007;

bool primes[max_n];
ll gcdSum[max_n];
ll smallestPrime[max_n];

class SegmentTree {
    public:
    ll arr_size;
    ll *tree;
    SegmentTree(vector<ll> &v) {
        this->arr_size = v.size();
        tree = new ll[arr_size*2];
        for(ll i=0;i<v.size();i++) {
            tree[i+arr_size] = v[i];
        }
        tree[0] = 0;
        for(ll i=v.size()-1;i>0;i--) {
            tree[i] = tree[2*i]+tree[(2*i+1)];
        }
    }
    void prllTree() {
        for(ll i = arr_size;i<2*arr_size;i++) {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    void update(ll index, ll val) {
        index+=arr_size;
        tree[index]=val;
        index/=2;
        while (index>=1) {
            tree[index] = tree[2*index]+tree[(2*index+1)];
            index/=2;
        }
    }

    ll query(ll l, ll r) {
        l+=arr_size;
        r+=(arr_size+1);
        ll ans = 0;
        while (l<r) {
            if(l&1) {
                ans= (ans%MOD+tree[l]%MOD)%MOD;
                l+=1;
            }
            if(r&1) {
                r-=1;
                ans= (ans%MOD+tree[r]%MOD)%MOD;
            }
            l/=2;
            r/=2;
        }
        return ans%MOD;   
    }
};

/*
gcd_sum[m * n] = gcd_sum[m] * gcd_sum[n]
Powers e of primes p:

gcd_sum[p^e] = (e + 1) * p^e - e * p^(e - 1)
*/

ll power(ll a, ll b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;   
}


void seive() {
    memset(primes,0,sizeof(primes));
    memset(gcdSum,0, sizeof(gcdSum));
    memset(smallestPrime, 0, sizeof(smallestPrime));
    vector<bool> isPrime(max_n, true);
    for(ll i=2;i*i<=max_n;i++) {
        if (isPrime[i] == true) 
        {
            for (ll j=i*i; j<=max_n; j += i) 
                isPrime[j] = false; 
        }
    }
    

    for(ll i=2;i<=max_n;i+=2) {
        smallestPrime[i] = 2;
    }
    for(ll i=3;i<=max_n;i+=2) {
        if(primes[i] == false) {
            smallestPrime[i] = i;
            for(ll j=i;j*i<=max_n;j+=2) {
                if(primes[j*i] == false) {
                    smallestPrime[j*i] = i;
                    primes[j*i] = true;
                }
            }
        }
    }
    gcdSum[1] = 1;

    for(ll i=2;i<=max_n;i++) {
        if(isPrime[i]) {
            gcdSum[i] = ((i)%MOD+(i-1)%MOD)%MOD;
        } else {
            ll x=i;
            ll curr = smallestPrime[x];
            ll cnt = 1;
            ll ans = 0;
            while (x > 1) 
            { 
                x /= smallestPrime[x]; 
                if (curr == smallestPrime[x]) 
                { 
                    cnt++; 
                    continue; 
                }
                ll ppowe = power(curr,cnt);
                if(gcdSum[ppowe] == 0) {
                    gcdSum[ppowe] = ((cnt+1)%MOD*ppowe)%MOD - (cnt%MOD*(ppowe/curr)%MOD)%MOD;
                }
                if(ans == 0) {
                    ans = gcdSum[ppowe];
                } else {
                    ans = (ans*gcdSum[ppowe]%MOD)%MOD;
                }
                curr = smallestPrime[x]; 
                cnt = 1; 
            }
            gcdSum[i]= ans;
            
        }
    }

}


ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b,a%b);
}

ll F(ll x) {
    return gcdSum[x];
}

void solve() {
    ll N;
    cin>>N;
    vector<ll> arr(N);
    for(ll i= 0;i<N;i++) {
        cin>>arr[i];
    }
    vector<ll> gcds(N);
    for(ll i = 0;i<N;i++) {
        gcds[i] = F(arr[i]);
    }
    SegmentTree *t = new SegmentTree(gcds);
    ll Q;
    cin>>Q;
    while (Q--) {
        char type;
        ll x,y;
        cin>>type>>x>>y;
        if(type == 'C') {
            x-=1;
            y-=1;
            cout<<t->query(x,y)<<"\n";
        } else if(type == 'U') { 
            x-=1;
            ll updateTo = F(y);
            t->update(x,updateTo);
        }
    }
}

int main() {
    seive();
    solve();
    return 0;
}


