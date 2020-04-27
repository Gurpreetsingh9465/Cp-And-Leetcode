#include<bits/stdc++.h>
using namespace std;

bool getSubsets(vector<int> &nums,int start, int sum, vector<int> &res) {
    if(sum == 0) {
        return true;
    }
    if(sum<0)
        return false;
    if(start >= nums.size())
        return false;

    bool ans1 = getSubsets(nums,start+1,sum,res);
    bool ans2 = getSubsets(nums,start+1,sum-nums[start],res);
    if(ans2)
        res.push_back(nums[start]);
    return ans1||ans2;
}

int main() {
    vector<int> v = {1,2,3,5,8,0};
    vector<int> res;
    int n;
    cin>>n;
    getSubsets(v,0,n,res);
    cout<<n<<endl;
    for(int i :res) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}