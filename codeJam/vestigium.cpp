#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int main() {
    fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N;
        cin>>N;
        int matrix[N][N];
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>matrix[i][j];
            }
        }
        int trace=0,r=0,c=0;
        for(int i=0;i<N;i++) {
            bool v[N+1] = {false};
            for(int j=0;j<N;j++) {
                if(i == j) {
                    trace+=matrix[i][j];
                }
                v[matrix[i][j]] = true;
            }
            bool flag = true;
            for(int l=1;l<=N;l++) {
                if(v[l] == false) {
                    flag = false;
                    break;
                }
            }
            if(flag == false) {
                r+=1;
            }
        }
        for(int j=0;j<N;j++) {
            bool v[N+1] = {false};
            for(int i=0;i<N;i++) {
                v[matrix[i][j]] = true;
            }
            bool flag = true;
            for(int l=1;l<=N;l++) {
                if(v[l] == false) {
                    flag = false;
                    break;
                }
            }
            if(flag == false) {
                c+=1;
            }
        }
        cout<<"Case #"<<t<<": "<<trace<<" "<<r<<" "<<c<<"\n";
    }
    return 0;
}
