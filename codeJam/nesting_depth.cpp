#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

string calculate(string &s) {
    string ans = "";
    vector<pair<int, int>> freq(101);
    int index = 0;
    for(auto &c: s) {
        int number = c-'0';
        if(index == 0) {
            freq[index++] = {number, 1};
        } else {
            if(freq[index-1].first == number) {
                freq[index-1].second+=1;
            } else {
                freq[index++] = {number, 1};
            }
        }
    }
    int cur = 0;
    for(int i=0;i<index;i++) {
        int number = freq[i].first;
        if(number > cur) {
            int adding = number-cur;
            cur+=adding;
            for(int j=0;j<adding;j++) {
                ans= ans+'(';
            }
        } else if(number<cur) {
            int adding = cur-number;
            cur-=adding;
            for(int j=0;j<adding;j++) {
                ans= ans+')';
            }
        }
        for(int j=0;j<freq[i].second;j++) {
            ans=ans+(char)(number+'0');
        }
    }
    for(int i=0;i<cur;i++) {
        ans=ans+=')';
    }
    return ans;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        string s;
        cin>>s;
        cout<<"Case #"<<t<<": "<<calculate(s)<<"\n";
    }
    return 0;
}
