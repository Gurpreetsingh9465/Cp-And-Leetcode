#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> a) {
    for(auto i: a) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int removeDuplicates(vector<int>& nums) {
    int l = nums.size();
    if(l == 0) {
        return 0;
    } else if (l == 1) {
        return 1;
    }
    int ans = 1;
    int prev = nums[0];
    for(int i = 1;i<nums.size();i++) {
        if(nums[i] == prev) {
            nums.erase(nums.begin()+i);
            i-=1;
            continue;
        }
        prev = nums[i];
        ans+=1;
    }
    return ans;
}

int main() {
    vector<int> V = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(V);
    printVector(V);
    return 0;
}