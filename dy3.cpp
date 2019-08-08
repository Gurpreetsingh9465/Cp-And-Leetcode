#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minThree(int a,int b,int c) {
        int res;
        res = a;
        if(res>b) {
            res = b;
        }
        if(res>c) {
            res = c;
        }
        return res;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        int **arr = new int*[A.size()];
        for(int i=0;i<A.size();i++) {
            arr[i] = new int[A[0].size()];
            for(int j=0;j<A[0].size();j++) {
                if(i == A.size()-1) {
                    arr[i][j] = A[i][j];
                } else {
                    arr[i][j] = 0;
                }
            }
        }
        for(int i = r-2;i>=0;i--) {
            for(int j = c-1;j>=0;j--) {
                int L,R,C;
                L=R=INT_MAX;
                C = arr[i+1][j]+A[i][j];
                if(j-1>=0) {
                    L = arr[i+1][j-1]+A[i][j];
                }
                if(j+1<=c-1) {
                    R = arr[i+1][j-1]+A[i][j];
                }
                arr[i][j] = minThree(L,R,C);
            }
        }
        int res = arr[0][0];
        for(int i=0;i<c;i++) {
            if(res>arr[0][i])
                res = arr[0][i];
        }
        return res;
        
    }
};
int main() {
    return 0;
}