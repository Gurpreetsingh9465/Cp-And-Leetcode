#include<bits/stdc++.h>
using namespace std;

vector<pair<char, char>> genStable(unordered_map<char, vector<char>> men, unordered_map<char, vector<char>> women) {
    unordered_set<char> occupied_men;
    unordered_set<char> occupied_women;
    vector<pair<char, char>> ans;

    for(auto &i: men) {
        vector<char> preference =  i.second;
        char men = i.first;
        for(auro &j: preference) {
            if(occupied_women.find(j) == occupied_women.end()) {
                ans.push_back({men, j});
                occupied_women.insert(j);
                occupied_men.insert(men);
                break;
            }
        }
    }
    return ans;
}
