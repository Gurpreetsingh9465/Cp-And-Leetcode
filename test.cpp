#include <bits/stdc++.h>
using namespace std;

int main() {
	long long T;
	cin>>T;
	while(T--) {
	    long long K;
	    cin>>K;
	    long long count = 0;
	    long long up = pow(10,K);
	    long long maxI = up/2;
	    int TotalCount = 0;
	    for(long long i = 0;i<maxI;i++){
	        int count = 0;
	        bool p[10];
	        memset(p,false,sizeof(p));
            long long x = i;
            if(x == 0) {
                p[0] = true;
                count++;
            } else {
                 while(x!=0) {
                    int dig = x%10;
                    if(p[dig] == false) {
                        p[dig] = true;
                        count += 1;
                        if(count > 2) {
                            continue;
                        }
                    }
                    x/=10;
                }
            }
            if(count > 2) {
                continue;
            }
            x = up-1-i;
            if(x == 0) {
                p[0] = true;
                count++;
            } else {
                 while(x!=0) {
                    int dig = x%10;
                    if(p[dig] == false) {
                        p[dig] = true;
                        count += 1;
                        if(count > 2) {
                            continue;
                        }
                    }
                    x/=10;
                }
            }
            if(count == 2) {
                TotalCount++;
            }
	    }
        cout<<(TotalCount*2)<<endl;
	}
	return 0;
}
