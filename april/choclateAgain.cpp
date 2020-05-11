#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


void solve() {
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i = 0;i<N;i++) {
        cin>>v[i];
    }
    for(int i=1;i<N;i++) {
        v[i]+=v[i-1];
    }
    int q;
    cin>>q;
    while (q--) {
        int number;
        cin>>number;
        if(number<=v[0]) {
            cout<<1<<"\n";
            continue;
        }
        int index = upper_bound(v.begin(),v.end(),number)-v.begin();
		if(v[index] == number) {
			cout<<index<<"\n";
			continue;
		}
        cout<<index+1<<"\n";
    }
}

int main() {
    // fastIO;
    // int T;
    // cin>>T;
    // while(T--) {
    solve();
    // }
    return 0;
}


