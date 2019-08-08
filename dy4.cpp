#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int arr[days.size()+1];
        arr[0] = 0;
        for(int j=0;j<days.size();j++) {
            int minimum = arr[j-1]+costs[0];
            for(int i = j ; i>=0 ; i--) {
                if(days[j] - days[i] >= 7 ) {
                    minimum = min(minimum,arr[days[i]]+costs[1]);
                }
            }
            for(int i = 0 ; i<=j ; i--) {
                if(days[j] - days[j-i] <= 30 ) {
                    minimum = min(minimum,arr[days[i]]+costs[2]);
                }
            }
            arr[j] = minimum;
        }
        return arr[days.size()];
    }
};

int main() {
    int days[] = {1,4,6,7,8,20};
    int costs[] = {2,7,15};
    vector<int> day(days,days+sizeof(days)/sizeof(int));
    vector<int> cost(costs,costs+sizeof(costs)/sizeof(int));
    Solution s;
    std::cout<<s.mincostTickets(day,cost)<<std::endl;
    return 0;
}