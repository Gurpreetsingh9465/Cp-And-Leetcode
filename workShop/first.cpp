#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> left, pair<int,int> right) {
    return left.first<right.first;
}

int main() {
    int N,K,Q;
    cin>>N>>K>>Q;
    vector<pair<int,int>> values(N);
    for(int i = 0;i<N;i++) {
        int first, second;
        cin>>first>>second;
        values[i] = {first, second};
    }
    sort(values.begin(), values.end(), comparator);
    unordered_map<int,int> m;
    int startTemp = values[0].first;
    int endTemp = values[values.size()-1].second;
    for(auto i: values) {
        for(int temp = i.first;temp<i.second;temp++) {
            m[temp] += 1;
        }
    }
    for(int q=0;q<Q;q++) {
        int start, end;
        cin>>start>>end;
        int ans = 0;
        for(int temp = start;temp<=end;temp++) {
            if(m[temp] >= K) {
                ans+=1;
            }
        }
        cout<<ans<<endl;
    }

}