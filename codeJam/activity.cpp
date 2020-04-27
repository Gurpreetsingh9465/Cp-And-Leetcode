#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

bool compare(pair<pair<int,int>,int> &l, pair<pair<int,int>,int> &r) {
    return l.first.first<r.first.first;
}

string calculate(vector<pair<pair<int,int>,int>> &activities, int N) {
    char ans[N] = {'\n'};
    pair<int,int> lastc = {-1,-1},lastj = {-1,-1};
    sort(activities.begin(), activities.end(), compare);
    for(auto &activity: activities) {
        if(lastc.first == -1) {
            lastc = activity.first;
            ans[activity.second] = 'C';
        } else if(lastc.second <= activity.first.first) {
            lastc = activity.first;
            ans[activity.second] = 'C';
        } else if (lastj.first == -1) {
            lastj = activity.first;
            ans[activity.second] = 'J';
        } else if(lastj.second <= activity.first.first) {
            lastj = activity.first;
            ans[activity.second] = 'J';
        } else {
            return "IMPOSSIBLE";
        }
    }
    string res = "";
    for(int i=0;i<N;i++) {
        res+=ans[i];
    }
    return res;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N;
        cin>>N;
        vector<pair<pair<int,int>,int>> v(N);
        for(int i=0;i<N;i++) {
            int s,e;
            cin>>s>>e;
            v[i] = {{s,e},i};
        }
        cout<<"Case #"<<t<<": "<<calculate(v,N)<<"\n";
    }
    return 0;
}
