#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isWinning(string &s) {
    for(char i: s) {
        if(i != '-') {
            return false;
        }
    }
    return true;
}

bool remove(string &s, int i) {
    if(s[i] == '1') {
        s[i] = '-';
        if(i-1 >= 0) {
            if(s[i-1] != '-') {
                s[i-1] = s[i-1] == '0'?'1':'0';
            }
        }
        if(i+1 < s.length()) {
            if(s[i+1] != '-') {
                s[i+1] = s[i+1] == '0'?'1':'0';
            }
        }
        return true;
    }
    return false;
}

bool backtrack(string &s, int i) {
    if(s[i] == '-') {
        s[i] = '1';
        if(i-1 >= 0) {
            if(s[i-1] != '-') {
                s[i-1] = s[i-1] == '0'?'1':'0';
            }
        }
        if(i+1 < s.length()) {
            if(s[i+1] != '-') {
                s[i+1] = s[i+1] == '0'?'1':'0';
            }
        }
        return true;
    }
    return false;
}

bool fun(string s, int cur) {
    if(cur<s.length()) {
        for(int i = cur;i<s.length();i++) {
            if(remove(s, i)) {
                if(isWinning(s)) {
                    return true;
                }
                bool ans = fun(s,i+1);
                if(ans == false) {
                    backtrack(s,i);
                    continue;
                } else {
                    return true;
                }
            }
        }
    } else {
        return false;
    }
}

bool fun(string s) {
    stack<pair<string,int>> st;
    st.push({s,-1});
    string curS;
    int curI;
    int N = s.length();
    while(!st.empty()) {
        curS = st.top().first;
        curI = st.top().second+1;
        for(curI;curI<N;curI++) {
            if(remove(curS, curI)) {
                if(isWinning(curS)) {
                    return true;
                }
                break;
            }
        }
        if(curI != N) {
            st.top().second = curI;
            st.push({curS, -1});
        } else {
            st.pop();
        }
    }

    return false;
}

string randomString(int n) {
    string s = "";
    for(int i=0;i<n;i++) {
        char x = rand()%2+'0';
        s+=x;
    }
    return s;
}



int main() {

	int T;
	cin>>T;
	while(T--) {
        // string s = randomString(20);
        // auto start = chrono::system_clock::now();
        // bool ans1 = fun(s,0);
        // bool ans = fun(s);
        // auto end = chrono::system_clock::now();
        // std::chrono::duration<double> elapsed_seconds = end-start;
        // cout<<elapsed_seconds.count()<<"s and answere recursive "<<ans1<<" iterative "<<ans<<endl;
        string s;
        cin>>s;
        // if(fun(s,0)) {
        //     cout<<"WIN"<<endl;
        // } else {
        //     cout<<"LOSE"<<endl;
        // }
        if(fun(s)) {
            cout<<"WIN"<<endl;
        } else {
            cout<<"LOSE"<<endl;
        }
	}
	return 0;
}
