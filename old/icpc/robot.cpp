#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_sum(int n, int* arr, int k) {
    int freq[50001];
    for(int i = 0; i < 50001; i++) freq[i] = 0;
    for(int i = 0; i < n; i++) freq[arr[i]] += 1;
    int nums = 0;
    int i = 50000;
    int j = 50000;
    while(i > k && j > k) {
        if(nums == 0) {
            if(freq[i] == 0) i--;
            else {
                freq[i]--;
                nums = 1;
            }
        }
        if(nums == 1) {
            if(freq[j] == 0) j--;
            else {
                freq[j]--;
                nums = 2;
            }
        }
        if(nums == 2) {
            freq[i - 1] += 1;
            freq[j - 1] += 1;
            nums = 0;
        }
    }
    if(nums == 1) {
        freq[i] += 1;
    } else if(nums == 2) {
        freq[i] += 1;
        freq[j] += 1;
    }
    ll sum_ = 0;
    for(int i = 1; i < 3; i++) {
        // cout << freq[i] << " ";
        sum_ += i*freq[i];
    }
    return sum_;
}

int main() {
    int test_n;
    cin >> test_n;
    for(int i = 0; i < test_n; i++) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int j = 0; j < n; j++) cin >> arr[j];
        cout << max_sum(n, arr, k) << endl;
    }
}
