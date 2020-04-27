#include<bits/stdc++.h>
using namespace std;

int fun() {
    int *a = new int;
    *a = 5;
    *a = *a + 1;
    return *a;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,8};
    vector<int> b = {2,4,5,8,9,10};
    vector<int> c = {0};
    merge(a.begin(), a.end(), b.begin(), b.end(),back_inserter(c));
    for(auto &i: c) {
        cout<<i<<endl;
    }
    return 0;
}