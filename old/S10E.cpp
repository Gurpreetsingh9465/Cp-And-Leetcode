#include <bits/stdc++.h>
using namespace std;

class cmp {
    public:
        bool operator() (int l, int r) {
            return r<l;
        }
};

int fun(int arr[], int n) {
    if(n <= 5) {
        return 1;
    }
    int ans = 1;
    priority_queue<int, vector<int>,cmp> Q;
    for(int i = 0;i<5;i++) {
        Q.push(arr[i]);
    }
    for(int i = 5;i<n;i++) {
        int t = Q.top();
        Q.pop();
        Q.push(arr[i]);
        if(t>arr[i]) {
            ans+=1;
        }
    }
    return ans;
}

int main() {
	int T;
	cin>>T;
	while(T--) {
	    int N;
	    cin>>N;
	    int prices[N];
	    for(int i = 0;i<N;i++) {
	        cin>>prices[i];
	    }
	    cout<<fun(prices,N)<<endl;
	}
	return 0;
}
