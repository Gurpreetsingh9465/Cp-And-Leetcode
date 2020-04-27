#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> left, pair<int,int> right) {
    return left.first<right.first;
}

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

vector<vector<int>> breakArrays(vector<int> &a, vector<int> &b) {
    vector<vector<int>> res;
    vector<int> cur = LCS(a,b);
    res.push_back(cur);
    while (cur.size() < a.size()) {
        for(auto &i_cur: cur) {
            std::vector<int>::iterator toErease ;
            toErease=std::find(a.begin(), a.end(), i_cur);
            a.erase(toErease);
            toErease=std::find(b.begin(), b.end(), i_cur);
            b.erase(toErease);
        }
        cur = LCS(a,b);
        res.push_back(cur);
    }
    return res;
}

vector<vector<int>> calculate(int **arr, int n, int k) {
    vector<vector<int>> ans;
    vector<int> init;
    for(int i = 0;i<n;i++) {
        init.push_back(arr[0][i]);
    }
    unordered_map<int, int> m[k];
    for(int i = 0;i<k;i++) {
        for(int j=0;j<n;j++) {
            m[i][arr[i][j]] = j;
        }
    }
    ans.push_back(init);
    for(int j=1;j<k;j++) {
        vector<int> array(n);
        int index = 0;
        for(int i = 0 ;i<n;i++) {
            array[i] = arr[j][i];
        }
        vector<vector<int>> newAns;
        for(auto &i: ans) {
            vector<pair<int,int>> interArrays(i.size());
            index = 0;
            for(auto &i_a: i) {
                interArrays[index++] = {m[j][i_a], i_a};
            }
            sort(interArrays.begin(), interArrays.end(), comparator);
            vector<int> newInterArray(i.size());
            index = 0;
            for(auto &i_a_a: interArrays) {
                newInterArray[index++] = i_a_a.second;
            }
            vector<vector<int>> interAns = breakArrays(i,newInterArray);
            for(auto &i_ans: interAns) {
                newAns.push_back(i_ans);
            }
        }
        ans = newAns;
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N,K;
        cin>>N>>K;
        vector<vector<int>> arr(K);
        for(int i = 0;i<K;i++) {
            arr[i].resize(N);
            for(int j = 0;j<N;j++) {
                cin>>arr[i][j];
            }
        }
        int **newArr = new int*[K];
        unordered_set<int> used;
        int max_size = INT_MIN;
        int toUseI = 0, toUsej = 0;
        for(int j=0;j<K;j++) {
            for(int k=0;k<K;k++) {
                if(used.find(j) != used.end() || used.find(k) != used.end()) {
                    continue;
                }
                if(j!=k) {
                    int size = LCS(arr[j], arr[k]).size();
                    if(max_size<size) {
                        max_size = size;
                        toUseI = j;
                        toUsej = k;
                    }
                }
            }
        }
        used.insert(toUseI);
        used.insert(toUsej);
        newArr[0] = new int[N];
        newArr[1] = new int[N];
        for(int i = 0;i<N;i++) {
            newArr[0][i] = arr[toUseI][i];
        }
        for(int i = 0;i<N;i++) {
            newArr[1][i] = arr[toUsej][i];
        }
        int index = 2;
        int lastToUse;
        for(int i = index;i<K;i++) {

        }
        for(int i=0;i<K;i++) {
            int toUsed = i;
            for(int j=0;j<K;j++) {
                for(int k=0;k<K;k++) {
                    if(used.find(j) != used.end() || used.find(k) != used.end()) {
                        continue;
                    }
                    if(j!=k) {

                    }
                }
            }
        }


        vector<vector<int>> ans = calculate(newArr,N,K);
        map<int,int> finalAns;
        // for(auto &i: ans) {
        //     for(auto &j: i) {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int count = 0;
        for(int i=0;i<ans.size();i++) {
            for(int j=0;j<ans[i].size();j++) {
                if(j+1 >= ans[i].size()) {
                    finalAns[ans[i][j]] = 0;
                    count++;
                    continue;
                }
                finalAns[ans[i][j]] = ans[i][j+1];
            }
        }
        cout<<count<<endl;
        for(auto &i: finalAns) {
            cout<<i.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}