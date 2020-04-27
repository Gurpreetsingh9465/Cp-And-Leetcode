#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int digCount(ll N) {
    return ceil(log10(N));
}

ll calculate(ll N, int d) {
    vector<int> v(18);
    int i = 0;
    while (N!=0) {
        int dig = N%10;
        N/=10;
        v[17 - i++] = dig;
    }
    int digC = i;
    int index = 18-digC;
    for(int i = index+1; i<18;i++) {
        if(v[index] > v[i]) {
            index = i;
        }
    }
    ll ans = 0;
    int newC = 0;
    vector<int> selected;
    for(int i = index;i<18;i++) {
        if(v[i] < d) {
            selected.push_back(v[i]);
        }
    }
    

    ans = ans*10 + v[i];
    newC++;
    int rem = digC - newC;
    while (rem--) {
        ans = ans*10 + d;
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        ll N;
        int d;
        cin>>N>>d;
        cout<<calculate(N, d)<<endl;
    }
    return 0;
}