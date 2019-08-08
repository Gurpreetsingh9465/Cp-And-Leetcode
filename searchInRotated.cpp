#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> nums, int st, int end,int target) {
    if(end>=st) {
        int mid = (end+st)/2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            return bs(nums, st, mid-1, target);
        }
        return bs(nums, mid+1, end, target);
    }
    return -1;
}

 int getPivot(vector<int> arr, int low, int high) {
    if(high < low) {
        return -1;
    }
    int mid = (high+low)/2;
    if(mid>low && arr[mid] < arr[mid-1]) {
        return mid;
    }
    if(mid<high && arr[mid] > arr[mid+1]) {
        return mid+1;
    }
    if(arr[mid] < arr[low])
        return getPivot(arr,low, mid-1);
    return getPivot(arr,mid+1,high);
}

int main() {
    cout<<getPivot({5,6,7,1,2,3,4},0,7);
    return 0;
}