#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const int MOD = 1000000007;

ll fun(ll x,ll y,ll z) {
    return (x&z)*(y&z);
}

void solve2(ll x, ll y, ll l, ll r) {
    ll max_num = INT_MIN;
    ll ans = 0;
    for(int i = l;i<=r;i++) {
        ll cur = fun(x,y,i);
        if(cur>max_num) {
            max_num = cur;
            ans = i;
        }
    }
    cout<<ans<<"\n";
}

ll leftToRight(ll ored, ll r) {
    ll ans = 0;
    ll number = 0;
    int i = 0;
    while (ored) {
        number = number + (1<<i)*(ored&1);
        if(number<=r)
            ans = number;
        ored>>=1;
        i++; 
    }
    return ans;
}

ll rightToLeft(ll ored, ll r) {
    ll ans = 0;
    for(int i=41;i>=1;i--) {
        if(((ored >> (i - 1)) & 1)) {
            ll bit = (1<<(i-1));
            if(ans+bit<=r) {
                ans+=bit;
            }
        }
    }
    return ans;
}

int checkKth(ll n, ll k) {
    ll one = 1;
    ll cur =( n & (one << (k - 1)));
    if(cur) {
        return 1;
    } 
    return 0;
}

ll turnOffK(ll n, ll k) 
{
    if (k <= 0) return n;
    ll one = 1;
    ll offBit = one<<(k-1);
    return (n & ~(offBit)); 
} 
ll turnOnK(ll n, ll k) 
{
    if (k <= 0) return n;
    ll one = 1;
    ll offBit = one<<(k-1);
    n=n+offBit;
    return (n); 
} 


void solve() {
    ll x,y,l,r;
    cin>>x>>y>>l>>r;
    // solve2(x,y,l,r);
    ll ored = x|y;
    if(x == 0 || y == 0) {
        cout<<l<<"\n";
        return;
    }
    if(l<=ored && ored<=r) {
        cout<<ored<<"\n";
        return;
    }
    if(l == r) {
        cout<<l<<"\n";
        return;
    }
    ll possible = 0;
    ll one = 1;
    int j = 0;
    ll max_num = 0;
    ll ans = 0;
    ll extra = 0;
    int start = 41;
    for(int j=41;j>=1;j--) {
        int bitl = checkKth(l,j);
        int bitr = checkKth(r,j);
        if(bitr == 0 && bitl == 0)
            continue;
        if(bitr == 1 && bitl == 1) {
            ll bit = one<<(j-1);
            extra+=bit;
        } else {
            start = j;
            break;
        }
    }
    for(int i=41;i>=(start+1);i--) {
        if(checkKth(ored,i) == 0) {    
            ll one = 1;
            ll bit = (one<<(i-1));
            ored+=bit;
        }
    }
    for(int i = start;i>=1;i--) {
        if(checkKth(r,i) == 1) {
            j = i;
            while (i>=1) {
                ll pow2 = (one<<(i-1));
                possible = possible + pow2;
                i--;
            }
            break;
        }
    }
    possible = possible+extra;
    possible = (possible&ored);
    if(fun(x,y,possible) == 0) {
        cout<<l<<"\n";
        return;
    }
    if(l<=possible && possible<=r) {
        cout<<possible<<"\n";
        return;
    }
    for(j=start;j>=1;j--) {
        if(checkKth(r,j) == 0) {
            possible = turnOffK(possible, j);
        }
        ll cur = turnOffK(possible,j);
        if(cur<=r && cur>=l) {
            ll cur_num = fun(x,y,cur);
            if(cur_num>max_num) {
                max_num = cur_num;
                ans = cur;
            }
        } else {
            if(cur>r) {
                continue;
            }
            for(int i=start;i>=1;i--) {
                if((cur>=l) && (cur<=r)) {
                    break;
                }
                if(checkKth(cur,i) == 0 && checkKth(l,i) == 1) {
                    ll one = 1;
                    ll bit = (one<<(i-1));
                    cur+=bit;
                }
            }
            if(cur<=r && cur>=l) {
                ll cur_num = fun(x,y,cur);
                if(cur_num>max_num) {
                    max_num = cur_num;
                    ans = cur;
                }
            }
        }
    }
    if(fun(x,y,ans) == 0) {
        cout<<l<<"\n";
        return;
    }
    cout<<ans<<"\n";
    


}

// 1 95 36 0 69
// 63
// 69


int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
