#include<bits/stdc++.h>
using namespace std;
#define li long int

pair<string, string> calculate(vector<int> v) {
    string A, B;
    A = "";
    B = "";
    for(auto &i: v) {
        if(i == 4) {
            A+='2';
            B+='2';
        } else {
            A+=(char)(i+'0');
            B+='0';
        }
    }
    int index = 0;
    for(auto &i : A) {
        if(i == '0') {
            index++;
        } else {
            break;
        }
    }
    A.erase(0,index);
    index = 0;
    for(auto &i : B) {
        if(i == '0') {
            index++;
        } else {
            break;
        }
    }
    B.erase(0,index);
    return {A, B};
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        string N;
        cin>>N;
        vector<int> v(N.length());
        int index = 0;
        for(auto &i: N) {
            v[index++] = i-'0';
        }
        pair<string, string> ans = calculate(v);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}
