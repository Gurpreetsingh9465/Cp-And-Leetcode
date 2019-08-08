#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {
	int T,D;
	cin>>T;
	while(T--) {
	    int N;
	    cin>>N;
	    int A[N];
	    for(int i=0;i<N;i++) {
	        cin>>A[i];
	    }
        if(N == 2) {
            cout<<(A[0] + A[1])<<endl;
        } else  {
            
        }
	}
	return 0;
}
