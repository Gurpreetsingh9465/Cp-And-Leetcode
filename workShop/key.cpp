#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int first = t1+s*v1+t1;
    int second = t2+s*v2+t2;
    if(first<second) {
        cout<<"First";
    } else if(second < first) {
        cout<<"Second";
    } else {
        cout<<"Friendship";
    }
    cout<<endl;
}