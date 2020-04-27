#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

inline ll modular_inverse(ll a, ll m) {
    ll m1 = m;
    ll y = 0, x = 1;
    if (m == 1) {
        return 0;
    }
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m1;
    }
    return x;
}

ll evalSolve(ll p, ll q) {
    return ((long long)p * modular_inverse(q, MOD) % MOD);
}

vector<ll> evalXor(vector<ll> &v1,vector<ll> &v2) {
    vector<ll> ans(4);
    ans[0] = (((v1[0]%MOD)*(v2[0]%MOD))%MOD + ((v1[1]%MOD)*(v2[1]%MOD))%MOD + ((v1[2]%MOD)*(v2[2]%MOD))%MOD + ((v1[3]%MOD)*(v2[3]%MOD))%MOD)%MOD;
    ans[1] = (((v1[0]%MOD)*(v2[1]%MOD))%MOD + ((v1[1]%MOD)*(v2[0]%MOD))%MOD + ((v1[2]%MOD)*(v2[3]%MOD))%MOD + ((v1[3]%MOD)*(v2[2]%MOD))%MOD)%MOD;
    ans[2] = (((v1[0]%MOD)*(v2[2]%MOD))%MOD + ((v1[1]%MOD)*(v2[3]%MOD))%MOD + ((v1[2]%MOD)*(v2[0]%MOD))%MOD + ((v1[3]%MOD)*(v2[1]%MOD))%MOD)%MOD;
    ans[3] = (((v1[0]%MOD)*(v2[3]%MOD))%MOD + ((v1[1]%MOD)*(v2[2]%MOD))%MOD + ((v1[2]%MOD)*(v2[1]%MOD))%MOD + ((v1[3]%MOD)*(v2[0]%MOD))%MOD)%MOD;


    // ans[0] = v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2] + v1[3]*v2[3];
    // ans[1] = v1[0]*v2[1] + v1[1]*v2[0] + v1[2]*v2[3] + v1[3]*v2[2];
    // ans[2] = v1[0]*v2[2] + v1[1]*v2[3] + v1[2]*v2[0] + v1[3]*v2[1];
    // ans[3] = v1[0]*v2[3] + v1[1]*v2[2] + v1[2]*v2[1] + v1[3]*v2[0];
    return ans;
}

vector<ll> evalAnd(vector<ll> &v1,vector<ll> &v2) {
    vector<ll> ans(4);
    ans[0] = (((v1[0]%MOD) * (v2[0]%MOD+v2[1]%MOD+v2[2]%MOD+v2[3]%MOD)%MOD)%MOD + ((v1[1]%MOD)*(v2[0]%MOD))%MOD + ((v1[2]%MOD)*((v2[0]%MOD+v2[3]%MOD)%MOD))%MOD + ((v1[3]%MOD)*((v2[0]%MOD+v2[2]%MOD)%MOD))%MOD)%MOD;
    ans[1] = ((v1[1]%MOD) * (v2[1]%MOD))%MOD;
    ans[2] = (((v1[1]%MOD)*(v2[2]%MOD))%MOD + ((v1[2]%MOD)*(v2[1]%MOD))%MOD + ((v1[2]%MOD) * (v2[2]%MOD))%MOD)%MOD;
    ans[3] = (((v1[1]%MOD)*(v2[3]%MOD))%MOD + ((v1[3]%MOD)*(v2[1]%MOD))%MOD + ((v1[3]%MOD) * (v2[3]%MOD))%MOD)%MOD;
    return ans;
}

vector<ll> evalOr(vector<ll> &v1,vector<ll> &v2) {
    vector<ll> ans(4);
    ans[0] = (((v1[0]%MOD) * (v2[0]%MOD))%MOD)%MOD;
    ans[1] = ((((v1[0]%MOD) * (v2[1]%MOD)))%MOD + ((v1[1]%MOD)*((v2[0]%MOD+v2[1]%MOD+v2[2]%MOD+v2[3]%MOD)%MOD))%MOD + (v1[2]%MOD*((v2[1]%MOD+v2[3]%MOD)%MOD))%MOD + ((v1[3]%MOD)*((v2[1]%MOD+v2[2]%MOD)%MOD))%MOD)%MOD;
    ans[2] = (((v1[0]%MOD) * (v2[2]%MOD))%MOD + ((v1[2]%MOD)*(v2[0]%MOD))%MOD + ((v1[2]%MOD) * (v2[2]%MOD))%MOD)%MOD;
    ans[3] = (((v1[0]%MOD) * (v2[3]%MOD))%MOD + ((v1[3]%MOD)*(v2[0]%MOD))%MOD + ((v1[3]%MOD) * (v2[3]%MOD))%MOD)%MOD;
    return ans;
}


void solve() {
    string L;
    cin>>L;
    ll number_hash = 0;
    for(auto &i: L) {
        if(i == '#')
            number_hash += 1;
    }
    stack<vector<ll>> st;
    for(int i = 0;i<L.length();i++) {
        if(L[i] == ')') {
            while (true) {
                vector<ll> v1 = st.top();
                st.pop();
                vector<ll> o = st.top();
                if(o[0] == -3) {
                    st.pop();
                    st.push(v1);
                    break;
                }
                st.pop();
                vector<ll> v2 = st.top();
                st.pop();
                vector<ll> evalRes;
                if(o[0] == 0) {
                    evalRes = evalAnd(v1,v2);
                } else if(o[0] == -1) {
                    evalRes = evalOr(v1,v2);
                } else if(o[0] == -2) {
                    evalRes = evalXor(v1,v2);
                }
                if(st.top()[0] == -3) {
                    st.pop();
                    st.push(evalRes);
                    break;
                }
                st.push(evalRes);
            }
        } else {
            if(L[i] == '#') {
                vector<ll> v(4,1);
                st.push(v);
            } else {
                if(L[i] == '&') {
                    vector<ll> v(4,0);
                    st.push(v);
                } else if(L[i] == '|') {
                    vector<ll> v(4,-1);
                    st.push(v);
                } else if(L[i] == '^') {
                    vector<ll> v(4,-2);
                    st.push(v);
                } else {
                    vector<ll> v(4,-3);
                    st.push(v);
                }
            }
        }   
    }
    while (st.size() > 1) {
        vector<ll> v1 = st.top();
        st.pop();
        vector<ll> o = st.top();
        st.pop();
        vector<ll> v2 = st.top();
        st.pop();
        if(o[0] == 0) {
            st.push(evalAnd(v1,v2));
        } else if(o[0] == -1) {
            st.push(evalOr(v1,v2));
        } else {
            st.push(evalXor(v1,v2));
        }
    }
    vector<ll> ans = st.top();
    ll count_0 = ans[0], count_1 = ans[1], count_a = ans[2], count_A = ans[3];
    ll q = 1;
    for(int i=0;i<number_hash;i++) {
        q=q%MOD*4;
        q=q%MOD;
    }
    cout<<count_0<<" "<<count_1<<" "<<count_a<<" "<<count_A<<"\n";

    // cout<<evalSolve(count_0,q)<<" "<<evalSolve(count_1,q)<<" "<<evalSolve(count_a,q)<<" "<<evalSolve(count_A,q)<<"\n";

}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}



