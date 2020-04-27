#include <bitset> 
#include<bits/stdc++.h>

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int win;
        for(int i:piles) {
            win+=i;
        }
        win = win/2;
        bool turn = true;
        int i = 0;
        int n = piles.size()-1;
        int alex,lee;
        alex=lee=0;
        while(i>n) {
            if(turn) {
                if(piles[i]<piles[n]) {
                    alex+=piles[i];
                    i+=1;
                } else {
                    alex+=piles[n];
                    n-=1;
                }
            } else {
                if(piles[i]>piles[n]) {
                    lee+=piles[i];
                    i+=1;
                } else {
                    lee+=piles[n];
                    n-=1;
                }
            }
            if(lee>=win) {
                return false;
            }
            turn = !turn;
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,
    27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,
    27,16,24,22,48,50,10,26,27,9,43,13,42,46,24
    };
    std::cout<<s.stoneGame(v)<<std::endl;
}

