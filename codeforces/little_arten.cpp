#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int max_n = 1e5+5;

void solve() {
    int n,m;
    cin>>n>>m;
    int w,b;
    if((n*m)&1) {
        w = ((n*m)/2);
        b = w+1;
    } else {
        w = ((n*m)/2)-1;
        b = w+2;
    }
    
    bool turn = false;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m;j++) {
            if(b>0 && turn) {
                cout<<"B";
                b--;
            } 
            if(w>0 && !turn) {
                cout<<"W";
                w--;
            }
            turn = !turn;
        }
        cout<<"\n";
    }
    turn = !turn;
    while (w>0 || b>0) {
        if(turn) {
            if(b>0) {
                cout<<'B';
                b--;
            }
            if(w>0) {
                cout<<'W';
                w--;
            }
        } else {
            if(w>0) {
                cout<<'W';
                w--;
            }

            if(b>0) {
                cout<<'B';
                b--;
            }
        }
        
    }
    cout<<"\n";
    
    
}


int main() {
    #ifdef ONLINE_JUDGE
        fastIO;
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while (T--) {
        solve();
    }
    
    return 0;
}


