#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

bool calculate(vector<int> &v, int N, int first) {
    for(int i=first+1;i<N;i++) {
        if(v[i] == 1) {
            if(i-first < 6) {
                return false;
            }
            first = i;
        }
    }
    return true;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        vector<int> v(N);
        bool flag = false;
        int first = 0;
        for(int i=0;i<N;i++) {
            cin>>v[i];
            if(flag == false && v[i] == 1) {
                first = i;
                flag = true;
            }
        }
        if(calculate(v,N,first)) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
        

    }
    return 0;
}


