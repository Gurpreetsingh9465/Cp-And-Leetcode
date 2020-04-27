#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 100001

int spf[MAXN];

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

int getMinNo(int val) {
    unordered_map<int,int> number;
    while (val != 1) 
    { 
        number[spf[val]] += 1;
        val = val / spf[val]; 
    } 
    int ans = 1;
    for(auto &i: number) {
        ans = ans*(i.second&1?i.first:1);
    }
    return ans; 
}

ll calculate(vector<ll> x, vector<ll> y) {
    ll ans = 0;
    unordered_map<ll, int> xfreq;
    unordered_map<ll, int> yfreq;
    bool isZeroX = false, isZeroY = false;
    ll yNegCount = 0, yPosCount = 0, xNegCount = 0, xPosCount = 0;
    for(auto &i: x) {
        if(i<0) {
            xNegCount++;
        } else if(i>0) {
            xPosCount++;
        }
        xfreq[i*i] += 1;
    }
    for(auto &i: y) {
        if(i<0) {
            yNegCount++;
        } else if(i>0) {
            yPosCount++;
        }
        yfreq[i*i] += 1;
    }
    vector<ll> xPositive(xPosCount);
    unordered_set
    <ll> xNegetive;
    ll xPosIndex=0;
    ll xNegIndex=0;
    for(auto &i: x) {
        if(i<0) {
            xNegetive.insert(i*-1);
        } else if(i>0) {
            xPositive[xPosIndex++] = i;
        } else {
            isZeroX = true;
        }
    }
    for(auto &i : xPositive) {
        int minEle = getMinNo(i);
        for(int j=1;j*j*minEle<=MAXN;j++) {
            int ele = j*j*minEle;
            if(xNegetive.find(ele) != xNegetive.end()) {
                ans+=yfreq[i*ele];
            }
        }
    }
    vector<ll> yPositive(yPosCount);
    unordered_set<ll> yNegetive;
    ll yPosIndex=0;
    ll yNegIndex=0;
    for(auto &i: y) {
        if(i<0) {
            yNegetive.insert(i*-1);
        } else if(i>0) {
            yPositive[yNegIndex++] = i;
        } else {
            isZeroY = true;
        }
    }
    for(auto &i : yPositive) {
        int minEle = getMinNo(i);
        for(int j=1;j*j*minEle<=MAXN;j++) {
            int ele = j*j*minEle;
            if(yNegetive.find(ele) != yNegetive.end()) {
                ans+=xfreq[i*ele];
            }
        }
    }
    if(isZeroY && isZeroX) {
        ans+=((x.size()-1) * (y.size() - 1));
    } else if(isZeroY) {
        ans+=((x.size()) * (y.size() - 1));
    } else if(isZeroX) {
        ans+=((x.size()-1) * (y.size()));
    }
    return ans;
}

int main() {
    sieve();
    ll T;
    cin>>T;
    while(T--) {
        ll N,M;
        cin>>N>>M;
        vector<ll> x(N), y(M);
        for(ll i = 0;i<N;i++) {
            cin>>x[i];
        }
        for(ll i = 0;i<M;i++) {
            cin>>y[i];
        }

        cout<<calculate(x,y)<<endl;
    }
    return 0;
}