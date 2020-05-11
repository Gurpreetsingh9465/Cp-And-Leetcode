#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

class Solution {
public:
    
    bool rec(vector<vector<char>>& board, string &s, bool **vis,int i, int j, int n, int m, int cur, vector<int> &kmpArr) {
        if(cur>=s.length())
            return true;
        if(i<0 || i>=n || j>=m || j< 0)
            return false;
        if(vis[i][j] == true) {
            return false;
        }
        if(board[i][j] != s[cur]) {
            if(cur == 0)
                return false;
            cur = kmpArr[cur-1];
            return rec(board,s,vis,i,j,n,m,cur,kmpArr);
        }
        vis[i][j] = true;
        bool a = rec(board,s,vis,i+1,j,n,m,cur+1,kmpArr);
        if(a)
            return true;
        bool b = rec(board,s,vis,i-1,j,n,m,cur+1,kmpArr);
        if(b)
            return true;
        bool c = rec(board,s,vis,i,j+1,n,m,cur+1,kmpArr);
        if(c)
            return true;
        bool d = rec(board,s,vis,i,j-1,n,m,cur+1,kmpArr);
        if(d)
            return true;
        return a|b|c|d;
    }
    
    void memfree(bool **vis, int n, int m) {
        for(int i = 0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vis[i][j] = false;
            }
        }
    }
    
    vector<int> createPrefixArray(string &s) {
        int n = s.length();
        vector<int> ans(n);
        int i = 1;
        int j = 0;
        while(i<n) {
            if(s[i] == s[j]) {
                ans[i] = j+1;
                i++;
                j++;
            } else {
                if(j!=0)
                    j = ans[j-1];
                else
                    i++;
            }
        }
        
        return ans;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int>> prefArrays(words.size());
        vector<string> ans;
        for(int i = 0;i<words.size();i++) {
            prefArrays[i] = createPrefixArray(words[i]);
        }
        int n = board.size();
        if(n==0)
            return {};
        int m = board[0].size();
        if(m == 0)
            return {};
        bool **visited = new bool*[n];
        for(int i =0;i<n;i++) {
            visited[i] = new bool[m];
            for(int j = 0;j<m;j++) {
                visited[i][j] = false;
            }
        }
        for(int k = 0;k<words.size();k++) {
            memfree(visited,n,m);
            bool any = false;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(board[i][j] == words[k][0]) {
                        bool cur = rec(board,words[k],visited,i,j,n,m,0,prefArrays[k]);
                        if(cur == true) {
                            any = true;
                            break;
                        }
                    }
                }
                if(any)
                    break;
            }
            if(any) {
                ans.push_back(words[k]);
            }
        }
        
        return ans;
        
    }
};

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> ans = Solution().findWords(board, words);
    for(auto &i: ans) {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}