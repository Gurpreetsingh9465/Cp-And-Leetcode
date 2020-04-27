#include<bits/stdc++.h>
using namespace std;
#define li long int

int getNext(int prev, int *sieve, int n) {
    for(int i=prev+1;i<n+1;i++) {
        if(sieve[i] == 1) {
            return i;
        }
    }
    return -1;
}

string calculate(vector<int> v, int n, int l) {
    int *sieve = new int[n+1];
    memset(sieve, -1, sizeof(int)*(n+1));
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2;i<=n;i++) {
        if(sieve[i] == -1) {
            sieve[i] = 1;
            for(int j = i*2;j<=n;j+=i) {
                sieve[j] = 0;
            }
        }
    }
    int ans[l+1];
    vector<int> possX;
    for(int i = n;i>=0;i--) {
        if(sieve[i] == 1 && v[0]%i == 0) {
            possX.push_back(i);
        }
    }
    int index;
    for(auto &x: possX) {
        index = 0;
        ans[index++] = x;
        int cur = x;
        for(int &i: v) {
            if(i%cur == 0 && sieve[i/cur]) {
                ans[index++] = i/cur;
                cur = i/cur;
            } else {
                break;
            }
        }
        if(index == l)
            break;
        continue;
    }
    unordered_set<int> s;
    vector<int> letters(26);
    index = 0;
    for(int i = 0;i<=l;i++) {
        auto res = s.insert(ans[i]);
        if(res.second) {
            letters[index++] = ans[i];
        }
    }
    sort(letters.begin(), letters.end());
    unordered_map<int, char> c;
    for(int i=0;i<26;i++) {
        c[letters[i]] = (char)(i+'A');
    }
    string res = "";
    for(int i=0;i<=l;i++) {
        res+=c[ans[i]];
    }
    return res;
}

int main() {
    int T;
    cin>>T;
    for(int t = 1;t<=T;t++) {
        int N, l;
        cin>>N>>l;
        vector<int> v(l);
        int index = 0;
        for(index;index<l;index++) {
            cin>>v[index];
        }
        string ans = calculate(v, N, l);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
