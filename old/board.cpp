#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchBoard(vector<vector<int>> board,int i,int j,string word,int cur) {
        if(i<0 || i>=board.size() || j <0 || j>=board[0].size() || word[cur] != board[i][j]) {
            return false;
        }
        bool left = searchBoard(board,i,j-1,word,cur+1);
        bool up = searchBoard(board,i-1,j,word,cur+1);
        bool down = searchBoard(board,i+1,j,word,cur+1);
        bool right = searchBoard(board,i,j+1,word,cur+1);
        if((left || up || down || right) && board[i][j] == word[cur]) {
            return true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size();i++) {
            for(int j = 0; j<board[0].size();j++) {
                if(searchBoard(board,i,j,word,0)) {
                    return true;
                }
            }
        }
        return 0;
    }
};


int main() {
    vector<vector<char>> v = {{'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}};
    cout<<Solution().exist(v,"SEE")<<endl;
    return 0;
}