#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int randi(int lo, int hi)
{
    int n = hi - lo + 1;
    int i = rand() % n;
    if (i < 0) i = -i;
    return lo + i;
}

int calculateScore(int **arr, int N, int K, vector<vector<int>> &prob, int cur[]) {
    int score = INT_MIN;
    for(int i=0;i<K;i++) {
        int cur_score = 0;
        for(int j=0;j<N;j++) {
            if(arr[j][i] == prob[j][cur[j]]) {
                cur_score++;
            }
        }
        if(score>cur_score) {
            score = cur_score;
        }
    }
    return score;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int N,M,K;
        cin>>N>>M>>K;
        int **matrix = new int*[N];
        vector<vector<int>> prob(N);
        int index = 0;
        for(int i = 0;i<N;i++) {
            matrix[i] = new int[K];
            int arr[M+1];
            memset(arr, 0, sizeof(arr));
            for(int j = 0;j<K;j++) {
                cin>>matrix[i][j];
                arr[matrix[i][j]]++;
            }
            int max_num = INT_MIN;
            int num;
            for(int j = 1;j<=M;j++) {
                if(arr[j] >= max_num) {
                    max_num = arr[j];
                    num = j;
                }
            }
            vector<int> sameFreq;
            for(int j=1;j<=M;j++) {
                if(arr[j] == max_num) {
                    sameFreq.push_back(j);
                }
            }
            prob[index++] = sameFreq;
        }

        int cur[N];
        memset(cur,0,sizeof(cur));
        int max_score = calculateScore(matrix,N,K,prob,cur);
        vector<int> ans(N,0);
        int op = 0;
        int mx_op = 100000;
        while (op<mx_op) {
            for(int i = 0;i<N;i++) {
                if(prob[i].size() == 1) 
                    continue;
                cur[i] = randi(0, prob[i].size()-1);
            }
            int score_cur =calculateScore(matrix,N,K,prob,cur);
            if(score_cur>max_score) {
                max_score = score_cur;
                for(int i=0;i<N;i++) {
                    ans[i] = cur[i];
                }
            }
            op++;
        }
        for(int i=0;i<N;i++) {
            cout<<prob[i][ans[i]]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}

