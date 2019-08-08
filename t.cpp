#include<bits/stdc++.h>
using namespace std;
#define lli long long
const lli N = 100000;

lli countOnes(lli n) {
    return __builtin_popcount (n);
}

class node {
    public:
        lli X;
        lli count;
        node(lli X) {
            this->X=X;
            this->count = countOnes(X);
        }
        void update(lli X) {
            this->X=X;
            this->count = countOnes(X);
        }
};

int main() {
    int T;
    cin>>T;
    while(T--) {
        int Q;
        cin>>Q;
        lli s[N];
        lli n = -1;
        for(int q=0;q<Q;q++) {
            lli data;
            cin>>data;
            lli l = n;
            for(lli i=0;i<=l;i++) {
                s[++n] = s[i]^data;
            }
            s[++n] = data;
            lli E,O;
            E=O=0;
            for(lli i=0;i<=n;i++) {
                lli count = countOnes(s[i]);
                if(count%2==0)
                    E+=1;
                else
                    O+=1;
            }
            cout<<E<<" "<<O<<endl;
        }
    }
    return 0;
}