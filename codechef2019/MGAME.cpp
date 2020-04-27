#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int calculate(int N, int p) {
    int M = N%((N/2)+1);
    return (((p-M)*(p-M)) + ((p-N)*((2*p)-N-M)));
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int N, p;
        cin>>N>>p;
        cout<<calculate(N, p)<<endl;
    }
}
