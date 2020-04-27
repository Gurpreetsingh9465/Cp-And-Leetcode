#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

string preficCount(string &s1, string &s2) {
    int index = 0;
    string s = "";
    while (index < s1.size() && index<s2.size()) {
        if(s1[index] == s2[index]) {
            s+=s[index];
        } else {
            return s;
        }
        index++;
    }
    return s;
}

void rec(vector<string> &vec, int *ans) {
    if(vec.size() == 0)
        return;
    int choose = -1;
    int max_len = 0;
    string pref = "";
    for(int i=1;i<vec.size();i++) {
        string cur_prefix = preficCount(vec[i-1], vec[i]);
        if((int)(cur_prefix.size()) > max_len) {
            pref = cur_prefix;
            max_len = cur_prefix.size();
            choose = i;
        }
    }
    if(choose == -1) {
        return;
    }
    *ans = *ans + 2;
    string selected = vec[choose].substr(0, max_len);
	
    vector<string> new_vec;

	for(int i=0;i<vec.size()-1;i++) {
		string cur_prefix = preficCount(vec[i], vec[i+1]);
		if(cur_prefix == selected) {
            i++;
		} else {
            new_vec.push_back(vec[i]);
        }
	}
    rec(new_vec, ans);
}

void solve() {
    int N;
    cin>>N;
    vector<string> vec(N);
    int index=0;
    for(int i=1;i<=N;i++) {
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        vec[index++] = s;
    }
    sort(vec.begin(), vec.end());
    int *ans = new int;
    *ans = 0;
    rec(vec,ans);
    cout<<*ans<<"\n";
}

int main() {
    fastIO;
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++) {
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
