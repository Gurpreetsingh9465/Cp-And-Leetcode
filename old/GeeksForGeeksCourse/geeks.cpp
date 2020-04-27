#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        int *arr = new int[N];
        for(int i = 0;i<N;i++) 
            cin>>arr[i];
        int sum = 0;
        if(N==1){
            cout<<1<<endl;
            break;
        }
        for(int i = 0;i<N;i++) 
            sum+=arr[i];
        int i = 0;
        int suml = arr[0];
        for(i = 1;i<N;i++) {
            if(suml == (sum-suml-arr[i])) {
                break;
            }
            suml+=arr[i];
        }
        if(i == N) {
            cout<<-1<<endl;
        } else {
            cout<<i+1<<endl;
        }
        
    }
	return 0;
}