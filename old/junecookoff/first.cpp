#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
	    int N;
        cin>>N;
        string S,U;
        cin>>S;
        cin>>U;
        int score = 0;
        for(int i = 0; i<S.length();i++) {
            if(U[i] == 'N') {
                continue;
            } else if(S[i] == U[i]) {
                score += 1;
            } else {
                i+=1;
            }
        }
        cout<<score<<endl;
	}
	return 0;
}