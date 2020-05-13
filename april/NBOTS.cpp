#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int destroyed = 0;

void printMat(int **arr, int N) {
    for(int i = 1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// start, end, num_digit, sum_digit
vector<vector<int>> Rpref;
vector<vector<int>> Lpref;
vector<vector<int>> Upref;
vector<vector<int>> Dpref;

void printPref(vector<vector<int>> pref) {
    for(auto &i: pref) {
        if(i.size())
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<" =>  ";
    }
    cout<<"\n";
}

void printPrefs() {
    cout<<"R = ";
    printPref(Rpref);
    cout<<"L = ";
    printPref(Lpref);
    cout<<"D = ";
    printPref(Dpref);
    cout<<"U = ";
    printPref(Upref);
}

bool inBetween(int a, int b, int c) {
    if(a>b) 
        swap(a,b);
    return (a<= c && c<=b);
}

void applyMove(int **arr, int N,int F, pair<char,int> move) {
    if(move.first == 'L') {
        int sum = 0;
        int start = 1, num_digit = 0,end = 0,sum_digit = 0;
        int i = move.second;
        bool flag = false;
        for(int j = 1;j<=N;j++) {
            if(arr[i][j] == 0)
                continue;
            //start,end,dig,sum
            if(sum+arr[i][j] <= F && flag == false) {
                sum+=arr[i][j];
                int num=arr[i][j];
                arr[i][j] = 0;
                destroyed++;
                if(inBetween(Rpref[i][0],Rpref[i][1],j)) {
                    Rpref[i][2]-=1;
                    Rpref[i][3]-=num;
                    Rpref[i][1]+=1;
                }
                // effect down;
                if(inBetween(Dpref[j][0], Dpref[j][1], i)) {
                    Dpref[j][2]-=1;
                    Dpref[j][3]-=num;
                }
                while (Dpref[j][1]+1<=N && Dpref[j][3]+arr[Dpref[j][1]+1][j]<=F) {
                    Dpref[j][3]+=arr[Dpref[j][1]+1][j];
                    if(arr[Dpref[j][1]+1][j]!=0)
                        Dpref[j][2]+=1;
                    Dpref[j][1]+=1;
                }
                if(inBetween(Upref[j][0],Upref[j][1], i)) {
                    Upref[j][2]-=1;
                    Upref[j][3]-=num;
                }
                while (Upref[j][1]-1>=1 && Upref[j][3]+arr[Upref[j][1]-1][j]<=F) {
                    Upref[j][3]+=arr[Upref[j][1]-1][j];
                    if(arr[Upref[j][1]-1][j])
                        Upref[j][2]+=1;
                    Upref[j][1]-=1;
                }
            } else {
                flag = true;
                if(sum_digit + arr[i][j] <= F) {
                    sum_digit+=arr[i][j];
                    num_digit+=1;
                } else {
                    end = j-1;
                    break;
                }
            }
        }
        if(end == 0)
            end = N;
        Lpref[i] = {start,end,num_digit,sum_digit};
    } else if(move.first == 'R') {
        int sum = 0;
        int start = N, num_digit = 0,end = 0,sum_digit = 0;
        int i = move.second;
        bool flag = false;
        for(int j = N;j>=1;j--) {
            if(arr[i][j] == 0)
                continue;
            //start,end,dig,sum
            if(sum+arr[i][j] <= F && flag == false) {
                sum+=arr[i][j];
                int num=arr[i][j];
                arr[i][j] = 0;
                destroyed++;
                if(inBetween(Lpref[i][0],Lpref[i][1],j)) {
                    Lpref[i][2]-=1;
                    Lpref[i][3]-=num;
                    Lpref[i][1]-=1;
                }
                // effect down;
                if(inBetween(Dpref[j][0], Dpref[j][1], i)) {
                    Dpref[j][2]-=1;
                    Dpref[j][3]-=num;
                }
                while (Dpref[j][1]+1<=N && Dpref[j][3]+arr[Dpref[j][1]+1][j]<=F) {
                    Dpref[j][3]+=arr[Dpref[j][1]+1][j];
                    if(arr[Dpref[j][1]+1][j]!=0)
                        Dpref[j][2]+=1;
                    Dpref[j][1]+=1;
                }
                if(inBetween(Upref[j][0],Upref[j][1], i)) {
                    Upref[j][2]-=1;
                    Upref[j][3]-=num;
                }
                while (Upref[j][1]-1>=1 && Upref[j][3]+arr[Upref[j][1]-1][j]<=F) {
                    Upref[j][3]+=arr[Upref[j][1]-1][j];
                    if(arr[Upref[j][1]-1][j]!=0)
                        Upref[j][2]+=1;
                    Upref[j][1]-=1;
                }
            } else {
                flag = true;
                if(sum_digit + arr[i][j] <= F) {
                    sum_digit+=arr[i][j];
                    num_digit+=1;
                } else {
                    end = j-1;
                    break;
                }
            }
        }
        if(end == 0)
            end = 1;
        Rpref[i] = {start,end,num_digit,sum_digit};
    } else if(move.first == 'D') {
        int sum = 0;
        int start = 1, num_digit = 0,end = 0,sum_digit = 0;
        int j = move.second;
        bool flag = false;
        for(int i = 1;i<=N;i++) {
            if(arr[i][j] == 0)
                continue;
            //start,end,dig,sum
            if(sum+arr[i][j] <= F && flag == false) {
                sum+=arr[i][j];
                int num=arr[i][j];
                arr[i][j] = 0;
                destroyed++;
                if(inBetween(Upref[j][0],Upref[j][1],i)) {
                    Upref[j][2]-=1;
                    Upref[j][3]-=num;
                    Upref[j][1]+=1;
                }
                // effect down;
                if(inBetween(Lpref[i][0], Lpref[i][1], j)) {
                    Lpref[i][2]-=1;
                    Lpref[i][3]-=num;
                }
                while (Lpref[i][1]+1<=N && Lpref[i][3]+arr[i][Lpref[i][1]+1]<=F) {
                    Lpref[i][3]+=arr[i][Lpref[i][1]+1];
                    if(arr[i][Lpref[i][1]+1]!=0)
                        Lpref[i][2]+=1;
                    Lpref[i][1]+=1;
                }
                if(inBetween(Rpref[i][0],Rpref[i][1], j)) {
                    Rpref[i][2]-=1;
                    Rpref[i][3]-=num;
                }
                while (Rpref[i][1]-1>=1 && Rpref[i][3]+arr[i][Rpref[i][1]-1]<=F) {
                    Rpref[i][3]+=arr[i][Rpref[i][1]-1];
                    if(arr[i][Rpref[i][1]-1]!=0)
                        Rpref[i][2]+=1;
                    Rpref[i][1]-=1;
                }
            } else {
                flag = true;
                if(sum_digit + arr[i][j] <= F) {
                    sum_digit+=arr[i][j];
                    num_digit+=1;
                } else {
                    end = j-1;
                    break;
                }
            }
        }
        if(end == 0)
            end = N;
        Dpref[j] = {start,end,num_digit,sum_digit};
    } else if(move.first == 'U') {
        int sum = 0;
        int start = N, num_digit = 0,end = 0,sum_digit = 0;
        int j = move.second;
        bool flag = false;
        for(int i = N;i>=1;i--) {
            if(arr[i][j] == 0)
                continue;
            //start,end,dig,sum
            if(sum+arr[i][j] <= F && flag == false) {
                sum+=arr[i][j];
                int num=arr[i][j];
                arr[i][j] = 0;
                destroyed++;
                if(inBetween(Dpref[j][0],Dpref[j][1],i)) {
                    Dpref[j][2]-=1;
                    Dpref[j][3]-=num;
                    Dpref[j][1]-=1;
                }
                if(inBetween(Lpref[i][0], Lpref[i][1], j)) {
                    Lpref[i][2]-=1;
                    Lpref[i][3]-=num;
                }
                while (Lpref[i][1]+1<=N && Lpref[i][3]+arr[i][Lpref[i][1]+1]<=F) {
                    Lpref[i][3]+=arr[i][Lpref[i][1]+1];
                    if(arr[i][Lpref[i][1]+1]!=0)
                        Lpref[i][2]+=1;
                    Lpref[i][1]+=1;
                }
                if(inBetween(Rpref[i][0],Rpref[i][1], j)) {
                    Rpref[i][2]-=1;
                    Rpref[i][3]-=num;
                }
                while (Rpref[i][1]-1>=1 && Rpref[i][3]+arr[i][Rpref[i][1]-1]<=F) {
                    Rpref[i][3]+=arr[i][Rpref[i][1]-1];
                    if(arr[i][Rpref[i][1]-1]!=0)
                        Rpref[i][2]+=1;
                    Rpref[i][1]-=1;
                }
            } else {
                flag = true;
                if(sum_digit + arr[i][j] <= F) {
                    sum_digit+=arr[i][j];
                    num_digit+=1;
                } else {
                    end = j-1;
                    break;
                }
            }
        }
        if(end == 0)
            end = 1;
        Upref[j] = {start,end,num_digit,sum_digit};
    }
}


pair<char,int> bestAns(int **arr, int N, int F) {
    char max_char;
    int max_index, max_digit = 0, max_sum = 0;
    for(int i = 1;i<=N;i++) {
        int cur_dig = Rpref[i][2];
        int cur_sum = Rpref[i][3];
        if(cur_sum>max_sum){
            max_sum = cur_sum;
            max_digit = cur_dig;
            max_char = 'R';
            max_index = i;
        }
    }
    for(int i = 1;i<=N;i++) {
        int cur_dig = Lpref[i][2];
        int cur_sum = Lpref[i][3];
        if(cur_sum>max_sum){
            max_sum = cur_sum;
            max_char = 'L';
            max_digit = cur_dig;
            max_index = i;
        }
    }
    for(int i = 1;i<=N;i++) {
        int cur_dig = Upref[i][2];
        int cur_sum = Upref[i][3];
        if(cur_sum>max_sum){
            max_sum = cur_sum;
            max_char = 'U';
            max_digit = cur_dig;
            max_index = i;
        }
    }
    for(int i = 1;i<=N;i++) {
        int cur_dig = Dpref[i][2];
        int cur_sum = Dpref[i][3];
        if(cur_sum>max_sum){
            max_sum = cur_sum;
            max_char = 'D';
            max_digit = cur_dig;
            max_index = i;
        }
    }
    if(max_sum == 0)
        assert(0);
    return {max_char, max_index};
}

bool isDestroyed(int **arr,int N) {
    for(int i = 1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(arr[i][j] != 0)
                return false;
        }
    }
    return true;
}

void applyMoveTest(int **arr, int N,int F, pair<char,int> move) {
    int sum = 0;
    char max_char = move.first; 
    int max_index = move.second;
    if(max_char == 'U') {
        for(int i = 1;i<=N;i++) {
            if(arr[N-(i-1)][max_index] != 0) {
                if(sum+arr[N-(i-1)][max_index] > F) 
                    break;
                sum+=arr[N-(i-1)][max_index];
                arr[N-(i-1)][max_index] = 0;
                destroyed+=1;
            }
        }
    } else if(max_char == 'D') {
        for(int i = 1;i<=N;i++) {
            if(arr[i][max_index] != 0) {
                if(sum+arr[i][max_index] > F)
                    break;
                sum+=arr[i][max_index];
                arr[i][max_index] = 0;
                destroyed+=1;
            }
        }
    } else if(max_char == 'L') {
        for(int i = 1;i<=N;i++) {
            if(arr[max_index][i] != 0) {
                if(sum+arr[max_index][i] > F)
                    break;
                sum+=arr[max_index][i];
                arr[max_index][i] = 0;
                destroyed+=1;
            }
        }
    } else if(max_char == 'R') {
        for(int i = 1;i<=N;i++) {
            if(arr[max_index][N-(i-1)] != 0) {
                if(sum+arr[max_index][N-(i-1)] > F)
                    break;
                sum+=arr[max_index][N-(i-1)];
                arr[max_index][N-(i-1)] = 0;
                destroyed+=1;
            }
        }
    }
}

void solve() {
    destroyed = 0;
    int N,F;
    cin>>N>>F;
    int **arr2 = new int*[N+1]; 
    int **arr = new int*[N+1];
    for(int i = 1;i<=N;i++) {
        arr[i] = new int[N+1];
        arr2[i] = new int[N+1];
        for(int j=1;j<=N;j++) {
            cin>>arr[i][j];
            arr2[i][j] = arr[i][j];
        }
    }
    // start,end, num_digit,sum_digit
    Rpref = vector<vector<int>>(N+1);
    Lpref = vector<vector<int>>(N+1);
    for(int i = 1;i<=N;i++) {
        int start = 1, num_digit = 0, sum_digit = 0;
        for(int j = 1;j<=N;j++) {
            if(sum_digit + arr[i][j] <= F) {
                sum_digit+=arr[i][j];
                num_digit+=1;
            } else {
                break;
            }
        }
        Lpref[i] = {start,num_digit,num_digit,sum_digit};
    }
    for(int i = 1;i<=N;i++) {
        int start = N, end = start, num_digit = 0, sum_digit = 0;
        for(int j = N;j>=1;j--) {
            if(sum_digit + arr[i][j] <= F) {
                sum_digit+=arr[i][j];
                num_digit+=1;
            } else {
                break;
            }
        }
        Rpref[i] = {start,N-num_digit+1,num_digit,sum_digit};
    }
    Upref = vector<vector<int>>(N+1);
    Dpref = vector<vector<int>>(N+1);
    for(int i = 1;i<=N;i++) {
        int start = 1, num_digit = 0, sum_digit = 0;
        for(int j = 1;j<=N;j++) {
            if(sum_digit + arr[j][i] <= F) {
                sum_digit+=arr[j][i];
                num_digit+=1;
            } else {
                break;
            }
        }
        Dpref[i] = {start,num_digit,num_digit,sum_digit};
    }
    for(int i = 1;i<=N;i++) {
        int start = N, num_digit = 0, sum_digit = 0;
        for(int j = N;j>=1;j--) {
            if(sum_digit + arr[j][i] <= F) {
                sum_digit+=arr[j][i];
                num_digit+=1;
            } else {
                break;
            }
        }
        Upref[i] = {start,N-num_digit+1,num_digit,sum_digit};
    }
    int k;
    cin>>k;
    int total = N*N;
    vector<pair<char,int>> res;
    while (!isDestroyed(arr,N)) {
        pair<char,int> a = bestAns(arr,N,F);
        applyMove(arr,N,F,a);
        res.push_back(a);
    }
    cout<<res.size()<<"\n";
    // if(res.size()>=k)
    //     assert(0);
    for(auto &i: res) {
        applyMoveTest(arr2,N,F,i);
    }
    // if(!isDestroyed(arr2,N) || res.size() >= k) {
    //     assert(0);
    // }
    for(auto &i: res) {
        if(i.first == 'U') {
            cout<<'D'<<" "<<i.second<<"\n";
        } else if(i.first == 'D') {
            cout<<'U'<<" "<<i.second<<"\n";
        } else 
            cout<<i.first<<" "<<i.second<<"\n";
    }
}

int main() {
    // fastIO;
    solve();
    return 0;
}


