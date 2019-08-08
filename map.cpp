#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> a;
    a[5] = 75;
    a[7] = 0;
    if(a.find(10) !=  a.end()) {
        cout<<"YO"<<endl;
    }
    cout<<a.find(5)->second<<endl;
    cout<<a.find(7)->second<<endl;
    return 0;
}