#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

string longestCommonPrefix(vector<string> &ar,int start, int end) 
{
    if (end == 0) 
        return "";
    if (end-start == 0) 
        return ar[end];
    int en = min(ar[start].size(),  
                 ar[end].size());
    string first = ar[start], last = ar[end]; 
    int i = start;
    while (i < en && first[i] == last[i]) 
        i++;
    string pre = first.substr(0, i); 
    return pre;
} 

int calculate(vector<string> &arr, int N, int K) {
    sort(arr.begin(), arr.end());
    int score = 0;
    for(int i=0;i<N;i+=K) {
        for(int j=0;j<i+K;j++) {
            
        }
    }
    return score;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int N, K;
        cin>>N>>K;
        vector<string> s(N);
        for(int i=0;i<N;i++) {
            cin>>s[i];
        }
        cout<<"Case #"<<t<<": "<<calculate(s,N,K)<<"\n"<<endl;
    }
    return 0;
}


