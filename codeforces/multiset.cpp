#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int N = 1e6+48576;

int p[2*N];

void inc(int index, int x) {
    index += N-1;
    p[index] += x;
    for(index/=2;index>=1;index/=2) {
        p[index] = p[index*2]+p[index*2+1];
    }
}

void find(int c) {
    int k = 1;
    while (k<N) {
        if(c<=p[2*k]) {
            k = 2*k;
        } else {
            c-=p[2*k];
            k=2*k+1;
        }
    }
    inc(k-N+1,-1);
}

void solve() {
    memset(p,0,sizeof(p));
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        inc(a,1);
    }
    while (k--) {
        int a;
        cin>>a;
        if(a>0) {
            inc(a,1);
        } else {
            a = abs(a);
            find(a);
        }
    }
    for (int i = 0; i < N; i++) {
		if (p[N+i]) {
			cout << i + 1 << "\n";
			return;
		}
	}
    cout<<"0\n";
    return;
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        solve();
    
    return 0;
}


