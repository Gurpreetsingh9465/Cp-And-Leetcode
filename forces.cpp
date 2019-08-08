#include<bits/stdc++.h>
using namespace std;

int main() {
    int m;
    int n;
    cin>>n>>m;
    pair<int,int> p[m];
    for(int i = 0; i<m; i++) {
        cin>>p[i].first;
        p[i].second = 0;
    }
    p[0].second = n;
    int overflow = 0;
    for(int i = 0;i<m;i++) {
        int left = p[i].second - p[i].first;
        if(left <= 0) {
            continue;
        } else {
            if(left%2 == 0) {
                if(2*i+1 < m) {
                    p[2*i+1].second = left/2;
                } else {
                    overflow += (left/2);
                }
                if(2*i+2 < m) {
                    p[2*i+2].second = left/2;
                } else {
                    overflow += (left/2);
                }
            } else {
                if(2*i+1 < m) {
                    p[2*i+1].second = left/2+1;
                } else {
                    overflow += (left/2+1);
                }
                if(2*i+2 < m) {
                    p[2*i+2].second = left/2;
                } else {
                    overflow += (left/2);
                }
            }
        }
    }
    cout<<overflow<<endl;
    return 0;
}


// 200
// 4
// 100
// 30
// 50
// 20