#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int calculate(vector<int> v, int b) {
    sort(v.begin(), v.end());
    int count = 0;
    for(int i=0;i<v.size();i++) {
        if(v[i]<=b) {
            count++;
            b-=v[i];
        } else {
            break;
        }
    }
    return count;
}

int main() {
    // fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N,b;
        cin>>N>>b;
        vector<int> v(N);
        for(int i = 0;i<N;i++) {
            cin>>v[i];
        }
        cout<<"Case #"<<t<<": "<<calculate(v,b)<<" \n";
    }
    return 0;
}