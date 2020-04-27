#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,Q;
        scanf("%d%d",&N,&Q);
        int v;
        int numberOfOdd = 0;
        int numberOfEven = 0;
        for(int i = 0;i<N;i++) {
            cin>>v;
            int setBit = __builtin_popcount(v);
            if(setBit&1) {
                numberOfOdd+=1;
            } else { 
                numberOfEven+=1;
            }
        }

        for(int i = 0;i<Q;i++) {
            int q;
            scanf("%d",&q);
            int setBits = __builtin_popcount(q);
            if(setBits&1) {
                printf("%d %d\n", numberOfOdd, numberOfEven);
            } else {
                printf("%d %d\n", numberOfEven, numberOfOdd);
            }
        }
    }
}