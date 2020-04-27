#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}
ll findlcm(int arr[], int n) 
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans)));
    return ans; 
} 

int calculate(int N, int M, int arr[]) {
    int s[M+1];
    for(int i=0;i<=M;i++) s[i]=0;
    for(int i=0;i<N;i++) {
        s[arr[i]] = 1;
    }
    int ans = INT_MAX;
    for(int i=0;i<N;i++) {
        if(arr[i]<ans) {
            ans = arr[i];
        }
    }
    ll maximum_lcm = findlcm(arr,N);
    for(int i=1;i<=M;i++) {
        if(s[i] == 0) {
            int a2[2];
            a2[0] = maximum_lcm;
            a2[1] = i;
            int lcm = findlcm(a2, 2);
            if(lcm>maximum_lcm) {
                lcm = maximum_lcm;
                ans = i;
            }
        }
    }
    return ans;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int N,M;
        cin>>N>>M;
        int arr[N];
        for(int i=0;i<N;i++) {
            cin>>arr[i];
        }
        cout<<calculate(N,M,arr)<<"\n";
    }
    
    return 0;
}


