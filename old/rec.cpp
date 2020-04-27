#include<bits/stdc++.h>
using namespace std;

void back(int n) {
    if(n>0) {
        cout<<n<<" ";
        back(n-1);
    }
}


void front(int n) {
    if(n>0) {
        front(n-1);
        cout<<n<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    back(n);
    cout<<endl;
    front(n);
    cout<<endl;
    return 0;
}