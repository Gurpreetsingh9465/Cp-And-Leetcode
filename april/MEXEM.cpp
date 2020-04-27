#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int const MOD = 998244353;

int bs(vector<int> &arr, int target) {
    int high = arr.size()-1;
    int low = 0;
    int mid;
    while (low<=high) {
        if(arr[mid] == target) {
            return mid;
        }
        if(target<arr[mid]) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

void solve() {
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i = 0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int onePos = bs(arr,1);
    int ans = 1;
    if(onePos == -1) {
        for(int i = 0;i<N;i++) {
            ans = ans%MOD*2;
        }
        cout<<ans%MOD<<"\n";
        return;
    }
    unordered_map<int,int> m;
    int num = 0;
    int lastNum = 0;
    for(int i=onePos;i<N-1;i++) {
        if(arr[i] == arr[i+1] || arr[i]+1 == arr[i+1]) {
            m[arr[i]]++;
            num++;
            lastNum = i;
        } else {
            m[arr[i]]++;
            num++;
            lastNum = i;
            break;
        }
    }

    int pow2 = 1;
    for(int i = 0;i<N-num;i++) {
        pow2 = (pow2%MOD*2)%MOD;
    }

    ans = pow2;
    int pow2Int= 1;
    for(int i = 0;i<num-m[i];i++) {
        pow2Int = (pow2Int%MOD*2)%MOD;
    }
    for(int i=1;i<=lastNum;i++) {
        ans = (ans + (pow2*((i+1)*(pow2Int*m[i])%MOD)%MOD)%MOD)%MOD;
        pow2Int = pow2Int/2;
    }
    cout<<ans-1<<"\n";


}

int main() {
    fastIO;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}


