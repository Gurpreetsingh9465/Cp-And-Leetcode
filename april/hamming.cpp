#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int hammingDistance(int a, int b) {

    int xored = a^b;
    int count = 0;
    while (xored) {
        count+=(xored&1);
        xored>>=1;
    }
    return count;
}


bool checkKthBit(int number, int k) {
    if(number&(1<<(k-1))) {
        return 1;
    }
    return 0;
}
//even parity
//D7 D6 D5 P4 D3 P2 P1 
int getError(int number) {
    int c = number;
    int count = 0;
    while (c) {
        count+=(c&1);
        c>>=1;
    }
    if(!(count&1))  {
        // no error
        return 0;
    }

    int p1 = 1;
    // p2 d3 d6 d7
    int p2 = checkKthBit(number,2)+ checkKthBit(number,3) +checkKthBit(number,6) + checkKthBit(number,7);
    if(p2&1) {
        p2 = 1;
    } else {
        p2 = 0;
    }
    // p4 d5 d6 d7
    int p4 = checkKthBit(number,4)+ checkKthBit(number,5) +checkKthBit(number,6) + checkKthBit(number,7);
    if(p4&1) {
        p4 = 1;
    } else {
        p4 = 0;
    }
    int ans =  (p4<<2)+(p2<<1)+p1;
    return ans;
}

int main() {
    int a, b;
    cout<<"get hamming distance\n";
    cin>>a>>b;
    cout<<hammingDistance(a,b)<<"\n";
    int number;
    cout<<"get error bit even parity hamming code\n";
    cin>>number;
    cout<<getError(number)<<" bit has error in "<<number<<"\n";
    return 0;
}


