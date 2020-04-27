#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
void solve(int n) 
{ 
    if(n == 1) {
        cout<<"1\n1 1\n";
        return;
    }
    // bool prime[n+1];
    // memset(prime, true, sizeof(prime));
    // for (int p=2; p*p<=n; p++) {
    //     if (prime[p] == true) {
    //         for (long long i=p*2; i<=n; i += p)
    //             prime[i] = false;
    //     }
    // }
    cout<<n/2<<"\n";
    for(int i = 1;i<((n&1)?n-3:n);i+=2) {
        cout<<"2 "<<i<<" "<<i+1<<"\n";
    }
    if(n&1) {
        cout<<"3 "<<n-2<<" "<<n-1<<" "<<n<<"\n";
    }
    return;

}
int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int N;
        cin>>N;
        solve(N);
    }
    
    return 0;
}


