#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int calculate(int A, int B) {
    if(A<=9 && B<=9) {
        return A+B;
    }
    if(A<=9) {
        
    }
    int arrA[10], arrB[10];
    for(int i=0;i<9;i++) {
        arrA[i] = 0;
        arrB[i] = 0;
    }
    int n = A;
    while (n) {
        arrA[n%10] = 1;
        n/=10;
    }
    n = B;
    while (n) {
        arrB[n%10] = 1;
        n/=10;
    }
    
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int A, B;
        cin>>A>>B;
        cout<<calculate(A,B)<<'\n';
    }
    
    return 0;
}


