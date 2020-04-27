#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int M,N;
        cin>>N>>M;
        vector<int> f(N);
        vector<int> p(N);
        int index = 0;
        for(int i = 0;i<N;i++) {
            cin>>f[index++];
        }
        index = 0;
        for(int i = 0;i<N;i++) {
            cin>>p[index++];
        }
        index = 0;
        vector<pair<int,int>> total(M);
        for(int i=0; i< N;i++) {
            total[f[i]-1].first = total[f[i]-1].first + p[i];
            total[f[i]-1].second+=1;
        }
        int ans = INT_MAX;
        for(int i=0;i<M;i++) {
            if(total[i].second != 0 && total[i].first < ans) {
                ans = total[i].first;
            }
        }
        // for(auto &i: total) {
        //     cout<<i<<endl;
        // }
        cout<<ans<<endl;
    }
}