#include <bits/stdc++.h>
using namespace std;

char getFirstNonRepeating(string s) {
    map<char, int> m;
    for(auto i: s) {
        if(m.find(i) != m.end()) {
            m[i] += 1;
        } else {
            m[i] = 1;
        }
    }
    for(auto i : m) {
        if(i.second == 1) {
            return i.first;
        }
    }
    return '-';
}

int main() {
    string s;
    cin>>s;
    cout<<getFirstNonRepeating(s)<<endl;
    return 0;
}