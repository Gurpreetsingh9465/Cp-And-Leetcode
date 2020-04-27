#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comparator(int left, int right) {
    return left>right;
}

ll calculate(vector<int> A, vector<int> B, int n) {
    ll ans = 0;
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    for(int i =0;i<n;i++) {
        ans+=(min(A[i], B[i]));
    }
    // for(int i=0;i<n;i++) {
    //     int lower = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    //     int upper = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
    //     // cout<<lower<<" "<<upper<<endl;
    //     if(lower == upper) { // A[i] does n't exist;
    //         lower--;
    //     }
    //     if(lower<0) {
    //         ans+=(min(A[i], B[upper]));
    //         B.erase(B.begin()+upper);
    //     } else if(upper>=B.size()) {
    //         ans+=(min(A[i], B[lower]));
    //         B.erase(B.begin()+lower);
    //     } else {
    //         if(A[i]-B[lower] <= B[upper] - A[i]) {
    //             //lower
    //             ans+=(min(A[i], B[lower]));
    //             B.erase(B.begin()+lower);
    //         } else { // upper
    //             ans+=(min(A[i], B[upper]));
    //             B.erase(B.begin()+upper);
    //         }
    //     }
    // }
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> A(n),B(n);
        for(int i = 0;i<n;i++) {
            cin>>A[i];
        }
        for(int i = 0;i<n;i++) {
            cin>>B[i];
        }
        cout<<calculate(A, B, n)<<endl;

    }
    return 0;
}