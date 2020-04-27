#include<bits/stdc++.h>
using namespace std;
#define ll long long int;

bool comparator(pair<int,int> left, pair<int,int> right) {
    return right.first<left.first;
}

bool isAllZero(vector<int> &v) {
    for(auto &i: v) {
        if(i!=0){
            return false;
        }
    }
    return true;
}

vector<int> calculate(vector<pair<int,int>> &v,int val) {
    int P = val;
    vector<int> res(v.size());
    if(v.size() == 1) {
        if(P%v[0].first == 0) {
            return {0};
        } else {
            return {(P/v[0].first)+1};
        }
    }
    sort(v.begin(), v.end(),comparator);
    if(v.size() == 2 && v[1].first == 1) {
        if(P%v[0].first == 0) {
            return {0 , 0};
        } else {
            vector<int> newV(2);
            newV[v[0].second] = (P/v[0].first)+1;
            return newV;
        }
    }
    if(v[0].first > P) {
        res[v[0].second] = 1;
        return res;
    } else if(v[0].first <= P) {
        for(auto &i: v) {
            if(i.first == P || i.first == 1)
                continue;
            else if(P%i.first == 0) {
                int a = P/i.first - 1;
                res[i.second] = a;
                P-=a*i.first;
            } else {
                int a = P/i.first + 1;
                res[i.second] = a;
                P-=a*i.first;
            }
            if(P<0)
                break;
        }
    }
    int ans = 0;
    for(auto &i: v) {
        ans+=(i.first*res[i.second]);
    }
    if(ans<=val) {
        vector<int> res(v.size());
        return res;
    }
    return res;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,P;
        cin>>N>>P;
        vector<pair<int,int>> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i].first;
            v[i].second = i;
        }
        vector<int> ans =  calculate(v, P);
        if(isAllZero(ans)) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES ";
            for(auto &i: ans) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

