#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int calculate(int N, int M, int arr[]) {
    bool prime[M+1]; 
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=M; p++) {
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=M; i += p) 
                prime[i] = false; 
        } 
    }
    int s[M+1];
    for(int i=0;i<=M;i++) s[i]=0;
    for(int i=0;i<N;i++) {
        s[arr[i]] = 1;
    }
    for(int i=M;i>=1;i--) {
        if(prime[i] == 1 && s[i] == 0) {
            return i;
        }
    }
    return 1;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int N,M;
        cin>>N>>M;
        int arr[N+1];
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        cout<<calculate(N,M,arr)<<"\n";
    }
    
    return 0;
}


