#include<bits/stdc++.h>
using namespace std;

string getAns(int a, int b) {
    int give = 1;
    while (a>=0 && b>=0) {
        if(give&1) {
            a-=give;
        } else {
            b-=give;
        }
        give++;
    }
    if(a<0) {
        return "Vladik";
    }
    return "Valera";
    
}

int main() {
    int a, b;
    cin>>a>>b;
    cout<<getAns(a,b)<<endl;
}