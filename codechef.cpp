#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,D;
	cin>>T;
	while(T--) {
	    cin>>D;
	    string s;
	    cin>>s;
	    int minAtt = ceil(0.75*D);
	    int proxy = 0;
	    for(int i = 0;i<D;i++) {
	        if(i<2 || i>(D-2)) {
	            if(s[i] == 'P')
	                minAtt-=1;
	            continue;
	        }
	        if(s[i] == 'P') {
	            minAtt-=1;
	        } else {
	            if((s[i-1] == 'P' || s[i-2] == 'P') && (s[i+1] == 'P' || s[i+2] == 'P')) {
	                proxy+=1;
	                minAtt-=1;
	            }
	        }
	
	    }
	    if(minAtt <= 0) {
	        cout<<(proxy+minAtt)<<endl;
	    } else {
	        cout<<-1<<endl;
	    }
	    
	}
	return 0;
}
