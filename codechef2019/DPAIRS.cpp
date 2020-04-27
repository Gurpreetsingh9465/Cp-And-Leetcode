#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

bool comparator(pair<ll, int> left, pair<ll, int> right) {
    return left.first<right.first;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int N,M,x;
        cin>>N>>M;
        vector<pair<ll, int>> A(N), B(M);
        for(int i = 0;i<N;i++) {
            cin>>x;
            A[i] = {x,i};
        }
        for(int i = 0;i<M;i++) {
            cin>>x;
            B[i] = {x,i};
        }
        sort(A.begin(), A.end(), comparator);
        sort(B.begin(), B.end(), comparator);
        ll i=0,j=0;
        while(i<N&&j<M) {
            cout<<A[i].second<<" "<<B[j].second<<endl;
            if(A[i].first<B[j].first)
            i++;
            else
            j++;
        }
        if(i<N) {
            i++;j--;
            while(i<N) {
                cout<<A[i++].second<<" "<<B[j].second<<endl;
            }
        }
        else if(j<M) {
            i--;j++;
            while(j<M) {
                cout<<A[i].second<<" "<<B[j++].second<<endl;
            }
        } 
    }
    return 0;
    
}
