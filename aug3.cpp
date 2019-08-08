#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,D;
	cin>>T;
	while(T--) {
	    int N;
	    cin>>N;
	    int C[N];
	    int Z[N];
	    for(int i = 0;i<N;i++) {
	        cin>>C[i];
	    }
	    for(int i = 0;i<N;i++) {
	        cin>>Z[i];
	    }
	    int R[N];
	    memset(R,0,sizeof(R));
	    for(int i = 0; i<N;i++) {
            R[i] += 1;
	        for(int j=1;j<=C[i];j++) {
	            if(i-j >= 0) {
	                R[i-j] += 1;
	            }
	            if(i+j < N) {
	                R[i+j] += 1;
	            }
	        }
	    }
        map<int,int> m;
        for(int i =0;i<N;i++) {
            if(m.find(R[i]) != m.end()) {
                m[R[i]] += 1;
            } else {
                m[R[i]] = 1;
            }
        }
        for(int i = 0;i<N;i++) {
            if(m.find(Z[i]) != m.end()) {
                m[Z[i]] -= 1;
                if(m[Z[i]] == 0) {
                    m.erase(Z[i]);
                }
            } else {
                break;
            }
        }
        if(m.size() == 0) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        
        cout<<endl;
	}
	return 0;
}
