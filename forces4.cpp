#include <bits/stdc++.h>
using namespace std;

int countDigit(long long n) { 
    return floor(log10(n) + 1); 
} 
int main() {
	long long T;
	cin>>T;
	while(T--) {
	    long long K;
	    cin>>K;
	    long long count = 0;
	    long long up = pow(10,K);
	    for(long long i = 0;i<up;i++) {
	        long long size = countDigit(i) + countDigit();
            if(size == 2) {
                count++;
            }
	    }
        cout<<((count)%1000000009)<<endl;
	}
	return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	long long T;
// 	cin>>T;
// 	while(T--) {
// 	    long long K;
// 	    cin>>K;
// 	    long long count = 10*pow(2,K-1);
//         cout<<((count)%1000000007)<<endl;
// 	}
// 	return 0;
// }
