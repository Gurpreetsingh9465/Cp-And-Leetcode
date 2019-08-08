#include <bits/stdc++.h>
using namespace std;

void print(vector<string> s) {
    for(auto i: s) {
        cout<<i<<endl;
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) {
            return {};
        }
        else if(n == 1) {
            return {"()"};
        } else if(n == 2) {
            return {"(())","()()"};
        }
        vector<string> inter = generateParenthesis(n-1);
        int dup = n-1;
        string dupString = "";
        for(int i =0;i<dup;i++) {
            dupString+="()";
        }
        vector<string> result;
        if(n%2 == 0) {
            string dup2;
            for(int i =0;i<dup-1;i++) {
                dup2+="(";
            }
            for(int i =0;i<dup-1;i++) {
                dup2+=")";
            }
            dup2 += "()";
            for(auto i: inter) {
                result.push_back('('+i+')');
                if(i != dupString) {
                    result.push_back(i+"()");
                }
                if(i!=dup2) {
                    result.push_back("()"+i);
                }
            }
            string extra = "";
            for(int i=0;i<n/2;i++) {
                extra += "(())";
            }
            result.push_back(extra);
        } else {
            for(auto i: inter) {
                result.push_back('('+i+')');
                if(i != dupString) {
                    result.push_back(i+"()");
                }
                result.push_back("()"+i);
            }
        }
        
        return result;
    }
};

int main() {
    int n;
    cin>>n;
    print(Solution().generateParenthesis(n));
}