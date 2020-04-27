#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin>>n;
    pair<long long int,long long int> p[n];
    for(long long int i = 0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    long long int s;
    for(s=0;s<63;s++) {
        long long int sum = 0;
        for(long long int i=0;i<n;i++) {
            bitset<62> b(p[i].second&(1<<s));
            if(b.count()%2 != 0) {
                sum+=(-p[i].first);
            } else {
                sum+=(p[i].first);
            }
        }
        if(sum < 0) {
            break;
        }
    }
    cout<<(1<<s)<<endl;
    return 0;
}

// 5
// 17 206
// -6 117
// -2 151
// 9 93
// 6 117