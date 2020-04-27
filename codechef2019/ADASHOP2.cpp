#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> calculate(int r, int c) {
    vector<pair<int,int>> ans = {{0,0},{1,1},{0,2},{2,0},{1,1},{2,2},
    {0,4},{4,0},{2,2},{3,3},{0,6},{6,0},
    {3,3},{4,4},{1,7},{7,1},{4,4},{5,5},
    {3,7},{7,3},{5,5},{6,6},{5,7},{7,5},{6,6},{7,7}};
    if(r==c) {
        ans.insert(ans.begin(), {r,c});
    } else {
        int toAdd = abs(r-c)/2;
        pair<int,int> added = {r,c};
        if(r>c) {
            added = {r-toAdd, c+toAdd};
        } else {
            added = {r+toAdd, c-toAdd};
        }
        ans.insert(ans.begin(),added);
        ans.insert(ans.begin(), {r,c});
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int r,c;
        cin>>r>>c;
        vector<pair<int,int>> ans = calculate(r-1, c-1);
        cout<<ans.size()<<endl;
        for(auto &i: ans) {
            cout<<i.first+1<<" "<<i.second+1<<endl;
        }
    }
    return 0;
}


