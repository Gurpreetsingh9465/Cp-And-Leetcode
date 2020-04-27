#include<bits/stdc++.h>
using namespace std;

vector<int> LCS(vector<int> &a, vector<int> &b) {
    int arr[a.size()+1][a.size()+1];
    int n = a.size()+1;
    for(int i = 0;i<n;i++) {
        for(int j= 0;j<n;j++) {
            if(i == 0 || j == 0) {
                arr[i][j] = 0;
            } else {
                if(a[i-1] == b[j-1]) {
                    arr[i][j] = arr[i-1][j-1]+1;
                } else {
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
    }
    vector<int> ans(arr[n-1][n-1]);
    int index = arr[n-1][n-1];
    int i = n-1, j = n-1;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) { 
            ans[index-1] = a[i-1];
            i--; j--; index--;
        }
        else if (arr[i-1][j] > arr[i][j-1]) 
            i--;
        else
            j--; 
    }
    return ans;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7};
    vector<int> b = {2,3,4,1,6,5,7};

    vector<int> longetsCommon = LCS(a,b);
    for(auto &i: longetsCommon) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

