#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n = 9;
    int prevMoves[9][9];
    bool isValidMove(vector<vector<char>>& board, int i, int j, char val) {
        if(i<0 ||  j < 0 || i>=n || j>= n)
            return false;
        if(board[i][j] != '.')
            return false;
        for(int l=0;l<n;l++) {
            if(board[i][l] == val || board[l][j] == val)
                return false;
        }
        int boxI = i/3;
        int boxJ = j/3;
        for(int k=boxI*3;k<boxI*3+3;k++) {
            for(int l=boxJ*3;l<boxJ*3+3;l++) {
                if(board[k][l] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isComplete(vector<vector<char>>& board) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<char>>& board,int i, int j) {
        if(i >= n) {
            return true;
        }
        if(j >= n) {
            return helper(board,i+1,0);
        }
        if(prevMoves[i][j] == 1) {
            for(char val = '1';val<='9';val++) {
                if(isValidMove(board,i,j,val)) {
                    board[i][j] = val;
                    bool ans = helper(board, i,j+1);
                    if(ans == true)
                        return true;
                    
                    board[i][j] = 0;
                }
            }
        } else {
            return helper(board,i,j+1);
        }
        return false;
        
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == '.') {
                    prevMoves[i][j] = 1;
                } else {
                    prevMoves[i][j] = 0;
                }
            }
        }
        helper(board,0,0);
    }
};

int main() {
    
}